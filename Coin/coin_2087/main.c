#include <stdio.h>

int pow( int n1, int n2){
    if( n2>0 )
        return pow(n1 * 2, n2-1);
    if( n2 == 0)
        return n1;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", pow(1,n));
    return 0;
}
