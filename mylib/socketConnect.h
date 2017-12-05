#include "apue.h"
#include <sys/socket.h>

#define MAXSLEEP 128

int
connect_retry(int sockfd, const struct sockaddr *addr, socklen_t alen)
{
	int nsec;
	/*
	 * Try to connect with exponential backoff.
	 */
	for (nsec = 1; nsec <= MAXSLEEP; nsec <<= 1) {
		if (connect(sockfd, addr, alen) == 0) {
			/*
			 * Connection accepted.
			 */
			return(0);
		}
		/*
		 * Delay before trying again.
		 */
		if (nsec <= MAXSLEEP/2)
			sleep(nsec);
	}
	return(-1);
}


int
initserver(int type, const struct sockaddr *addr, socklen_t alen,
		int qlen)
{
	int fd;
	int err = 0;
	if ((fd = socket(addr->sa_family, type, 0)) < 0)
		return(-1);
	if (bind(fd, addr, alen) < 0) {
		err = errno;
		goto errout;
	}
	if (type == SOCK_STREAM || type == SOCK_SEQPACKET) {
		if (listen(fd, qlen) < 0) {
			err = errno;
			goto errout;
		}
	}
	return(fd);

errout:
	close(fd);
	errno = err;
	return(-1);
}

