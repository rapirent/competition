#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

bool visited[50];
int path[50];
int capacity[50][50];
int flow[50][50];
int residual[50][50];
int bottleneck[50];

//start 皆為0

int dfs(int t)
{
    int s = 0;
    memset(visited,0 ,sizeof(visited));
    visited[s] = true;
    queue<int>Q;
    path[s] = s;
    bottleneck[s] = 1e9;
    Q.push(s);
    while(!Q.empty())
    {
        int i = Q.front();
        Q.pop();
        for(int j = 0;j<=t;j++) {
            if(!visited[j]&&residual[i][j]>0) {
                visited[j] = true;
                path[j] = i;
                bottleneck[j] = min(bottleneck[i],residual[i][j]);
                Q.push(j);
                if(j==t) {
                    return bottleneck[t];
                }
            }
        }
    }
    return 0;
}


int max_flow(int t)
{
    memset(flow,0,sizeof(flow));
    memcpy(residual,capacity,sizeof(capacity));

    int total_flow, aug_flow;
    for(total_flow = 0; aug_flow=dfs(t); total_flow+=aug_flow) {
        for(int i = path[t], j = t; i!=j; i = path[j=i]) {
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
    int case_total,case_count;
    int sticker_num;
    int t,count;
    int n,m;
    scanf("%d",&case_total);
    for(case_count = 1; case_count<=case_total; case_count ++) {
        memset(capacity, 0, sizeof(capacity));
        scanf("%d %d ",&n,&m);
        t = n + m;
        for(int i = 0;i<n;i++) {
            scanf("%d",&count);
            for(int j = 0; j<count;j++) {
                scanf("%d",&sticker_num);
                capacity[i][sticker_num + n - 1]++;
            }
        }
        for(int i = 1;i<n;i++) {
            for(int j = n; j<n+m; j++) {
                if(capacity[i][j]>=1) {
                    capacity[i][j]--;
                }
                else {
                    capacity[j][i] = 1;
                }
            }
        }
        for(int i = n;i<n+m;i++) {
            capacity[i][t] = 1;
        }
        printf("Case #%d: %d\n",case_count,max_flow(t));

    }
    return 0;
}
