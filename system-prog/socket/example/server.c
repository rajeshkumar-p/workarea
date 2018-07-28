#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

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

#define BACK_LOG    20
#define MAXDATASIZE 1000


// FIXME print error code and error no on failure

int main()
{
	int sockfd, clientfd;
	int ret;
	struct sockaddr_in my_addr, client_addr;
	int sin_size;
	int num_bytes;
	char buf[MAXDATASIZE];

	// 1. create socket
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd == -1) 
	{
		printf("\n socket creation failure \n");
		perror("socket");
		return sockfd;
	}
	printf("\n socket descriptor created - descriptor id : %d", (int) sockfd);

	// 2. bind the socket
	my_addr.sin_family = AF_INET;
	my_addr.sin_port = htons(SERVER_PORT);
	my_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
	//my_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	memset(&(my_addr.sin_zero), '\0', 8); // zero the rest of the struct
	ret = bind(sockfd, (struct sockaddr *)&my_addr, sizeof(struct sockaddr));
	if(ret == -1)
	{
		/*
		if the address is not your ip address
		bind: Cannot assign requested address; 
		 */
		printf("\n binding failure \n");
		perror("bind");
		return ret;
	}

	// 3. start listening on the port 
	ret = listen(sockfd, BACK_LOG);
	if(ret == -1)
	{
		printf("\n listen failure \n");
		perror("listen");
		return ret;
	}


	client_addr.sin_family = AF_INET;
	client_addr.sin_port = htons(CLIENT_PORT);
	client_addr.sin_addr.s_addr = inet_addr(CLIENT_IP);
	memset(&(client_addr.sin_zero), '\0', 8); // zero the rest of the struct

	// 4. accept connections from specific client port 
	sin_size = sizeof(struct sockaddr_in);
	while(1)
	{

		//clientfd = accept(sockfd, (struct sockaddr *)&client_addr, sizeof(struct sockaddr_in));
		clientfd = accept(sockfd, (struct sockaddr *)&client_addr, &sin_size);
		if(clientfd == -1)
		{
			perror("accept failure");
			continue;
		}

		printf("server: got connection from %s\n", inet_ntoa(client_addr.sin_addr));

		if (!fork()) 
		{ // this is the child process
			if((num_bytes = recv(clientfd, buf, MAXDATASIZE-1, 0)) == -1)
			{
				perror("recv failure");
				exit(0);
			}
			printf("\n Received Message : %s", buf);

			close(sockfd); // child doesn’t need the listener
			if (send(clientfd, "Hello, world!\n", 14, 0) == -1)
				perror("send");
			close(clientfd);
			exit(0);
		}
		close(clientfd); // parent doesn’t need this

	} // end server loop

	return 0;
}
