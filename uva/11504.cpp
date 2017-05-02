#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

bool visit[100001] = {0};
vector<int>edge[100001];
vector<int>topo;
void dfs(int i)
{
    visit[i] = true;
    for(vector<int>::iterator it = edge[i].begin() ;it!=edge[i].end() ;it++) {
        if(!visit[(*it)]) {
            dfs((*it));
        }
    }
    topo.push_back(i);
}
void reverse_dfs(int i)
{
    visit[i] = true;
    for(vector<int>::iterator it = edge[i].begin() ;it!=edge[i].end() ;it++) {
        if(!visit[(*it)]) {
            reverse_dfs((*it));
        }
    }
}
int scc(int N)
{
    memset(visit,0,sizeof(visit));
    topo.clear();
    for(int i = 1;i<=N;i++) {
        if(!visit[i]) {
            dfs(i);
        }
    }
    memset(visit,0,sizeof(visit));
    int result = 0;
    for(int i = topo.size()-1;i>=0;i--) {
        if(!visit[topo[i]]) {
            reverse_dfs(topo[i]);
            result++;
        }
    }
    return result;
}
int main(void)
{
    int case_num;
    scanf("%d",&case_num);
    int n,m;
    int x,y;
    for(int case_count = 0;case_count < case_num;case_count++) {
        scanf("%d %d",&n,&m);
        for(int i = 1;i<=n;i++) {
            edge[i].clear();
        }
        for(int i = 0;i<m;i++) {
            scanf("%d %d",&x,&y);
            edge[x].push_back(y);
        }
        printf("%d\n",scc(n));
    }
    return 0;
}
