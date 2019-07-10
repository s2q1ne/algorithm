#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, b, j, a;
    scanf("%d", &n);
    for( i=1; i<=n; i++){
        b = n*2 - i*2;
        //printf("%d", b);
        for( j=0; j<b; j++) printf(" ");
        a=1;
        for( j=0; j< n*2-b-1; j++){
            if( j%2 == 0) printf("%d", a++);
            else printf(" ");
        }printf("\n");
    }
    return 0;

}
