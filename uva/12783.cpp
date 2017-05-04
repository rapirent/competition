#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
    int from;
    int to;
    bool operator < (const node &a) const {
        if(from == a.from) {
            return to<a.to;
        }
        return from<a.from;
    }
};

vector<struct node>result;
bool edge[1010][1010];
int low[1010],dfn[1010];
int dfs_clock;
void dfs(int u, int v, int N)
{
    dfn[v] = low[v] = ++dfs_clock;
    for(int i = 0; i<N; i++) {
        if(edge[v][i]) {
            if(!dfn[i]) {
                dfs(v,i,N);
                low[v] = min(low[v],low[i]);
                if(low[i] > dfn[v]) {
                    //(u,v)
                    struct node tmp;
                    tmp.from = i<v?i:v;
                    tmp.to = i<v?v:i;
                    result.push_back(tmp);
                }
            }
            else if(u!=i) {
                low[v] = min(low[v],low[i]);
            }
        }
    }
}

void bridge(int N)
{
    dfs_clock = 0;
    memset(low,0,sizeof(low));
    memset(dfn,0,sizeof(dfn));
    result.clear();
    for(int i = 0; i<N; i++) {
        if(!dfn[i]) {
            dfs(i,i,N);
        }
    }
}

int main(void)
{
    int n,m;
    int x,y;
    while(scanf("%d %d",&n,&m)==2&&(n!=0||m!=0)) {
        memset(edge,0,sizeof(edge));
        for(int i = 0; i<m; i++) {
            scanf("%d %d",&x,&y);
            edge[y][x] = edge[x][y] = true;
        }
        bridge(n);
        printf("%ld",result.size());
        sort(result.begin(),result.end());
        for(int i = 0; i<result.size(); i++) {
            printf(" %d %d",result[i].from,result[i].to);
        }
        puts("");
    }
    return 0;
}

