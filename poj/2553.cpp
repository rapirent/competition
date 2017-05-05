#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

bool edge[5010][5010];
bool indegree[5010];
bool visited[5010];
vector<int> topo;
int scc_list[5010];
vector<int> reverse_scc_list[5010];
void dfs(int i, int N)
{
    for(int k = 1; k<=N; k++) {
        if(!visited[k]&&edge[i][k]) {
            visited[k] = true;
            dfs(k,N);
        }
    }
    topo.push_back(i);
}

void dfs_reverse(int i, int N, int num)
{
    for(int k = 1; k<=N; k++) {
        if(visited[k]&&edge[k][i]) {
            visited[k] = false;
            dfs_reverse(k,N,num);
        }
    }
    scc_list[i] = num;
//    reverse_scc_list[num].push_back(i);
}
void search(int N)
{
    int tmp;
    for(int i = 1; i<=N; i++) {
        for(int j = 1; j<=N; j++) {
            if(edge[i][j]&&(scc_list[i]!=scc_list[j])) {
                tmp = scc_list[i];
                for(int k = 1; k<=N; k++) {
                    if(scc_list[k] == tmp) {
                        scc_list[k] = -1;
                    }
                }
            }
        }
    }
}

void scc(int N)
{
    topo.clear();
    for(int i = 0; i<5010; i++) {
        visited[i] = false;
        scc_list[i] = -1;
//        reverse_scc_list[i].clear();
    }
    for(int i = 1; i<=N; i++) {
        if(!visited[i]) {
            visited[i] = true;
            dfs(i,N);
        }
    }
    int num = 0;
    for(int i = topo.size() - 1; i>=0; i--) {
        if(visited[topo[i]]) {
            visited[topo[i]] = false;
            dfs_reverse(topo[i],N,num++);
        }
    }
    search(N);
}

int main(void)
{
    int n,m;
    int x,y;
    while(scanf("%d",&n)==1&&n!=0) {
        scanf("%d",&m);
        memset(edge,0,sizeof(edge));
        for(int i = 0; i<m;i++) {
            scanf("%d %d",&x,&y);
            edge[x][y] = true;
        }
        scc(n);
        bool flag = false;
        for(int i = 1; i<=n; i++) {
            if(scc_list[i] != -1) {
                if(!flag) {
                    printf("%d",i);
                    flag = true;
                }
                else {
                    printf(" %d",i);
                }
            }
        }
        if(!flag) {
            puts("");
        }
        puts("");
    }
    return 0;
}
