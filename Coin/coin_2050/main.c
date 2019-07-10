#include <stdio.h>

int main()
{
    int total=0, num=1;

    while(num!=0)
    {
        scanf("%d", &num);
        total += num;
    }
    printf("%d", total);
    return 0;
}
