#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;


int capacity[510][510];
int flow[510][510];
int residual[510][510];
bool visited[510];
int pre[510];
int bottleneck[510];

int dfs(int s, int t)
{
    memset(visited, 0, sizeof(visited));
    visited[s] = true;
    queue<int>Q;
    Q.push(s);
    bottleneck[s] = 1e9;
    pre[s] = s;
    while(!Q.empty()) {
        int i = Q.front();
        Q.pop();
        for(int j = 0;j<=t;j++) {
            if(!visited[j]&&residual[i][j]>0) {
                visited[j] = true;
                pre[j] = i;
                bottleneck[j] = min(bottleneck[i],residual[i][j]);
                Q.push(j);
                if(j==t) {
                    return bottleneck[j];
                }
            }
        }
    }
    return 0;
}


int max_flow(int s, int t)
{
    memset(flow,0,sizeof(flow));
    memcpy(residual, capacity, sizeof(capacity));

    int total_flow;
    int aug_flow;
    for(total_flow = 0;aug_flow=dfs(s,t);total_flow+=aug_flow) {
        for(int i = pre[t], j = t;i!=j;i=pre[j=i]) {
            flow[i][j] = flow[i][j] + aug_flow;
            flow[j][i] = -flow[i][j];
            residual[i][j] = capacity[i][j] - flow[i][j];
            residual[j][i] = capacity[j][i] - flow[j][i];
        }
    }
    return total_flow;
}


int main(void)
{
    int N,M;
    int x,y;
    int B,D;
    int input;
    while(scanf("%d",&N)!=EOF) {
        memset(capacity, 0,sizeof(capacity));
        for(int i = 1;i<=N;i++) {
            scanf("%d",&input);
            capacity[i][i+N]=input;
        }
        scanf("%d",&M);
        for(int i = 1;i<=M;i++) {
            scanf("%d %d",&x,&y);
            scanf("%d",&input);
            capacity[x+N][y] += input;
        }
        scanf("%d %d",&B,&D);
        for(int i = 0;i<B;i++) {
            scanf("%d",&x);
            capacity[0][x] = 1e9;
        }
        for(int i = 0;i<D;i++) {
            scanf("%d",&x);
            capacity[N+x][2*N+1] = 1e9;
        }
        printf("%d\n",max_flow(0,2*N+1));
    }
    return 0;
}
