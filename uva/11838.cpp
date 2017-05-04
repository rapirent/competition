#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

bool edge[2010][2010];
bool visit[2010];
vector<int> topo;

void dfs(int i, int N)
{
    visit[i] = true;
    for(int k = 1; k<= N; k++) {
        if(!visit[k]&&edge[i][k]) {
            dfs(k,N);
        }
    }
    topo.push_back(i);
}

void dfs_reverse(int i, int N)
{
    visit[i] = false;
    for(int k = 1; k<= N; k++) {
        if(visit[k]&&edge[k][i]) {
            dfs_reverse(k,N);
        }
    }
    
}


int scc(int N)
{

    memset(visit,0,sizeof(visit));
    topo.clear();
    for(int i = 1; i <= N; i++) {
        if(!visit[i]) {
            dfs(i,N);
        }
    }
    int result = 0;
    for(int i = topo.size() - 1; i >= 0; i--) {
        if(visit[topo[i]]) {
            dfs_reverse(topo[i],N);
            result++;
        }
    }
    return result;
}

int main(void)
{
    int n,m;
    int v,w,p;
    while(scanf("%d %d",&n,&m)==2&&(n!=0||m!=0)) {
        memset(edge,0,sizeof(edge));
        for(int i = 0; i<m; i++) {
            scanf("%d %d %d",&v,&w,&p);
            edge[v][w] = true;
            if(p==2) {
                edge[w][v] = true;
            }
        }
        printf("%d\n",scc(n)==1?1:0);
    }
    return 0;
}
