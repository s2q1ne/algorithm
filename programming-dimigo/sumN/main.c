#include <stdio.h>
#include <stdlib.h>

int N[100];

int A(int n){
    if( n==2) return 2;
    if( n==1 ) return 1;
    return A(N[n-1]) * A(N[n-2]) % 100;
    //N[ n ] = N[ n-1 ] * N[ n-2 ] % 100
}

int main()
{
    int Q, i;
    scanf("%d", &Q);
    N[1] = 2;
    N[0] = 1;
    printf("%d", A(Q));
    return 0;
}
