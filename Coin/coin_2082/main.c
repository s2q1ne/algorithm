#include <stdio.h>
#include <stdlib.h>

int MIN(int n1, int n2){
    return n1<n2?n1:n2 ;
}

int main()
{
    int n1, n2, i;
    scanf("%d %d", &n1 , &n2);
    for( i=MIN(n1, n2); i>=1; i--){
        if( n1 % i == 0 && n2 % i == 0){
            printf("%d", i);
            return 0;
        }
    }
    return 0;
}
