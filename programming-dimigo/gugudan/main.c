#include <stdio.h>
#include <stdlib.h>

int main()
{
    int s, e, i, j, k[10];
    scanf("%d %d", &s, &e);
    if( !((2<=s&&s<=9) && (2<=e&&e<=9) ) ) {
        printf("INPUT ERROR!\n");
        return main();
    }
    if( s <= e){
        for( j=1; j<=9; j++){
            for( i=s; i<=e ; i++){
                printf("%d * %d = %2d   ", i, j, i*j);
            }printf("\n");
        }
    }else{
        for( j=1; j<=9; j++){
            for( i=s; i>=e ; i--){
                printf("%d * %d = %2d   ", i, j, i*j);
            }
            printf("\n");
        }
    }
    return 0;
}
