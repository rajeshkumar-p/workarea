#include<stdio.h>
#include<unistd.h>
#include<string.h>

int main() 
{
   int pipefds[2];  // 0 - read 1 - write
   int ret;

   char writemessages[3][20]= { "Hi\0", 
                                "Welcome to CSC\0", 
                                "Hope! You are fine\0"};
   char readmessage[60];

   ret = pipe(pipefds);
   if (ret == -1) {
      printf("Unable to create pipe\n");
      return -1;
   }
   
   printf("Writing to pipe - Message 1 is %s\n", writemessages[0]);
   write(pipefds[1], writemessages[0], strlen(writemessages[0]));
   read(pipefds[0], readmessage, strlen(writemessages[0]));
   printf("Reading from pipe – Message 1 is %s\n", readmessage);

   printf("Writing to pipe - Message 2 is %s\n", writemessages[1]);
   write(pipefds[1], writemessages[1], strlen(writemessages[1]));
   read(pipefds[0], readmessage, strlen(writemessages[1]));
   printf("Reading from pipe – Message 2 is %s\n", readmessage);

#if 1
   printf("Writing to pipe - Message 1 is %s Length %d \n", writemessages[0],
strlen(writemessages[0]));
   printf("Writing to pipe - Message 2 is %s Length %d \n", writemessages[1],
strlen(writemessages[1]));
   printf("Writing to pipe - Message 3 is %s Length %d \n", writemessages[2],
strlen(writemessages[2]));
   write(pipefds[1], writemessages[0], strlen(writemessages[0]));
   write(pipefds[1], writemessages[1], strlen(writemessages[1]));
   write(pipefds[1], writemessages[2], strlen(writemessages[2]));

   read(pipefds[0], readmessage, strlen(writemessages[0]));
   printf("Reading from pipe – Message is %s\n", readmessage);
   read(pipefds[0], readmessage, strlen(writemessages[1]));
   printf("Reading from pipe – Message is %s\n", readmessage);
   read(pipefds[0], readmessage, strlen(writemessages[2]));
   printf("Reading from pipe – Message is %s\n", readmessage);
#endif
  
   return 0;
}
