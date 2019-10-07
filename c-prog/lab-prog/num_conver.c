/*
Program to demontrate while loop usage
- binary to decimal
- decimal to binary
*/

#include <stdio.h>

int binary_to_decimal(int num)
{
    int rem, decimal_val = 0, base = 1;

    while(num > 0)
    {
        rem = num % 10;
        decimal_val = decimal_val + (rem * base);
        num = num / 10;
        base = base * 2;            
    }

    return decimal_val;
}

int decimal_to_binary(int num)
{
    int rem, binary_val = 0, base = 1;

    while(num > 0)
    {
        rem = num % 2;
        binary_val = binary_val + (rem * base);
        num = num / 2;
        base = base * 10;            
    }

    return binary_val;
}

int main()
{
    int num;

    printf("\n Enter a binary number \n");
    scanf("%d", &num);    

    printf("\n Binary number is = %d\n", num);
    printf("\n Its decimal equivalent is = %d\n", binary_to_decimal(num));

    printf("\n Enter a decimal number \n");
    scanf("%d", &num);    
    printf("\n Decimal number is = %d\n", num);
    printf("\n Its binary equivalent is = %d\n", decimal_to_binary(num));

    return 0;
}
