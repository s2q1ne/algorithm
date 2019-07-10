#include <stdio.h>
#include <stdlib.h>

int A(int n){
    if( n < 1 ) return 0;
    A(n-2);
    printf("%d ", n);
    return 0;
}

int main()
{
    int n;
    scanf("%d", &n);
    A(n);
    return 0;
}
