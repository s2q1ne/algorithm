#include <stdio.h>

int main()
{
    const int MONEY = 10000, CR = 500, SH = 700 , CO=400;
    int money=10000;
    int i,j,k;
    for( i=1; i<=(MONEY/CR); i++){
        money = MONEY - i * CR;

        if( money < 0)
            break;

        for ( j=1; j<=(MONEY/SH); j++){
            money = MONEY - i * CR - j * SH;

            if( money < 0)
                break;

            for( k=1; k<=(MONEY/CO); k++){
                money = MONEY - i * CR - j * SH - k * CO;

                if( money == 0){
                printf("크림빵 %d개, 새우깡 %d개, 콜라 %d개\n", i, j, k);
                }
                else if( money < 0)
                    break;
            }
        }
    }
    return 0;
}
