/*
 * C program to read two matrices A(MxN) and B(MxN) and perform addition
 * OR subtraction of A and B. Also, find the trace of the resultant
 * matrix. Display the given matrices, their sum or differences and
 * the trace.
 */

#include <stdio.h>

void main()
{
   int array1[10][10], array2[10][10];

   int i, j, m, n;
   int trace = 0;

   printf("Enter the order of the matrix array1 and array2 \n");
   scanf("%d %d", &m, &n);

   printf("Enter the elements of matrix array1 \n");
   for (i = 0; i < m; i++) 
   {
      for (j = 0; j < n; j++)
      {
         scanf("%d", &array1[i][j]);
      }
   }

   printf("MATRIX array is \n");
   for (i = 0; i < m; i++) 
   {
      for (j = 0; j < n; j++) 
      {
         printf("%3d", array1[i][j]);
      }
      printf("\n");
   }

   /* transpose of a matrix is formed by interchanging the rows and
      columns of a matrix */
   printf("Transpose of matrix is \n");
   for (j = 0; j < n; ++j)
   {
      for (i = 0; i < m; ++i)
      {
         printf(" %d", array1[i][j]);
      }
      printf("\n");
   }

   printf("Trace of matrix is \n");
   for (i = 0; i < m; i++)
   {
      for (j = 0; j < n; j++) 
      {
         if (i == j)
         {
            trace = trace + array1[i][j];
         }
      }
   }

   printf("Trace of the given matrix is = %d\n", trace);
}
