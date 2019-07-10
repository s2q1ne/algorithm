#include <stdio.h>
int main()
{
    int n, i=0, tmp;
    float sum = 0.0;
    scanf("%d" ,&n);
    while(i++<n){
        scanf("%d", &tmp);
        sum += tmp;
    }printf("%f", sum / n * 1.0 );
    return 0;
}
