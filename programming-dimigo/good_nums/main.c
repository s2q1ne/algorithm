#include <stdio.h>
int chk1[15], chk2[30], chk3[30];
int sum, n;
int chk( int, int);
void dfs(int);
int main()
{
    scanf("%d", &n);
    dfs(1);
    printf("%d", sum);
    return 0;
}
void dfs(int r)
{
    int i;
    if(r > n)
    {
        sum++;
        return;
    }
    for(i = 1; i <= n; i++)
    {
        if(chk(r, i))
        {
            chk1[i]=chk2[r+i]=chk3[r-i+n]=1;
            dfs(r+1);
            chk1[i]=chk2[r+i]=chk3[r-i+n]=0;
        }
    }
}
int chk(int x, int y)
{
    if(chk1[y]==1)
        return 0;
    if(chk2[x+y]==1)
        return 0;
    if(chk3[x-y+n]==1)
        return 0;
    return 1;
}
