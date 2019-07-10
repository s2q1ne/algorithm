#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, num[100], i, j, T;
    scanf("%d", &N);
    for( i=0; i<N; i++) scanf("%d", &num[i]);
    for( i=1; i<N; i++){
        T = num[i];
        j=i-1;
        while( j>= 0&& num[j]>T ){
            num[j+1] = num[j];
            j--;
        }
        num[j+1] = T;
        for( j=0; j<N; j++){
            printf("%d ", num[j]);
        }printf("\n");
    }
    return 0;
}
