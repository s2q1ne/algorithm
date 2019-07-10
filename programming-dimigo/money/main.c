#include <stdio.h>
#include <stdlib.h>

int is( int n ){
    return n>0?1:0;
}

int main()
{
    long long n;
    int s = 0, m;
    scanf("%d", &n);

    printf("%d ", n/10000+is(n%10000) ); //ÁöÆó °³¼ö
    m = 10000 - n%10000; //°Å½º¸§µ· ÃÑ¾×
    if( m == 10000 ) return printf("0")*0;
    s += m/500;
    m%=500;
    s += m/100;
    m%=100;
    s+= m/50;
    m%=50;
    s+=m/10;
    m%=10;
    s+=m/5;
    m%=5;
    s+=m;
    printf("%d", s);
    return 0;
}
