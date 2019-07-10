#include <stdio.h>
#include <stdlib.h>

int n, map[25][25], sum;
int dx[4]={0, 1, 0, -1};
int dy[4]={ 1, 0, -1, 0};

void dfs( int x, int y  ){
    if( x>=n || x<0 || y<0 || y>=n ){
        return;
    }
    int s=0;
    if( map[x][y]==1 ){
        printf("%d %d: %d\n", x+1,y+1, sum);
        map[x][y]=-1;
        sum++;
        for( int i=0; i<4; i++){
            dfs( x+dx[i], y+dy[i] );
        }
    }
}

int main()
{
    int i, j, t[100], tc=0, tmp;
    scanf("%d", &n);
    for( i=0; i<n; i++){
        for( j=0; j<n; j++){
            scanf("%1d", &map[i][j]);
        }
    }
    for( i=0; i<n; i++){
        for(j=0; j<n; j++){
            sum=0;
            dfs(i,j);
            if( sum )   t[tc++]=sum;
        }
    }
    printf("%d\n", tc);
    for( i=0; i<tc; i++){
        for( j=i; j<tc; j++){
            if( t[i]>t[j] ){
                tmp=t[i];
                t[i]=t[j];
                t[j]=tmp;
            }
        }
    }
    for( i=0; i<tc; i++)
        printf("%d\n", t[i]);
    return 0;
}
