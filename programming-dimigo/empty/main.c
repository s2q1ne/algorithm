#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int deg[102];
int adj[102][102];
int pre[102][102];
int cost[102][102];
int n,m;
bool visit[102];
bool gib[102];
void bfs(){
    queue<int> q;
    for(int i=1;i<=n;++i){
        if(!deg[i]){
            q.push(i);
            visit[i]=1;
        }
    }
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i=1;i<=n;++i){
            if(adj[i][cur]){
                for(int j=1;j<=n;++j){
                    cost[cur][j] += pre[cur][i] * cost[i][j];
                }
            }
        }
        for(int i=1;i<=n;++i){
            if(adj[cur][i]){
                --deg[i];
                if(!deg[i] && !visit[i]){
                    q.push(i);
                    visit[i]=1;
                }
            }
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;++i){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        adj[b][a]=1;
        ++deg[a];
        pre[a][b]=c;
        gib[a]=1;
    }
    for(int i=1;i<=n;++i){
        if(!gib[i]){
            cost[i][i]=1;
        }
    }
    bfs();
    for(int i=1;i<=n;++i){
        if(!gib[i]){
            printf("%d %d",i,cost[n][i]);
        }
    }

}
