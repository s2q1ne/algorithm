#include <stdio.h>
#include <stdlib.h>

int N; // 크기
int num; //문명 발상지의 갯수
int a[2001][2001]={0,};

int is( int ta){
    if( ta < 1 || ta > N  ) return 0;
    return 1;
}

int main()
{
    scanf("%d %d", &N, &num);
    int i, j, ta, tb, K=1; //K는 햇수
    //int tmpN[ ] // 문명
    for( i=0; i<num; i++){
        scanf("%d %d", &ta, &tb);
        a[ta][tb] = 1;
        if( is( ta - 1) ){
            if( a[ta-1][tb] < K ){
                a[ta-1][tb] = K+1;
            }
        }

        if( is( ta + 1) ){
            if( a[ta+1][tb] < K ){
                a[ta+1][tb] = K+1;
            }
        }

        if( is( tb - 1) ){
            if( a[ta][tb-1] < K ){
                a[ta][tb-1] = K+1;
            }
        }

        if( is( tb + 1) ){
            if( a[ta][tb+1] < K ){
                a[ta][tb+1] = K+1;
            }
        }
    } K = 2;
    for( i=1; i<=N; i++){
        for( j=1; j<=N; j++){
            if( a[i][j] == K ){
                if( a[i+1][j] == 0 && is(i+1) ){
                    a[i+1][j] = K+1;
                }
            }
            if( a[i][j] == K ){
                if( a[i+1][j] == 0 && is(i+1) ){
                    a[i+1][j] = K+1;
                }
            }
            if( a[i][j] == K ){
                if( a[i+1][j] == 0 && is(i+1) ){
                    a[i+1][j] = K+1;
                }
            }
            if( a[i][j] == K ){
                if( a[i+1][j] == 0 && is(i+1) ){
                    a[i+1][j] = K+1;
                }
            }
        }
    }

    return 0;
}
