#include <stdio.h>
#include <stdlib.h>


int main()
{

    char A = 'a' ;
    int cnt = 3;
    while( 1){
        if( A+cnt - 'a' < 6 ){
            printf("%c", A+cnt);
            cnt++;
        }else break;
    }

    return 0;
}
