#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    switch (n/10){
        case 0:
            printf("0이상 10미만");
            break;
        case 1:
            printf("10이상 20미만");
            break;
        case 2:
            printf("20이상 30미만");
            break;
        case 3:
            printf("30이상 40미만");
            break;
        case 4:
            printf("40이상 50미만");
            break;
        case 5:
            printf("50이상 60미만");
            break;
        case 6:
            printf("60이상 70미만");
            break;
        case 7:
            printf("70이상 80미만");
            break;
        case 8:
            printf("80이상 90미만");
            break;
        case 9:
            printf("90이상 100미만");
            break;
    }
    return 0;
}
