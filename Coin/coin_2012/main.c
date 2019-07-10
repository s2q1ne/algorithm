#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    float n2;
    scanf("%d", &n);
    n2 = n * 1.0;
    printf("%.0f", pow(n2, 2.0));
    return 0;
}
