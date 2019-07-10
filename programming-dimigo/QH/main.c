#include <stdio.h>
#include <stdlib.h>

// a, a+3
int main()
{
    int a=1, b=1, c ,n;
    scanf("%d", &n);
    for( int i=1; i<n-1; i++){

        c = a+b;
        a = b;
        b = c;

    }
    printf("%d", b);
    return 0;
}
