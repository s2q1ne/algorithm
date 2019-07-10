#include <stdio.h>
#include <stdlib.h>

int n( int a, int b){
    return a>b?a:b;
}

int m( int a, int b, int c){
    return n(n(a,b),c);
}

int main()
{
    int N, i, j, k, cnt=0;
    scanf("%d", &N);

    for( i=1; i<=N-2; i++ ){
        for( j=i; j<=N-i-1; j++ ){
            if( m(i,j,N-i-j) < N-m(i,j,N-i-j)  && j<=N-i-j/*&& i+j+k == N*/){
                cnt++;
                //printf("%d %d %d\n", i, j, N-i-j);
            }
        }
    }
    printf("%d", cnt);
    return 0;
}
