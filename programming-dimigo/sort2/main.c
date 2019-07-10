#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, NUM[100];
    int i,j, tmp;
    scanf("%d", &N);
    for( i=0; i<N; i++ ) scanf("%d", &NUM[i]);
    for( i=0; i<N-1; i++){
        for( j=1; j<N-i; j++){
            if( NUM[j] < NUM[j-1]){
                tmp = NUM[j];
                NUM[j] = NUM[j-1];
                NUM[j-1] = tmp;
            }
        }
        for( j=0; j<N; j++){
            printf("%d ", NUM[j]);
        }printf("\n");
    }
    return 0;
}
