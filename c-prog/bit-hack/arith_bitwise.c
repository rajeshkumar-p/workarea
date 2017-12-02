#include <stdio.h>

/* Using Half-adder logic */
int my_add(int x, int y) 
{
	int carry;
	do {
		/* carry now contains common set bit of x and y */
		carry = x & y;
		/* sum of bits of x and y */
		x = x ^ y;
		/* carry is shifted by 1, so that adding it gives the required */
		y = carry << 1;
	} while (y);
	return x;
}

int my_sub(int x, int y) 
{
	int borrow;
	do {
		/* carry now contains common set bit of x and y */
		borrow = (~x) & y;
		/* subraction of bits of x and y */
		x = x ^ y;
		/* borrow is shifted by 1, so that subraction gives the required */
		y = borrow << 1;
	} while (y);
	return x;
}

int my_mult(int num1, int num2)
{
	switch(num2)
	{
		case 1: return num1;
		case 2: return (num1 << 1);
		case 3: return ((num1 << 1) + (num1));
		case 4: return (num1 << 2);
		case 5: return ((num1 << 2) + (num1));
		case 6: return ((num1 << 2) + (num1 << 1));
		case 7: return ((num1 << 2) + (num1 << 1)) + num1;
		case 8: return (num1 << 3);
		case 9: return ((num1 << 3) + (num1));
		case 10: return ((num1 << 3) + (num1 << 2));
		default: return 0;	
	}		
}

int my_div(int num1, int num2)
{
	switch(num2)
	{
		case 1:
			return num1;
		case 2:
			return (num1 >> 1);
		case 3:
			return ((num1 >> 1) - (num1));
		case 4:
			return (num1 >> 2);
		case 5:
			return ((num1 >> 2) - (num1));
		case 6:
			return ((num1 >> 2) - (num1 >> 1));
		case 7:
			return ((num1 >> 2) - (num1 >> 1)) - num1;
		case 8:
			return (num1 >> 3);
		case 9:
			return ((num1 >> 3) - (num1));
		case 10:
			return ((num1 >> 3) - (num1 >> 2));
		default:
			return 0;	
	}	
}	

int main()
{
	printf("\n  = %d",my_add(10,1));
	printf("\n  = %d",my_add(19,2));
	printf("\n  = %d",my_add(28,3));
	printf("\n  = %d",my_add(37,4));
	printf("\n  = %d",my_add(46,5));
	printf("\n  = %d",my_add(55,6));
	printf("\n  = %d",my_add(64,7));
	printf("\n  = %d",my_add(73,8));
	printf("\n  = %d",my_add(82,9));
	printf("\n  = %d",my_add(91,10));
	printf("\n");

	printf("\n  = %d",my_sub(10,1));
	printf("\n  = %d",my_sub(21,2));
	printf("\n  = %d",my_sub(32,3));
	printf("\n  = %d",my_sub(43,4));
	printf("\n  = %d",my_sub(54,5));
	printf("\n  = %d",my_sub(6,65));
	printf("\n  = %d",my_sub(7,76));
	printf("\n  = %d",my_sub(8,87));
	printf("\n  = %d",my_sub(9,98));
	printf("\n  = %d",my_sub(10,109));
	printf("\n");


	printf("\n  = %d",my_mult(10,1));
	printf("\n  = %d",my_mult(2,2));
	printf("\n  = %d",my_mult(3,3));
	printf("\n  = %d",my_mult(4,4));
	printf("\n  = %d",my_mult(5,5));
	printf("\n  = %d",my_mult(2,6));
	printf("\n  = %d",my_mult(3,7));
	printf("\n  = %d",my_mult(4,8));
	printf("\n  = %d",my_mult(5,9));
	printf("\n  = %d",my_mult(1,10));
	printf("\n");

	printf("\n  = %d",my_div(10,1));
	printf("\n  = %d",my_div(10,2));
	printf("\n  = %d",my_div(30,3));
	printf("\n  = %d",my_div(20,4));
	printf("\n  = %d",my_div(50,5));
	printf("\n  = %d",my_div(30,6));
	printf("\n  = %d",my_div(70,7));
	printf("\n  = %d",my_div(40,8));
	printf("\n  = %d",my_div(90,9));
	printf("\n  = %d",my_div(50,10));
	printf("\n");

	printf("\n\n Good Bye \n\n");
}
