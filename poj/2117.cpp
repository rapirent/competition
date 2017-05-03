#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>

using namespace std;


vector<int> edge[10010];
int dfn[10010];
int low[10010];
int subpart[10010];
int dfs_clock;
int max_result;
int part;


void dfs(int u,int v)
{
    dfn[v] = low[v] = ++dfs_clock;
    int child = 0;
    for(int it = 0;it<edge[v].size(); it++) {
        if(edge[v][it]!=u) {
            int k = edge[v][it];
            if(dfn[k]) {
               low[v] = min(low[v],dfn[k]);
            }
            else {
                child++;
                dfs(v,k);
                low[v] = min(low[v],low[k]);
                if((u==v&&child>=2)||(u!=v&&low[k]>=dfn[v])) {
                    subpart[v]++;
                    if(max_result<subpart[v]) {
                        max_result = subpart[v];
                    }
                }
            }
        }
    }
}

void find(int N)
{
    //init
    for(int i = 0;i<N;i++) {
        dfn[i] = low[i] = 0;
        subpart[i] = 1;
    }
    dfs_clock = 0;
    max_result = 1;
    part = 0;
    //注意！有可能一開始圖就已經是分割的，所以得求初始分割數
    for(int i =0;i<N;i++) {
        if(!dfn[i]) {
            part++;
            dfs(i,i);
        }
    }
}

int main(void)
{
    int p,c;
    int x,y;
    while(scanf("%d %d",&p,&c)==2&&(p!=0||c!=0)) {
        if(c==0) {
            printf("%d\n",p-1);
            continue;
        }
        for(int i =0;i<=p;i++) {
            edge[i].clear();
        }
        for(int i = 0;i<c;i++) {
            scanf("%d %d",&x,&y);
            edge[x].push_back(y);
            edge[y].push_back(x);
        }
        find(p);
        printf("%d\n",part + max_result - 1);
    }
    return 0;
}
