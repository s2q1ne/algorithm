#include <stdio.h>

int MAX(int n1, int n2){
    return n1>n2?n1:n2 ;
}
int MIN(int n1, int n2){
    return n1<n2?n1:n2 ;
}

int main()
{
    int n1, n2;
    scanf("%d %d", &n1, &n2);
    int i,j;
    for( i=MIN(n1, n2); i<=MAX(n1,n2); i++){
        for( j=1; j<=9; j++){
            printf("%d * %d = %d\n", i, j, i*j);
        }
    }
    return 0;
}
