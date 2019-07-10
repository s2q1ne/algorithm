#include <stdio.h>
#include <stdlib.h>

int n, asprice[12][12], map[12];
int minprice, ok=0;

/*

3
0 86 0
69 0 83
45 97 0

*/


int finished( ){
    for( int i=0; i<n; i++){
        if( map[i] == 0 ) return 0;
    }
    return 1;
}

void printStatus( int cm, int x, int price ){
    for( int i=0; i<n; i++ ) {
        printf("%d ", map[i]);
    }
    printf("\npos: %d, price: %d, Where: %d\n\n", cm, price, x+1);
}

void dfs( int cm, int price, int x ) {
    // cm: 몇번째 도는 싸이클인지, price: 현재 싸이클의 가격, x: 현재 어느 위치인지
    map[x]++;
    //printStatus( cm,  x, price );
    //if( map[x] ) return;
    if( price > minprice ) {
        //printf("빠꾸 \n");
        map[x] = 0;
        return;
    }
    if( finished() ){
        //printf("Arrived : %d\n\n", price+asprice[x][0]);
        if( price < minprice ) minprice = price+asprice[x][0];
        map[x]=0;
        ok=1;
        return;
    }
    for( int i=0; i<n; i++ ){
        if( i==x ) continue;
        if( map[i]==0)
            dfs( cm+1, price+asprice[x][i], i);
    }
    map[x]=0;
}
int main()
{
    int i, j;
    scanf("%d", &n);
    for( i=0; i<n; i++ ){
        for( j=0; j<n; j++ ){
            scanf("%d", &asprice[i][j]);
            minprice += asprice[i][j];
        }
    }
    dfs(0, 0, 0);
    if( ok )
        printf("%d", minprice);
    else
        printf("%d", 0);
    return 0;
}
