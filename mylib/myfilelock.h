#include "apue.h"
#include <fcntl.h>

int
lock_reg(int fd, int cmd, int type, off_t offset, int whence, off_t len)
{
	struct flock lock;
	/* 	F_RDLCK, F_WRLCK, F_UNLCK */
	lock.l_type = type;
	/* 	byte offset, relative to l_whence */
	lock.l_start = offset;
	/* 	SEEK_SET, SEEK_CUR, SEEK_END */
	lock.l_whence = whence;
	/* 	#bytes (0 means to EOF) */
	lock.l_len = len;
	return(fcntl(fd, cmd, &lock));
}

pid_t
lock_test(int fd, int type,
		off_t offset, int whence, off_t len)
{
	struct flock lock;
	/* F_RDLCK or F_WRLCK */
	lock.l_type = type;
	/* byte offset, relative to l_whence */
	lock.l_start = offset;
	/* SEEK_SET, SEEK_CUR, SEEK_END */
	lock.l_whence = whence;
	/* #bytes (0 means to EOF) */
	lock.l_len = len;
	if (fcntl(fd, F_GETLK, &lock) < 0)
		err_sys("fcntl error");
	if (lock.l_type == F_UNLCK)
		return(0);
	/* false, region isn't locked by another proc */
	return(lock.l_pid); /* true, return pid of lock owner */
}

