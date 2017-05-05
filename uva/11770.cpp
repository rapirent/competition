#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

vector<int> edge[10010];
vector<int> reverse_edge[10010];
int visit[10010];
int scc_list[10010];
bool scc_index[10010];
vector<int> topo;
void dfs(int i)
{
    visit[i] = true;
    for(int k = 0; k<edge[i].size(); k++) {
        if(!visit[edge[i][k]]) {
            dfs(edge[i][k]);
        }
    }
    topo.push_back(i);
}
void dfs_reverse(int i,int num)
{
    visit[i] = false;
    scc_list[i] = num;
    for(int k = 0; k<reverse_edge[i].size(); k++) {
        if(visit[reverse_edge[i][k]]) {
            dfs_reverse(reverse_edge[i][k],num);
        }
    }
}

void mini_graph(int N)
{
    int tmp;
    for(int i = 1; i<=N ; i++) {
        for(int k = 0; k<reverse_edge[i].size(); k++) {
            if(scc_list[i]!=scc_list[ reverse_edge[i][k] ]) {
                scc_index[scc_list[i]] = false;
            }
        }
    }
}

int find(int N)
{
    topo.clear();
    memset(visit,0,sizeof(visit));
    memset(scc_list,-1,sizeof(scc_list));
    memset(scc_index,0,sizeof(scc_index));
    for(int i = 1; i<=N; i++) {
        if(!visit[i]) {
            dfs(i);
        }
    }
    int num = 0;
    for(int i = topo.size() - 1; i>=0; i--) {
        if(visit[topo[i]]) {
            dfs_reverse(topo[i],num++);
            scc_index[num] = true;
        }
    }
    mini_graph(N);
    int result = 0;
    for(int i = 1; i<=N; i++) {
        if(scc_index[i]) {
            result++;
        }
    }
    return result;
}

int main(void)
{
    int case_num;
    int n,m;
    int x,y;
    scanf("%d",&case_num);
    for(int case_count = 1;case_count<=case_num;case_count++) {
        scanf("%d %d",&n,&m);
        for(int i =0;i<=n;i++) {
            edge[i].clear();
            reverse_edge[i].clear();
        }
        for(int i =0;i<m;i++) {
            scanf("%d %d",&x,&y);
            edge[x].push_back(y);
            reverse_edge[y].push_back(x);
        }
        printf("Case %d: %d\n",case_count,find(n));
    }
    return 0;
}
