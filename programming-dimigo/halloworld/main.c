#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    /*
    char a[500000], b;
    scanf("%s", &a);
    b=a[strlen(a)-1]-'0';
    if(!( 0 <= b && b<=9) ){
        printf("input error");
        return 0;
    }
    printf("%s", ( b&1?"È¦¼ö":"Â¦¼ö" ));
    */
    /*
    unsigned long long c;
    scanf("%d", &c);
    printf("%s", c>0 ? (c%4==0?"4ÀÇ ¹è¼ö": (c&1?"È¦¼ö":"Â¦¼ö" )): "¾çÀÇ Á¤¼ö°¡ ¾Æ´Ô" );
    */
    unsigned long long A, B;
    scanf("%lld", &A);
    //printf("%d" , A);
    for(B=A/2; B>=1; B-- ){
        if( A%B == 0 ) {
            printf("%lldÀÇ ¹è¼ö\n", B);
            printf("%lldÀÇ ¹è¼ö\n", A/B);
        }
    }
    return 0;
}
