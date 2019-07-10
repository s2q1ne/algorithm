
#include <stdio.h>
#include <stdlib.h>

int abs( int n ){
    return n>0?n:-n;
}

int main()
{
    int n, i, j, num=0;
    scanf("%d", &n);
    for( i = 0; i<n; i++){
        num = 1;
        for( j=i; j<n-1; j++) printf("  ");
        for( j=0; j<=i; j++) printf("%d ", num++);
        printf("\n");
    }

    return 0;
}
