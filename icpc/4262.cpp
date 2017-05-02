#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;


vector<int> topo;

void dfs(bool edge[][1010],int i,int N, bool visit[])
{
    for(int k = 1;k<=N;k++) {
        if(edge[i][k]&&!visit[k]) {
            visit[k] = true;
            dfs(edge,k,N,visit);
        }
    }
    topo.push_back(i);
}
void dfs_reverse(bool edge[][1010],int i, int N, bool visit[])
{
    for(int k = 1;k<=N;k++) {
        if(edge[k][i]&&!visit[k]) {
            visit[k] = true;
            dfs_reverse(edge,k,N,visit);
        }
    }
}
int scc_cal(bool edge[][1010],int N)
{
    bool visit[1010] = {0};
    topo.clear();
    for(int i = 1;i<=N;i++) {
        if(!visit[i]) {
            visit[i] = true;
            dfs(edge,i,N,visit);
        }
    }
    memset(visit,0,sizeof(visit));
    int scc_num = 0;
    for(int i = topo.size()-1;i>=0;i--) {
        if(!visit[topo[i]]) {
            visit[topo[i]] = true;
            dfs_reverse(edge,topo[i],N,visit);
            ++scc_num;
        }
    }
    return scc_num;
}
int main(void)
{
    int case_num;
    int x,y;
    int N,M;
    bool edge[1010][1010];
    scanf("%d",&case_num);
    for(int case_count = 0;case_count<case_num;case_count++) {
        scanf("%d %d",&N,&M);
        memset(edge,0,sizeof(edge));
        int count = 0;
        for(int count=0;count<M;count++) {
            scanf("%d",&x);
            scanf("%d",&y);
            edge[x][y] = true;
        }
        scanf("%d",&x);
        printf("%d\n",scc_cal(edge,N));
    }
    return 0;
}
