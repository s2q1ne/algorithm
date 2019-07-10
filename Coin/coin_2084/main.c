#include <stdio.h>

int main()
{
    int i=0;
    int num, num2=1, check=0;
    for( num=2; i<30; num++){
        check=0;
        for( num2=2; num2 < num; num2++){
            if( num % num2 == 0) {
                    check=1;
                    break;
            }
        }
        if(check == 0){
            i++;
            printf("%d ", num);
        }
    }

    return 0;
}
