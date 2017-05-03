#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;


struct node {
    int num;
    int pigeon;
    bool operator<(const node& a) const {
        if(pigeon == a.pigeon) {
            return num<a.num;
        }
        else {
            return pigeon>a.pigeon;
        }
    }
};

vector<int> edge[10010];
int low[10010],dfn[10010];
int dfs_clock;
struct node subset[10010];


void dfs(int u,int v)
{
    low[v] = dfn[v] = ++dfs_clock;
    int child=0;
    int k;
    for(int i = 0;i<edge[v].size();i++) {
        if(edge[v][i]!=u) {
            k = edge[v][i];
            if(dfn[k]) {
                low[v] = min(low[v],dfn[k]);
            }
            else {
                child++;
                dfs(v,k);
                low[v] = min(low[v],low[k]);
                if((u==v&&child>=2)||(u!=v&&low[k]>=dfn[v])) {
                    subset[v].pigeon++;
                }
            }
        }
    }
}

void find(int N)
{
    for(int i = 0;i<N;i++) {
        low[i] = dfn[i] = 0;
        subset[i].num = i;
        subset[i].pigeon = 1;
    }
    dfs_clock = 0;
    for(int i = 0;i<N;i++) {
        if(!dfn[i]) {
            dfs(i,i);
        }
    }
}


int main(void)
{
    int n,m;
    int x,y;
    while(scanf("%d %d",&n,&m)==2&&n!=0&&m!=0) {
        for(int i =0;i<n;i++) {
            edge[i].clear();
        }
        while(scanf("%d %d",&x,&y)==2&&x!=-1&&y!=-1) {
            edge[x].push_back(y);
            edge[y].push_back(x);
        }
        find(n);
        sort(subset,subset + n);
        for(int i = 0;i<m;i++) {

            printf("%d %d\n",subset[i].num,subset[i].pigeon);
        }
        puts("");
        /*
        for(int i = n - 1,count = 0;count<m;count++,i--) {
            printf("%d %d\n",subset[i].num,subset[i].pigeon);
        }
        */
    }
    return 0;
}
