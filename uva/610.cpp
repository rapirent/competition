#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
    int from;
    int to;
    bool operator<(const node& a) const {
        if(from == a.from) {
            return to < a.to;
        }
        else {
            return from < a.from;
        }
    }
};


bool edge[1010][1010];
int dfn[1010],low[1010];
int dfs_clock;
vector<struct node> result;



void dfs_bridge(int u, int v, int N)
{
    dfn[v] = low[v] = ++dfs_clock;
    for(int i = 1; i<=N ;i++) {
        if(edge[v][i]) {
            if(!dfn[i]) {
                //有可能不是back edge
                dfs_bridge(v,i,N);
                low[v] = min(low[v],low[i]);
                if(low[i] > dfn[v]) {
                    //i比v還要年幼
                    struct node tmp;
                    tmp.from = i;
                    tmp.to = v;
                    result.push_back(tmp);
                    tmp.from = v;
                    tmp.to = i;
                    result.push_back(tmp);
                    edge[i][v] = edge[v][i] = 0;
                }
            }
            else if((u!=i)||(u==i&&edge[v][i]>=2)) {
                low[v] = min(low[v],low[i]);
            }
        }
    }
}

void dfs(int u,int v, int N)
{    
    if(u!=v) {
        struct node tmp;
        tmp.from = u;
        tmp.to = v;
        result.push_back(tmp);
    }

    dfn[v] = 1;
    edge[u][v] = edge[v][u] = 0;
    for(int i = 1; i<=N; i++) {
        if(edge[v][i]) {
            dfs(v,i,N);
        }
    }
}


void find(int N)
{
    memset(low,0,sizeof(low));
    memset(dfn,0,sizeof(dfn));
    dfs_clock = 0;
    result.clear();
    for(int i = 1; i <= N;i++) {
        if(!dfn[i]) {
            dfs_bridge(i,i,N);
        }
    }
    memset(dfn,0,sizeof(dfn));
    for(int i = 1; i <= N; i++) {
        if(!dfn[i]) {
            dfs(i,i,N);
        }
    }
}

int main(void)
{
    int n,m;
    int x,y;
    int case_count = 0;
    while(scanf("%d %d",&n,&m)==2 && (n!=0||m!=0)) {
        memset(edge,0,sizeof(edge));
        for(int i = 0; i<m; i++) {
            scanf("%d %d",&x,&y);
            edge[x][y] = edge[y][x] = true;
        }
        find(n);
        sort(result.begin(),result.end());
        printf("%d\n\n",++case_count);
        for(int i = 0; i<result.size(); i++) {
            printf("%d %d\n",result[i].from,result[i].to);
        }
        printf("#\n");
    }
    return 0;
}
