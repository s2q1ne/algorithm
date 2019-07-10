#include <stdio.h>
#include <stdlib.h>

int A(int n){
    if( n==1) {
        printf("1! = 1\n");
        return 1;
    }
    printf("%d! = %d * %d!\n", n, n, n-1);
    return A(n-1) * n;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", A(n));
    return 0;
}
