#include <stdio.h>

int main()
{
    char coin[1000];

    int n=0;
    scanf("%s", &coin);
    while( coin[n++] != 0);
    printf("%d", n-1);
    return 0;
}
