#include <stdio.h>
int main()
{
    int n, sum=1;
    scanf("%d", &n);
    for( ; n>0; n-- ){
        sum *= n;
    }
    printf("%d", sum);
    return 0;
}
