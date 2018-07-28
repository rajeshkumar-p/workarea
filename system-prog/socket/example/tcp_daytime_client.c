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

#define LINELEN 128
#define SERVER_PORT 5000

int connectTCP(const char *host, const char *service)
{ return connectsock(host, service, "tcp"); }

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
		protocol = IPPROTO_TCP;
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

void TCPdaytime(const char *host, const char *service)
{
	/* buffer for one line of text */
	char buf[LINELEN+1];

	/* socket, read count */
	int s, n;

	s = connectTCP(host, service);

	while((n = read(s, buf, LINELEN)) > 0)
	{
		/* ensure null-terminated */
		buf[n] = '\0';
		(void) fputs(buf, stdout);
	}
}

int main(int argc, char *argv[ ])
{
	/* host to use if none supplied */
	char *host = "localhost";
	/* default service port */
	char *service = "daytime";
	int i;

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
			fprintf(stderr, "usage: TCPdaytime [host [port]]\n");

			exit(1);
	}

	for(i=0; i<100; i++)
	TCPdaytime(host, service);
	exit(0);
}


