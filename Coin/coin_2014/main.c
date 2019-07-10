
#include <stdio.h>

int main()
{
    int n1, n2, n3;
    scanf("%d %d %d", &n1, &n2, &n3);
    printf("%d", (n1-n2)*(n2+n3)*(n3%n1));

    return 0;
}
