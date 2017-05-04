#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
    int from;
    int to;
    bool operator< (const node& a) const {
        if(from == a.from) {
            return to<a.to;
        }
        else {
            return from<a.from;
        }
    }
};

vector<struct node> result;
int dfn[5010],low[5010];
int dfs_time;
bool edge[5010][5010];

void dfs(int u, int v, int N)
{
    dfn[v] = low[v] = ++dfs_time;
    for(int k = 0; k<N; k++) {
        if(edge[v][k]) {
            if(!dfn[k]) {
                dfs(v,k,N);
                low[v] = min(low[v],low[k]);
                if(low[k] > dfn[v]) {
                    struct node tmp;
                    tmp.from = k<v?k:v;
                    tmp.to = k<v?v:k;
                    result.push_back(tmp);
                }
            }
            else if((k!=u)) {
                low[v] = min(low[v],low[k]);
            }
        }
    }
}

void find(int N)
{
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    dfs_time = 0;
    result.clear();
    for(int i = 0;i<N;i++) {
        if(!dfn[i]) {
            dfs(i,i,N);
        }
    }
}


int main(void)
{
    int no;//no_of_server
    int x,y;
    int connect;
    while(scanf("%d",&no)==1) {
        memset(edge,0,sizeof(edge));
        for(int i = 0; i<no; i++) {
            scanf("%d ",&x);
            scanf("(%d)",&connect);
            for(int j = 0; j<connect; j++) {
                scanf("%d",&y);
                edge[x][y] = true;
            }
        }
        find(no);
        sort(result.begin(), result.end());
        printf("%ld critical links\n",result.size());
        for(int i = 0; i<result.size(); i++) {
            printf("%d - %d\n",result[i].from,result[i].to);
        }
        puts("");
    }
    return 0;
}
