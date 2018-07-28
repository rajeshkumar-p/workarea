#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <string.h>
//#include <>

int main()
{
int ret, size;
int sockfd[2];
char *buf;

*buf = "Hello World \0";
//#printf("%s", buf);

return 0;
}
