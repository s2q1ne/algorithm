#include <stdio.h>
int main()
{
    int i, j;
    for( i=2; i<=8; i+=2){
        for( j=1; j<=i; j++){
            printf("%d * %d = %d\n", i, j, i*j);
        }
    }
    return 0;
}
