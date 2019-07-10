#include <stdio.h>

int main()
{
    int a=0, j=1, tmp, n, i;
    scanf("%d", &n);
    for( i=0; i<n; i++ ){
        printf("%d ", a);
        tmp=j+a;
        a=j;
        j=tmp;
    }
    return 0;
}
