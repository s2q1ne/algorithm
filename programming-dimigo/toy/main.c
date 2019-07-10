#include <stdio.h>
#include <stdlib.h>

int N; //부품의 종류 수
int NS[100][4]={0,}; //기본부품 1, 기본부품 2, 기본 부품 3, 기본 부품 4

int* get( int n ){ //기본 부품 5
    int i;
    int a[4]={0,};
    for( i=0; i<4; i++){
        if( NS[n][i] !=0 ){
            a[i] = NS[n][i];
        }
    }
    return a;
}

int P( int n){

}

int main()
{
    int NUM, i, a, b, c;
    scanf("%d", &N);
    scanf("%d", &NUM);
    for( i=0; i<NUM; i++){
        scanf("%d %d %d", &a, &b, &c);
        NS[a][b] = c;
    }
    return 0;
}
