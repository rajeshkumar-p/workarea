#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>

#define MSG  "What time is it?\n"

#define SERVER_PORT 5000

int connectUDP(const char *host, const char *service)
{ 
	return connectsock(host, service, "udp"); 
}

int connectsock(const char *host, const char *service, const char *transport)
{
	struct hostent      *phe;   /* pointer to host information entry    */
	struct servent      *pse;   /* pointer to service information entry */
	struct protoent     *ppe;   /* pointer to protocol information entry*/
	struct sockaddr_in sin;     /* an Internet endpoint address         */
	int s, type;                /* socket descriptor and socket type    */
	int protocol;

	memset(&sin, 0, sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_port = SERVER_PORT;
	sin.sin_addr.s_addr = INADDR_ANY;

	/* Use protocol to choose a socket type */
	if(strcmp(transport, "udp") == 0)
	{	
		type = SOCK_DGRAM;
		protocol = IPPROTO_UDP;
	}	
	else
	{	
		type = SOCK_STREAM;
		protocol = IPPROTO_UDP;
	}	

	/* Allocate a socket */
	s = socket(PF_INET, type, protocol);
	if(s < 0)
		err_exit("can't create socket: %s\n", strerror(errno));

	/* Connect the socket */
	if(connect(s, (struct sockaddr *)&sin, sizeof(sin)) < 0)
		err_exit("can't connect to %s.%s: %s\n", host, service, strerror(errno));

	return s;
}

int main(int argc, char *argv[ ])
{
	char   *host = "localhost"; /* host to use if none supplied */
	char   *service = "time";   /* default service name   */

	time_t now;                 /* 32-bit integer to hold time  */ 
	int    s, n;                /* socket descriptor, read count */

	switch (argc) {
		case 1:
			host = "localhost";
			break;
		case 3:
			service = argv[2];
			/* FALL THROUGH */
		case 2:
			host = argv[1];
			break;
		default:
			fprintf(stderr, "usage: UDPtime [host [port]]\n");
			exit(1);
	}

	s = connectUDP(host, service);
	(void) write(s, MSG, strlen(MSG));

	/* Read the time */
	n = read(s, (char *)&now, sizeof(now));

	if(n < 0)
		err_exit("read failed: %s\n", strerror(errno));

	/* put in host byte order */
	now = ntohl((u_long)now);
	printf("%s", ctime(&now));

	exit(0);
}


