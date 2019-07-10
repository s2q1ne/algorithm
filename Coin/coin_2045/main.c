#include <stdio.h>

int main()
{
    int sum=0, tmp, n=5;
    while(n>0){
        scanf("%d", &tmp);
        if( tmp >= 1){
            sum += tmp;
            n--;
        }
    }
    printf("%d", sum);
    return 0;
}
