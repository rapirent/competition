#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int scc_list[10010];
vector<int> edge[10010];
vector<int> rev_edge[10010];
int visited[100010];
vector<int> topo;
bool scc_index[10010];
void dfs(int i)
{
    visited[i] = true;
    for(int k = 0; k<edge[i].size(); k++) {
        if(!visited[edge[i][k]]) {
            dfs(edge[i][k]);
        }
    }
    topo.push_back(i);
}
void dfs_reverse(int i, int num)
{
    visited[i] = false;
    for(int k = 0; k<rev_edge[i].size(); k++) {
        if(visited[rev_edge[i][k]]) {
            dfs_reverse(rev_edge[i][k],num);
        }
    }
    scc_list[i] = num;
    scc_index[num] = true;
}

void find(int N)
{
    int result;
    for(int i = 1;i<=N;i++) {
        for(int k = 0;k<edge[i].size();k++) {
            if(scc_list[i]!=scc_list[edge[i][k]]) {
                scc_index[scc_list[i]] = false;
                break;
            }
        }
    }
}

void scc(int N)
{
    memset(visited,0,sizeof(visited));
    memset(scc_list,-1,sizeof(scc_list));
    memset(scc_index,0,sizeof(scc_index));
    for(int i = 1; i<=N; i++) {
        if(!visited[i]) {
            dfs(i);
        }
    }
    int num = 0;
    for(int i = topo.size() - 1; i>=0; i--) {
        if(visited[topo[i]]) {
            dfs_reverse(topo[i],num++);
        }
    }
}

int main(void)
{
    int n,m;
    int x,y;
    scanf("%d %d",&n,&m);
    for(int i = 0; i<m; i++) {
        scanf("%d %d",&x,&y);
        edge[x].push_back(y);
        rev_edge[y].push_back(x);
    }
    scc(n);
    find(n);
    int count = 0;
    int flag = -1;
    for(int i = 1; i<=n; i++) {
        if(scc_index[scc_list[i]]) {
            if(flag != -1&&flag!=scc_list[i]) {
                count = 0;
                break;
            }
            flag = scc_list[i];
            count++;
        }
    }
    printf("%d\n",count);
    return 0;
}
