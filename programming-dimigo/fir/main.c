#include <stdio.h>

int N, M, t[101][101]={0, };

int f( int n, int ns ){
    int i, j;
    if( t[n][0] != 1 ){
        for( i=1; i<n; i++ ){
            for( j=0; j<n; j++){
                if( t[i][j] != 0 ){
                t[i][j]+=ns;
                }
            }
            f(i, t[n][i]*ns);
        }
    }
    else{
        t[n][1]+=ns;
    }
}

int main( ){
    int i, tmp1, tmp2, tmp3;
    scanf("%d" , &N );
    scanf("%d", &M );
    for( i=0; i<M; i++){
        scanf("%d %d %d", &tmp1, &tmp2, &tmp3);
        t[tmp1][0] = 1;
        t[tmp1][tmp2] = tmp3;
    }
    f(N, 1);

    for( i=0; i<N; i++ ){
        if( t[i][0] != 1 )
            printf("%d %d\n", i, t[i][1]);
    }

}
