#include <stdio.h>

int main()
{
    int a;
    scanf("%d", &a);
    printf("%d�ð� ", a/3600);
    a %= 3600;
    printf("%d�� ", a/60);
    a %= 60;
    printf("%d��", a);
    return 0;
}
