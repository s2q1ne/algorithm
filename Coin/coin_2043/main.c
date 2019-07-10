#include <stdio.h>

int main()
{
    int a, b=10;
    scanf("%d", &a);
    while( b-->1 ){
        printf("%d * %d = %d\n", a, b, a*b);
    }
    return 0;
}
