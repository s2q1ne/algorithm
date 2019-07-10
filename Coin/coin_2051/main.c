#include <stdio.h>

int main()
{
    int total=0, num=2;

    do{
        total+=num;
    }while((num += 2) <= 100);
    printf("%d", total);
    return 0;
}
