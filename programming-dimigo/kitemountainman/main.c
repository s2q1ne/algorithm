#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{


    int a=5, b, tmp;
    printf(" �й��� �Է��ϼ���!\n");
    scanf("%d", &a);
    A:
    printf("������ �Է��ϼ���(m/f)\n");
    scanf("\n%c", &b);
    if( b != 'm' && b!='f'){
        goto A;
        return 0;
    }
    printf(" �й� : %d , ���� : %c\n", a, b);
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
