#include <stdio.h>

int main()
{
    int sum=0, tmp=1;
    while( tmp != 0){
        scanf("%d", &tmp);
        sum += tmp;
    }printf("%d", sum);
    return 0;
}
