#include <stdio.h>
#include <stdlib.h>
int a=0, b=0, DAY;
int f( int d){
    if( d > DAY ) return 0;
    if( d== DAY) return 1;
    return f(d+2)-f(d+1);
}

int main()
{
    int N;
    scanf("%d %d", &DAY, &N);
    f(DAY);
    int d; //a+b = N¿Ã¥Ÿ
    return 0;
}
