#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int A = time(1), C;
    scanf("%d", &C);
    printf("%d초가 지났습니다. ", time(1)-A);
    return 0;
}
