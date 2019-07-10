#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A[100][100]={0,}, i, j, c=0, ka, C='A';
    scanf("%d", &ka);
    for( i=ka-1; i<ka*2-1; i++ ){
        for( j=0; j+i<ka*2-1; j++) {
            A[i-ka+j+1][ka-j-1]=C++;
            if( C > 'Z') C = C+ - 'Z'+'A'-1;
        }
    }
    for( i=0; i<ka; i++){
        for( j=0; j<ka; j++ ){
            if( A[i][j]!=0)
                printf("%c ", A[i][j]);
            else
                printf("  ");
        }
        printf("\n");
    }
    return 0;
}
