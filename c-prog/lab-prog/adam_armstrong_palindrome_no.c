#include <stdio.h>
#include <math.h>

#define bool int
#define TRUE  1
#define FALSE 0

/* procedure to find no of digits */
int no_of_digits(int no)
{
   int numofdigits = 0;

   while(no)
   {
      no = no / 10;
      numofdigits++;
   }	
   return numofdigits;	
}

/* procedure to find sum of digits in a no */
int sum_of_digits(int no)
{
   int sum = 0;

   while(no)
   {
      sum = sum + (no % 10);
      no = no / 10;
   }	
   return sum;	
}

/* procedure to reverse a number */
int reverse_num(int no)
{
   int temp = 0;

   while(no)
   {
      temp = (temp*10) + (no%10);
      no = no / 10; 	
   }	
   return temp;	
}

/*
Adam Number :
If a number when reversed , the square of the number and the square of the
reversed number should be numbers which are reverse of each other, then 
the no is a adam no

example : 12 and 21, 12 = 144 and 21 = 441
other examples : 0,1,2,3,11,12,13,21,22,31,101,102,103,111,112,113 etc
*/
bool isAdam(int no)
{
   int rev_no;

   rev_no = reverse_num(no);

   if((no * no) == reverse_num(rev_no * rev_no))
      return TRUE; 
   return FALSE;
}

/*

Armstrong Number :  
An Armstrong Number is an n-digit number which is equal to the
nth power sum of its individual digits.

example : 153 = (1*1*1) + (5*5*5) + (3*3*3) = 153
other examples : 0,1,2,3,4,5,6,7,8,9,153,370,371,407,1634,8208, 9474
 */
bool isArmstrong(int no)
{
   int digits = no_of_digits(no);
   int temp = no;
   int sum = 0;

   while(no)
   {
      //sum = sum + (int)pow((double)(no%10), (double)digits);
      sum = sum + pow((no%10), digits);
      no = no / 10;
   }		
   if(sum == temp)
      return TRUE;

   return FALSE;
}

/*
Palindrome number :
A palindrome number is defined as a number which remains the number when its
digits are reversed
 */ 
bool isPalindrome(int no)
{
   int rev = reverse_num(no);

   if(rev == no)
      return TRUE;
   return FALSE;
}	

int main()
{
   int i;

   int no = 123;

   printf("\n No of digits in  %d is %d", no, no_of_digits(no));
   printf("\n Sum of digits in %d is %d", no, sum_of_digits(no));
   printf("\n Reverse of       %d is %d", no, reverse_num(no));
   printf("\n");
   
   // print all adam no, armstrong no and palindrome no
   for(i=0; i<500; i++)
   {
      if(isAdam(i)) printf("\n %d is adam no      ", i);
      if(isArmstrong(i)) printf("\n %d is armstrong no ", i);
      if(isPalindrome(i)) printf("\n %d is palindrome no ", i);
   }

   printf("\n\n");	
   return 0;
}	

