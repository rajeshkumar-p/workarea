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

unsigned short portbase = 0;

#define SERVER_SOCK 5000

int passiveUDP(const char *service)
{
	return passivesock(service, "udp", 0);
}

int passivesock(const char *service, const char *transport, int qlen)
{
	struct sockaddr_in sin;
	int     s, type;
	int 	protocol;

	memset(&sin, 0, sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_addr.s_addr = INADDR_ANY;
	sin.sin_port = SERVER_SOCK;

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

	/* Bind the socket */
	if(bind(s, (struct sockaddr *)&sin, sizeof(sin)) < 0)
		err_exit("can't bind to %s port: %s\n", service, strerror(errno));

	if(type == SOCK_STREAM && listen(s, qlen) < 0)
		err_exit("can't listen on %s port: %s\n", service, strerror(errno));

	return s;
}


/* main() - Iterative UDP server for TIME service */

int main(int argc, char *argv[ ])
{
	struct sockaddr_in fsin;
	char *service = "time";
	char buf[1];
	int sock;
	time_t now;
	int alen;

	sock = passiveUDP(service);

	while (1)
	{
		alen = sizeof(fsin);
		if(recvfrom(sock, buf, sizeof(buf), 0, (struct sockaddr *)&fsin, &alen) < 0)
			err_exit("recvfrom: %s\n", strerror(errno));
		time(&now);
		now = htonl((u_long)now);
		sendto(sock, (char *)&now, sizeof(now), 0, (struct sockaddr *)&fsin, sizeof(fsin));
	}
}


