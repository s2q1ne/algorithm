#include <stdio.h>
int main()
{
    int a=1,b=1;
    double c;
    while( 1){
        scanf("%d %d", &a, &b);
        if((a==0 && b==0) ) break;
        if( a > 1000 || b > 4000 || a<0 || b<0 ) {
            printf("INPUT ERROR!\n");
            continue;
            // A+B = a
            // 4A+2B = b
            // b-2a = 2A
        }
        c = (b-(2*a))/2.0;
        if( c - (int)c != 0 || a-c < 0 || a>b || c<0 ) {
            printf("0\n");
            continue;
        }
        printf("%d %d\n", (int)c,(int) (a-c));
    }

    return 0;
}
