#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    switch (n/10){
        case 0:
            printf("0�̻� 10�̸�");
            break;
        case 1:
            printf("10�̻� 20�̸�");
            break;
        case 2:
            printf("20�̻� 30�̸�");
            break;
        case 3:
            printf("30�̻� 40�̸�");
            break;
        case 4:
            printf("40�̻� 50�̸�");
            break;
        case 5:
            printf("50�̻� 60�̸�");
            break;
        case 6:
            printf("60�̻� 70�̸�");
            break;
        case 7:
            printf("70�̻� 80�̸�");
            break;
        case 8:
            printf("80�̻� 90�̸�");
            break;
        case 9:
            printf("90�̻� 100�̸�");
            break;
    }
    return 0;
}
