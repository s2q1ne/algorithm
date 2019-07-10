#include <stdio.h>

int main()
{
    int a,b,c;
    scanf("%d %d %d", &a, &b, &c);
    printf("%c", a+b+c >= 270 ? 'A' : (a+b+c >= 240?'B':(a+b+c >= 210?'C':(a+b+c >= 150 ? 'D' : 'F'))));
        return 0;
}
