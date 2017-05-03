#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

vector<int> edge[110];
int dfn[110];
int low[110];
int dfs_clock;
int second;
void dfs(int u,int v)
{
    dfn[v] = low[v] = ++dfs_clock;
    int child = 0;
    int k;
    bool flag = false;
    for(int i = 0;i<edge[v].size();i++) {
        if(edge[v][i]!=u) {
            flag = true;
            k = edge[v][i];
            if(dfn[k]) {
                low[v] = min(low[v],dfn[k]);
            }
            else {
                child++;
                dfs(v,k);
                low[v] = min(low[v],low[k]);
            }
        }
    }
    if(flag) {
        second++;
    }
}

void find(int N)
{
    memset(dfn,-1,sizeof(dfn));
    memset(low,0,sizeof(low));
    dfs_clock = 0;
    second = 0;
    for(int i = 1;i<=N;i++) {
        if(!dfn[i]) {
            dfs(i,i);
        }
    }
}

int main(void)
{
    int N;
    scanf("%d",&N);
    int in_degree[110] = {0};
    for(int i = 0;i<=N;i++) {
        edge[i].clear();
    }
    int input;
    for(int i = 1;i<=N;i++) {
        while(scanf("%d",&input)&&input) {
            edge[i].push_back(input);
            in_degree[input]++;
        }
    }
    find(N);
    int first = 0;
    for(int i = 1;i<=N;i++) {
        if(!in_degree[i]) {
            first++;
        }
    }
    printf("%d\n%d\n",first,first<second?second:first);
    return 0;
}
