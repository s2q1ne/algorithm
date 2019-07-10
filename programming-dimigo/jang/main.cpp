#include <iostream>
#include <stdio.h>
using namespace std;
#define MAX_V 10e9

int m,n, toX, toY, mn=MAX_V;
int tr[101][101];
int dd[8][2]={
    {-2, -1}, {-2, 1}, {-1,-2}, {-1, 2},
    {1,-2}, {1,2}, {2, -1}, {2, 1}
};

int check( int x, int y, int c ){
    if( 1<=x && x<=n && 1<=y && y<=m ){
        if( tr[x][y]!=0 ) return 0;
        return 1;
    }
    return 0;
}

void f( int x, int y, int c ){
    if( x==toX && y==toY ) {
        if( mn>c) {
            mn=c;
            printf("%d find\n", c);
        }
        return;
    }
    if( c>mn ) return;
    for( int i=0; i<8; i++){
        if( check(x+dd[i][0], y+dd[i][1],c)){
            tr[x+dd[i][0]][y+dd[i][1]] = 1;
            f( x+dd[i][0], y+dd[i][1], c+1 );
            tr[x+dd[i][0]][y+dd[i][1]] = 0;
        }
    }
}

int main()
{
    int fromX, fromY;
    scanf("%d %d", &m, &n);
    scanf("%d %d %d %d", &fromX, &fromY, &toX, &toY);
    /*
    for( int i=0; i<m; i++){
        for( int j=0; j<n; j++){
            tr[i][j]=MAX_V;
        }
    }
    */
    tr[fromX][fromY]=0;
    f(fromX, fromY, 0);
    printf("%d", mn);
    return 0;
}
