#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{


    int a=5, b, tmp;
    printf(" 학번을 입력하세요!\n");
    scanf("%d", &a);
    A:
    printf("성별을 입력하세요(m/f)\n");
    scanf("\n%c", &b);
    if( b != 'm' && b!='f'){
        goto A;
        return 0;
    }
    printf(" 학번 : %d , 성별 : %c\n", a, b);
    /*
    scanf_s("%d", &a);
    int *b, *c;
    b = &a;
    c = b;
    printf("%d\n", *c);
//    printf("%f " , 5.5^3.5);



    //scanf("%d", &b);

    while(1){
        if( a==0 ) break;
        scanf("%d.%d", &a, &b);
        printf("%d.%d\n", a,b);
        printf("*%d\n", a*b);
        printf("/ %d\n", a%b);
        printf("-%d\n", a-b);
        printf("+%d\n", a+b);
        printf("/%d\n", a/b);
        printf("^%d\n", a^b);
        printf("&%d\n", a&b);
        printf("|%d\n", a|b);
        printf("^^%f", pow(a/1.0, b/1.0));
    }
    */
    return 0;
}
