#include <stdio.h>
#include <stdlib.h>
int N[100]={1, 2};
int A( int n){
    if( N[n-1] != 0 ) return N[n-1];
    int a = A(n-2);
    int b = A(n-1);
    N[n-1] = A(n-1)*A(n-2) % 100;
    return A(n-1)*A(n-2)%100;
}

int main()
{
    int a;
    scanf("%d", &a);
    printf("%d", A(a));
    return 0;
}
