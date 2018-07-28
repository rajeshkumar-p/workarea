#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>

#if 0
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

// FIXME print error code and error no on failure

int main()
{
int sockfd;
int ret;
struct sockaddr my_addr, dest_addr;

// 1. create socket
sockfd = socket(AF_INET, SOCK_DGRAM, 0);
if(sd == -1) 
{
	printf("\n socket creation failure \n");
	return sd;
}
printf("\n socket descriptor created - descriptor id : %d", (int) sd);

// 2. bind the socket
my_addr.sin_family = AF_INET;
my_addr.sin_port = htons(CLIENT_PORT);
//my_addr.sin_addr.s_addr = inet_addr(CLIENT_IP);
my_addr.sin_addr.s_addr = htonl(INADDR_ANY);
memset(&(my_addr.sin_zero), ’\0’, 8); // zero the rest of the struct
ret = bind(sockfd, (struct sockaddr *)&my_addr, sizeof(struct sockaddr));
if(ret == -1)
{
	printf("\n binding failure \n");
	return ret;
}

// 3. connect to the remote socket
dest_addr.sin_family = AF_INET;
dest_addr.sin_port = htons(DEST_PORT);
// short, network byte order
dest_addr.sin_addr.s_addr = inet_addr(DEST_IP);
memset(&(dest_addr.sin_zero), ’\0’, 8); // zero the rest of the struct
// don’t forget to error check the connect()!
connect(sockfd, (struct sockaddr *)&dest_addr, sizeof(struct sockaddr));
 

return 0;
}
