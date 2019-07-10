#include <stdio.h>

int main()
{
    int i=2, j=1;
    do{
        j=1;
        do{
            printf("%d * %d = %d\n", i, j, i*j);
        }while(j++<9);
    }while(i++<9);
    return 0;
}
