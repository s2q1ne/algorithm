#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, i,j, max_ = 0;
    int p[30][3];
    int q[30];
    scanf("%d", &N);
    for(i=0; i<N; i++){
        scanf("%d %d", &p[i][0], &p[i][1]);
        p[i][2]=0;
        q[i]=0;
    }
    for( i=0; i<N; i++){
        for( j=0; j<N; j++){
            if( i==j ) continue;
            if( p[i][0] >= p[j][0] && p[i][1] >= p[j][1]){
                p[j][2]++;
            }
        }
    }
    for( i=0; i<N; i++){
        q[p[i][2]]++;
    }
    for( i=0; i<N; i++){
        if( q[i] > max_){
            max_ = q[i];
        }
    }
    printf("%d", max_);
    return 0;
}
