#include <stdio.h>

int main()
{
    for( int i=0; i<=9; i++){
        for( int j=0; j<=9; j++){
            if( i*11+j*11 == 99){
                printf("%d%d + %d%d = 99\n", i,j, j,i );
            }
        }
    }
    return 0;
}
