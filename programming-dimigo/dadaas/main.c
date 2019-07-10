#include <stdio.h>
#include <stdlib.h>

long long s( long long n ){
    if( n >= 2)
        printf("%d! = %d * %d!\n", n, n, n-1);
    else if( n==1)
        printf("%d! = %d", n, n);
    else return 1;
    return s(n-1) * n;
}

int main()
{
    int n;
    scanf("%d" , &n);
    printf("\n%lld", s(n) );
    return 0;
}
