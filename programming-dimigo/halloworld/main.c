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
    printf("%s", ( b&1?"Ȧ��":"¦��" ));
    */
    /*
    unsigned long long c;
    scanf("%d", &c);
    printf("%s", c>0 ? (c%4==0?"4�� ���": (c&1?"Ȧ��":"¦��" )): "���� ������ �ƴ�" );
    */
    unsigned long long A, B;
    scanf("%lld", &A);
    //printf("%d" , A);
    for(B=A/2; B>=1; B-- ){
        if( A%B == 0 ) {
            printf("%lld�� ���\n", B);
            printf("%lld�� ���\n", A/B);
        }
    }
    return 0;
}
