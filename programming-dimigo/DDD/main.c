#include <stdio.h>
#include <stdlib.h>

int main()
{
    //
    //A B C
    //D E 0
    //F 1 2
    //A A+1 A+2
    //A+3 A+4 0
    //A+5 1 2
    int n, i,j, cnt1=0, cnt2=0;
    scanf("%d", &n);
    for( i=0; i<n; i++ ){
        for( j=n; j>i; j--){
            printf("%c", 'A'+cnt1++);
            printf(" ");
        }for( j=0; j<i; j++){
            printf("%d", cnt2++);
            printf(" ");
        }
        printf("\n");
    }
    return 0;
}
