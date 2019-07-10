#include <stdio.h>
#include <stdlib.h>

int abs( int n ){
    return n>0?n:-n;
}

int main()
{
    int n, i, j, k;
    scanf("%d", &k);
    if( !(1<=k && k<=100 && k%2 == 1 )){
        return printf("INPUT ERROR!")*0;
    }
    for( i=-k/2; i<=k/2; i++, printf("\n")){
        for( j=0; j<k/2-abs(i); j++){
            printf(" ");
        }
        for( j=0; j<=(k/2-abs(i))*2; j++){
            printf("*");
        }
    }
    return 0;
}
