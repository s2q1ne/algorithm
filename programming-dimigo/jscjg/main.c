#include <stdio.h>
#include <stdlib.h>

#define MX 10000

int MAX_X, MAX_Y;
int toX, toY;

struct coord{
    int x;
    int y;
} list[10000];
int len=0;

int xx[4]={-1, 0, 0, 1 }, yy[4]={0, -1, 1, 0};
int map[1001][1001];


int isM( int x, int y ){
    if( x > MAX_X || x <= 0 || y <=0 || y > MAX_Y ) return 0;
    return 1;
}

void isK( int x, int y, int t ){
    for( int i=0; i<4; i++ ){
        if( isM( x+xx[i], y+yy[i] ) && map[x+xx[i]][y+yy[i]]==0 ){
            map[x+xx[i]][y+yy[i]] = t;
            list[len].x = x+xx[i];
            list[len++].y = y+yy[i];
        }
    }
}

int f( int n ){
    if( n==1 ){
        len=0;
        for( int i=1; i<=MAX_X; i++){
            for( int j=1; j<=MAX_Y; j++){
                if( map[i][j] == n ){
                    isK(i,j,n+1) ;
                }
            }
        }
    }
    else {
        int tlen = len;
        len=0;
        printf("NUM: %d\n", n);

        for( int i=0; i<tlen; i++){
            printf("x: %d, y: %d\n", list[i].x, list[i].y);
            isK(list[i].x, list[i].y, n+1);
        }

        for( int i=1; i<=MAX_Y; i++){
            for( int j=1; j<=MAX_X; j++){
                printf("%d ", map[j][i]);
                /*if( map[j][i] == 0 ){
                    return -1;
                }*/
            }printf("\n");
        }
        if( tlen == 0 ){
            /*
            for( int i=1; i<=MAX_Y; i++){
                for( int j=1; j<=MAX_X; j++){
                    printf("%d ", map[j][i]);
                    /*if( map[j][i] == 0 ){
                        return -1;
                    }
                }printf("\n");
            }*/
            return n;
        }
    }
    return 0;
}

int main()
{
    int fromX, fromY, ans, cnt=0, kkk=0;
    scanf("%d %d", &MAX_X, &MAX_Y);
    for( int i=1; i<=MAX_Y; i++){
        for( int j=1; j<=MAX_X; j++){
            scanf("%1d", &map[j][i]); kkk+=map[j][i];
        }
    }
    if( kkk==0 ) return printf("%d", kkk)*0;

    for (int i = 1; ; i++) {
        ans = f(i);
        if ( ans != 0 ) break;
    }

    printf("%d\n", ans);

    return 0;
}
