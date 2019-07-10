#include <stdio.h>

int main()
{
    int n1, n2, i, t=0;
    scanf("%d %d", &n1, &n2);
    for( i=n1; i<=n2; i++){
        t+=i;
    }
    printf("%d", t);
    return 0;
}
