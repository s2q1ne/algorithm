#include <stdio.h>

int main()
{
    int a;
    scanf("%d", &a);
    printf("%d시간 ", a/3600);
    a %= 3600;
    printf("%d분 ", a/60);
    a %= 60;
    printf("%d초", a);
    return 0;
}
