#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

vector<int> edge[10010];
int visit[10010];
int low[10010];
int dfs_clock;
int result;
void dfs(int u,int v)
{
    low[v] = visit[v] = ++dfs_clock;
    int child = 0;
    int k;
    for(int i = 0;i<edge[v].size();i++) {
        if(edge[v][i]!=u) {
            k = edge[v][i];
            if(visit[k]) {
                low[v] = min(low[v],visit[k]);
            }
            else {
                child++;
                dfs(v,k);
                low[v] = min(low[v],low[k]);
            }
        }
    }
}


void find(int N)
{
    memset(visit,0,sizeof(visit));
    memset(low,0,sizeof(low));
    dfs_clock = 0;
    result = 0;
    for(int i = 1;i<=N;i++) {
        if(!visit[i]) {
            result++;
            dfs(i,i);
        }
    }
}

int main(void)
{
    int case_num;
    int n,m;
    int x,y;
    scanf("%d",&case_num);
    for(int case_count = 1;case_count<=case_num;case_count++) {
        scanf("%d %d",&n,&m);
        for(int i =0;i<=n;i++) {
            edge[i].clear();
        }
        for(int i =0;i<m;i++) {
            scanf("%d %d",&x,&y);
            edge[x].push_back(y);
        }
        find(n);
        printf("Case %d: %d\n",case_count,result);
    }
    return 0;
}
