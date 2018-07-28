/* gethostn.c:
 *
 * Example of gethostname(2):
 */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/utsname.h>

int
main(int argc,char **argv) {
	int z;
	char buf[32];

	struct utsname u_name;
	z = uname(&u_name);
	if ( z == -1 ) {
		fprintf(stderr, "%s: uname(2)\n",
				strerror(errno));
		exit(1);
	}
	printf("sysname[] = '%s';\n",
			u_name.sysname);
	printf("nodename[] = '%s';\n",
			u_name.nodename);
	printf("release[] = '%s';\n",
			u_name.release);
	printf("version[] = '%s';\n",
			u_name.version);
	printf("machine[] = '%s';\n",
			u_name.machine);
	//printf("domainname[] = '%s';\n",
	//		u_name.domainname);

	z = gethostname(buf,sizeof buf);
	if ( z == -1 ) {
		fprintf(stderr, "%s: gethostname(2)\n",
				strerror(errno));
		exit(1);
	}
	printf("host name = '%s'\n",buf);
	
	/*
	domainname This returns the NIS/YP domain name for the host.
	NOTE 
	NIS/YP (Network Information Service) is beyond the scope of this book. NIS
	provides centralized information management for a group of hosts in a
	network. It permits a centralized management of users, groups, and passwords, 
	for example.
	*/


	z = getdomainname(buf,sizeof buf);
	if ( z == -1 ) {
		fprintf(stderr,"%s: getdomainname(2)\n",
				strerror(errno));
		exit(1);
	}
	printf("domain name = '%s'\n",buf);
	return 0;
}

