#include <stdio.h>
#include <stdlib.h>

int A( int n ){
    if( n<1) return 0;
    int a=n%10;
    n /= 10;
    return a*a+A(n);
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", A(n));
    return 0;
}
