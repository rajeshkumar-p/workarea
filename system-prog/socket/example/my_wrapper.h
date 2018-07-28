
#define SERV_PORT        9877
#define	MAXLINE			 4096
#define	LISTENQ			 1024	/* 2nd argument to listen() */

#define SA struct sockaddr

int Socket(int family, int type, int protocol)
{
	int n;
    if ( (n = socket(family, type, protocol)) < 0)
	        err_sys("socket error");
    return(n);
}

void Bind(int fd, const struct sockaddr *sa, socklen_t salen)
{
    if (bind(fd, sa, salen) < 0)
        err_sys("bind error");
}

void Listen(int fd, int backlog)
{
	char    *ptr;
    /*4can override 2nd argument with environment variable */
	if ( (ptr = getenv("LISTENQ")) != NULL)
	        backlog = atoi(ptr);

	if (listen(fd, backlog) < 0)
	       err_sys("listen error");
}

ssize_t                     /* Write "n" bytes to a descriptor. */
writen(int fd, const void *vptr, size_t n)
{
    size_t      nleft;
    ssize_t     nwritten;
    const char  *ptr;

    ptr = vptr;
    nleft = n;
    while (nleft > 0) {
        if ( (nwritten = write(fd, ptr, nleft)) <= 0) {
            if (nwritten < 0 && errno == EINTR)
                nwritten = 0;       /* and call write() again */
            else
                return(-1);         /* error */
        }

        nleft -= nwritten;
        ptr   += nwritten;
    }
    return(n);
}
/* end writen */

void
Writen(int fd, void *ptr, size_t nbytes)
{
    if (writen(fd, ptr, nbytes) != nbytes)
        err_sys("writen error");
}

void Close(int fd)
{
	if (close(fd) == -1)
		err_sys("close error");
}

int Accept(int fd, struct sockaddr *sa, socklen_t *salenptr)
{
	int     n;

again:
	if ( (n = accept(fd, sa, salenptr)) < 0) {
#ifdef  EPROTO
		if (errno == EPROTO || errno == ECONNABORTED)
#else
			if (errno == ECONNABORTED)
#endif
				goto again;
			else
				err_sys("accept error");
	}
	return(n);
}

pid_t Fork(void)
{
    pid_t   pid;

    if ( (pid = fork()) == -1)
        err_sys("fork error");
    return(pid);
}

void
Connect(int fd, const struct sockaddr *sa, socklen_t salen)
{
    if (connect(fd, sa, salen) < 0)
        err_sys("connect error");
}

const char *
Inet_ntop(int family, const void *addrptr, char *strptr, size_t len)
{
	const char	*ptr;

	if (strptr == NULL)		/* check for old code */
		err_quit("NULL 3rd argument to inet_ntop");
	if ( (ptr = inet_ntop(family, addrptr, strptr, len)) == NULL)
		err_sys("inet_ntop error");		/* sets errno */
	return(ptr);
}

void
Inet_pton(int family, const char *strptr, void *addrptr)
{
	int		n;

	if ( (n = inet_pton(family, strptr, addrptr)) < 0)
		err_sys("inet_pton error for %s", strptr);	/* errno set */
	else if (n == 0)
		err_quit("inet_pton error for %s", strptr);	/* errno not set */

	/* nothing to return */
}
