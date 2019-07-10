#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[10][10]={0,};
    int n, i, j;
    scanf("%d", &n);
    for( i=n-1; i>=0; i--){
        a[i][0] = 1;
        a[i][n-i-1] = 1;

    }
    for( i=n-2; i>=0; i--){
        for( j=1; j<n-i-1; j++){
            a[i][j] = a[i+1][j] + a[i+1][j-1];
        }
    }

    for( i=0; i<n; i++){
        for( j=0; j<n; j++){
            if( a[i][j] == 0 )printf(" ");
            else printf("%d ", a[i][j]);
        }printf("\n");
    }
    return 0;
}
