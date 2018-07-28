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

int passiveTCP(const char *service, int qlen)
{
	return passivesock(service, "tcp", qlen);
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

void TCPdaytimed(int fd)
{
	char *pts;
	time_t now;
	char *ctime();

	time(&now);
	pts = ctime(&now);
	write(fd, pts, strlen(pts));

	return;
}


int main(int argc, char *argv[ ])
{
	char   *service = "echo";
	struct sockaddr_in fsin;
	int    msock;
	fd_set rfds;
	fd_set afds;
	int    alen;
	int    fd, nfds;

	msock = passiveTCP(service, 5);
	nfds = getdtablesize();

	FD_ZERO(&afds);
	FD_SET(msock, &afds);

	while (1) {
		memcpy(&rfds, &afds, sizeof(rfds));

		if(select(nfds, &rfds, (fd_set *)0, (fd_set *)0, (struct timeval *)0) < 0)
			err_exit("select: %s\n", strerror(errno));

		if(FD_ISSET(msock, &rfds))
		{
			int ssock;
			alen = sizeof(fsin);
			ssock = accept(msock, (struct sockaddr *)&fsin, &alen);
			if(ssock < 0)
				err_exit("accept: %s\n", strerror(errno));

			FD_SET(ssock, &afds);
		}

		for(fd=0; fd < nfds; ++fd)
			if(fd != msock && FD_ISSET(fd, &rfds))
				if(echo(fd) == 0)
				{
					(void) close(fd);
					FD_CLR(fd, &afds);
				}
	}
}

int echo(int fd)
{
	char buf[BUFSIZ];
	int  cc;

	cc = read(fd, buf, sizeof buf);
	if(cc < 0)
		err_exit("echo read: %s\n", strerror(errno));

	if(cc && write(fd, buf, cc) < 0)
		err_exit("echo write: %s\n", strerror(errno));

	return cc;
}


