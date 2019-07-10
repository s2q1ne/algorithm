#include <stdio.h>

int len(char A[500]) {
   int i = 0;
   while (A[i++] != '\0');
   return i - 1;
}

int check(int a, int b)
{
   char A[500], B[500];
   int C[10]={0,};
   int i, j;

   sprintf(A, "%d", a);
   sprintf(B, "%d", b);
   for (i = 0; i < len(A); i++) {
      C[A[i]-'0'] ++;
   }
   for (i = 0; i < len(B); i++) {
      C[B[i]-'0'] ++;
   }

   for (i = 1; i < 10; i++) {
      if (C[i] >= 2) return 0;
   }
   return 1;
}

int main()
{
   int i, j, cnt=0;

   for (i = 12; i <= 98; i++)
   {
      for (j = 123; j <= 987; j++)
      {
         if (check(i, j)==1)
         {
            cnt++;
            printf("%d %d\n", i, j);
         }
         else
            continue;
      }
   }
   printf("%d", cnt);
   return 0;
}
