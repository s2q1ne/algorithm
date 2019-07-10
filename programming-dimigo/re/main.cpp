#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int maps[101][101], m,n;
int cts, ct[10000], ct_n;
int dd[4][2]={
    {-1,0}, {1,0}, {0,1}, {0,-1}
};

int check_in( int x, int y ){
    if( 0<=x && x<=m && 0<=y && y<=n )
        return 1;
    return 0;
}

int check2(int x, int y){
    if( !check_in(x,y)) return 0;
    if( maps[x][y]==0 ){
        int a=0;
        maps[x][y]=1;
        for( int i=0; i<4; i++){
            a+=check2(x+dd[i][0], y+dd[i][1]);
        }
        return a+1;
    }
    return 0;
}

int check2( int x, int y, int current ){
    for( int i=0; i<4; i++){
        if( check_in( maps[x+dd[i][0]][y+dd[i][1]] ) && maps[x+dd[i]][y+dd[i]]==1 )
            maps[x+dd[i]][y+dd[i]]=0;
    }
    return mn;
}

int check(){
    int chk=0;
    for( int i=0; i<m; i++){
        for( int j=0; j<n; j++ ){
            if( maps[i][j] == -1 ){
                check2(i,j);
            }
        }
    }
}

void setEdge( int x, int y ){
    if( !check_in(x,y) ) return;
    if( maps[y][x]==0 ){
        maps[y][x]=-1;
        for( int i=0; i<4; i++){
            setEdge(x+dd[i][0], y+dd[i][1]);
        }
    }
}

int main()
{
    int c,i,j,k;
    int t_ax, t_bx, t_ay, t_by;
    scanf("%d %d %d", &m, &n);
    for( i=0; i<m; i++ ){
        for( j=0; j<n; j++){
            scanf("%d", &maps[i][j]);
        }
    }
    setEdge(0,0);
    int a=check();

    return 0;
}
