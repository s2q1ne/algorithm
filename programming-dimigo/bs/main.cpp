#include <stdio.h>

int N, board[20][20], check[20]={0}, ans=0, f=0;

void bishop(int r, int cnt)
{
    int i;
    f=0;
    if(r>=N*2){
        if(cnt>ans)ans=cnt;
        return;
    }
    if(r<=N){
        for(i=0; i<r; i++){
            if(board[r-i][1+i]==1&&check[N-r+1+i*2]==0){
                check[N-r+1+i*2]=1;
                bishop(r+1, cnt+1);
                check[N-r+1+i*2]=0;
                f=1;
            }
        }
        if(f==0)bishop(r+1, cnt);
    }
    else{
        for(i=0; i<N*2-r; i++){
            if(board[N-i][r-N+1+i]==1&&check[-N+r+1+i*2]==0){
                check[-N+r+1+i*2]=1;
                bishop(r+1, cnt+1);
                check[-N+r+1+i*2]=0;
                f=1;
            }
        }
        if(f==0)bishop(r+1, cnt);
    }
}

int main()
{
    scanf("%d", &N);
    int i, j;
    for(i=1; i<=N; i++)
        for(j=1; j<=N; j++)
            scanf("%d", &board[i][j]);
    bishop(1, 0);
    printf("%d", ans);
    return 0;
}
