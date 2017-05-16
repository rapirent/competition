#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int capacity[110][110];
int residual[110][110];
int flow[110][110];
bool visit[110];
int bottleneck[110];
int bfs_path[110];


int bfs(int s, int t, int n)
{
    memset(visit, 0, sizeof(visit));
    memset(bottleneck, 0, sizeof(bottleneck));
    queue<int> Q;
    visit[s] = true;
    bfs_path[s] = s;
    bottleneck[s] = 1e9;
    Q.push(s);
    while(!Q.empty()) {
        int i = Q.front();
        Q.pop();
        for(int j = 1; j<=n; j++) {
            if(!visit[j] && residual[i][j] > 0 ) {
                //可以出發到j
                visit[j] = true;
                bfs_path[j] = i;
                bottleneck[j] = min(bottleneck[i], residual[i][j]);
                Q.push(j);
                if(j == t) {
                    return bottleneck[j];//這條路徑的最大瓶頸
                }
            } 

        }
    }
    return 0;
}


int max_flow(int s, int t, int n)
{
    memcpy(residual, capacity, sizeof(capacity));
    int result;
    int aug_path_flow;
    for(result = 0;aug_path_flow = bfs(s,t,n); result+=aug_path_flow) {
        for(int i = bfs_path[t], j = t; i!=j; i = bfs_path[j = i]) {
            flow[i][j] = flow[i][j] + aug_path_flow;
            flow[j][i] = -flow[i][j];
            residual[i][j] = capacity[i][j] - flow[i][j];
            residual[j][i] = capacity[j][i] - flow[j][i];
        }
    }
    return result;
}

int main(void)
{
    int n;
    int s,t,c;
    int x,y;
    int case_count = 0;
    int input;
    while(scanf("%d",&n)!=EOF&&n!=0) {
        memset(capacity,0,sizeof(capacity));
        memset(flow,0,sizeof(flow));
        scanf("%d %d %d",&s,&t,&c);
        for(int i = 0; i<c; i++) {
            scanf("%d %d",&x,&y);
            scanf("%d",&input);
            capacity[y][x] = capacity[x][y] = capacity[x][y] + input;
        }
        printf("Network %d\n",++case_count);
        printf("The bandwidth is %d.\n\n",max_flow(s,t,n));
    }
    return 0;
}

