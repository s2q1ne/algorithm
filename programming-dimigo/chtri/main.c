#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A[500][500]={0,}, k, x, y=1, C=1, a=-1, b=1, i, j;
    scanf("%d", &k);
    x=k;
    for( i=0; i<=k*2; i++){
        for( j=0; j<=k*2; j++){
            A[i][j] = -1;
        }
    }
    for( i=1; i<k*2; i++){
        for( j=1; j<k*2; j++){
            A[i][j] = 0;
        }
    }

    for( i=1; i<=k; i++){
        for( j=1; j<=k-i; j++){
            A[i][j] = -1;
            A[k*2-i][j] = -1;
            A[i][k*2-j] = -1;
            A[k*2-i][k*2-j] = -1;
        }
    }

    while( C <= 2*k*(k-1) ){
        A[y][x] = C;
        if( (a == -1 && b == 1  && A[y+b][x+a]!=0) ) {
            // a was -1, b was 1
            a=1;
        }
        else if( (a == 1 && b == 1 && A[y+b][x+a]!=0 ) ){
            // a was 1 , b was 1
            b=-1;
        }
        else if( (a == 1 && b == -1 && A[y+b][x+a]!=0 ) ){
            // a was 1 , b was -1
            a = -1;
        }
        else if( (a == -1 && b == -1 && A[y+b][x+a]!=0 ) ){
            // a was -1 , b was -1
            y--;
            b=1;
        }
        x+=a;
        y+=b;
        C++;
    }
    A[k][k] = C;
    for( i=1; i<k*2; i++){
        for( j=1; j<k*2; j++){
            if( A[i][j] != -1)
            printf("%c", (A[i][j]-1)%26+'A');
            else printf(" ");
            printf(" ");
        }printf("\n");
    }
    return 0;
}
