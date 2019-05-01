/* 
Endianess : 
 Little Endian and Big Endian are two ways of storing multibyte data
 Little Endian : In a multibyte data, last byte of data stored first
 Big Endian    : In a multibyte data, first byte stored first 

https://www.geeksforgeeks.org/little-and-big-endian-mystery/
*/
	    
#include <stdio.h>

void endianess()
{
	unsigned int i = 1;
  unsigned int j = 0x12345678;
	char *c1 = (char*)&i;
	char *c2 = (char*)&j;

	if (*c1)   
		printf("\n Little endian");
	else
		printf("\n Big endian");

	if (*c2 == 0x78)   
		printf("\n Little endian");
	else
		printf("\n Big endian");

	return ;
}

unsigned int conv_little_to_big(unsigned int num)
{
unsigned int b0,b1,b2,b3;

b0 = (num & 0x000000ff) << 24u;
b1 = (num & 0x0000ff00) << 8u;
b2 = (num & 0x00ff0000) >> 8u;
b3 = (num & 0xff000000) >> 24u;

return (b0|b1|b2|b3);
}

/* function to show memory representation */ 
void show_mem_rep(char *ch, unsigned int size)
{
  unsigned int i=0;
  
  printf("\n memory representation : ");
  for ( i=0; i<size; i++)
      printf("%.2x ", ch[i]); 
}

int main ()
{
  unsigned int no = 0x12345678;

  printf("\n size of no : %d ", sizeof(no));

  show_mem_rep((char *) &no, sizeof(no));
 
	endianess();

  printf("\n no is : %x after endianess convert is : %x \n",
                     no, conv_little_to_big(no));
	return 0;
}
