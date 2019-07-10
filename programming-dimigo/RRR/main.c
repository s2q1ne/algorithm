#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A, B, i, j;
    scanf("%d", &A);
    for( i=0; i<A*2-1; i++ ){
        B = (i>=A)?A*2-i-2: i ;
        // 0 1 2 1 0
        // 5-0 5-2 5-4 5-2 5-0
        // 5 3 1 3 5
        //printf("%d", B);
        for( j=0;j<B; j++ ){
            printf(" ");
        }for( j=0;j<A*2-1-B*2; j++ ){
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
