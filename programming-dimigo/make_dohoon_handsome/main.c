#include <stdio.h>
#include <stdlib.h>

int N, num[100][100], K[100];


int main()
{
    int i, j, k,mn=100000, n;
    scanf("%d", &N);
    for( i=0; i<N; i++){
        for( j=0; j<N; j++){
            scanf("%d", &num[i][j]);
        }
    }
    for( i=0; i<N; i++){
        mn = 100000;
        for( j=0; j<N; j++){
            if( mn > num[k[i]][j]){
                mn=num[k[i]][j];
                n = j;
            }
        }

        k = n;
    }
    return 0;
}
