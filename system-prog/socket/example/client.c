#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>

#include <errno.h>

#if 1 
#define LOCAL_HOST  "127.0.0.1"
#define SERVER_IP   LOCAL_HOST
#define CLIENT_IP   LOCAL_HOST
#else
#define LOCAL_HOST  "INADDR_ANY"
#define SERVER_IP   LOCAL_HOST
#define CLIENT_IP   LOCAL_HOST
#endif
#define SERVER_PORT 3001
#define CLIENT_PORT 3000

int main()
{
	int sockfd;
	int ret;
	char *msg = "Hello Buddy";
	struct sockaddr_in my_addr, dest_addr;
	int len, bytes_sent;

	// 1. create socket
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd == -1) 
	{
		perror("socket creation failure");
		return sockfd;
	}
	printf("\n socket descriptor created - descriptor id : %d \n", (int) sockfd);

	// 2. bind the socket
	my_addr.sin_family = AF_INET;
	my_addr.sin_port = htons(CLIENT_PORT);
	my_addr.sin_addr.s_addr = inet_addr(CLIENT_IP);
	//my_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	memset(&(my_addr.sin_zero), '\0', 8); // zero the rest of the struct
	ret = bind(sockfd, (struct sockaddr *)&my_addr, sizeof(struct sockaddr));
	if(ret == -1)
	{
		perror("binding failure");
		return ret;
	}

	// 3. connect to the remote socket
	dest_addr.sin_family = AF_INET;
	dest_addr.sin_port = htons(SERVER_PORT);
	dest_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
	memset(&(dest_addr.sin_zero), '\0', 8); // zero the rest of the struct
	ret = connect(sockfd, (struct sockaddr *)&dest_addr, sizeof(struct sockaddr));
	if(ret == -1)
	{
		perror("connection to remote failure");
		return ret;
	}

	// 4. say hello to the remote machine
	len = strlen(msg);
	bytes_sent = send(sockfd, msg, len, 0);


	// 5. close the socket properly
	close(sockfd);

#if 0 
	shutdown(sockfd, 0); // 0 - further receives are disallowed
	shutdown(sockfd, 1); // 1 - further sends are disallowed
	shutdown(sockfd, 2); // 2 - further receives and sends are disallowed same as close
#endif

	return 0;
}
