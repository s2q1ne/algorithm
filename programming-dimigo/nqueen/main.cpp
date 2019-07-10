#include <iostream>
#include <stdio.h>

using namespace std;


int ch1[40], ch2[40], ch3[20]; //ch1: ¢Ø ch2: ¢Ö, ch3: ¡è
int n, cnt;

int check(int x, int y){
    if( ch1[x+y]==1 ) return 0;
    if( ch2[n-x+y-1]==1 ) return 0;
    if( ch3[x] == 1) return 0;
    return 1;
}

void dfs( int r, int c ){ //r: row
    if( r >= n ){
        cnt++;
        return;
    }
    for( int i=0; i<n; i++){
        if( check(i,r)==1 ){
            ch1[r+i]=ch2[n-i-1+r]=ch3[i]=1;
            dfs(r+1, c+1);
            ch1[r+i]=ch2[n-i-1+r]=ch3[i]=0;
        }
    }
}

int main()
{
    scanf("%d", &n);
    dfs(0,0);
    printf("%d", cnt);
    return 0;
}
