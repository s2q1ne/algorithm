#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, i, j = scanf("%d %d", &a, &b);
    for( i=1; i<=9; i++, printf("\n")){
        if( a > b)
            for( j=a; j>=b; j--) printf("%d * %d = %2d%s", j, i, j*i, (j!=b)?"   ":"");
        else
            for( j=a; j<=b; j++) printf("%d * %d = %2d%s", j, i, j*i, (j!=b)?"   ":"");
    }

    return 0;
}
