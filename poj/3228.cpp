#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

#define INF 0x3f3f3f3f
using namespace std;


struct edge {
    int u;
    int v;
    int length;
};

vector<struct edge> edge_list;
vector<int> gold, storage;
int flow[700][100];
int residual[700][700];
int capacity[700][700];
int pre[700];
int bottleneck[700];
bool visited[700];
int bfs(int s, int t)
{
    memset(visited, 0, sizeof(bool)*(t+1));

    queue<int> Q;
    visited[s] = true;
    pre[s] = s;
    bottleneck[s] = 1e8;
    Q.push(s);
    while(!Q.empty())
    {
        int i = Q.front();
        Q.pop();
        for(int j = 0; j<=t; j++) {
            if(!visited[j]&&residual[i][j]>0) {
                visited[j] = true;
                pre[j] = i;
                bottleneck[j] = min(bottleneck[i], residual[i][j]);
                Q.push(j);

                if(j==t) {
                    return bottleneck[t];
                }
            }
        }
    }
    return 0;
}

int max_flow(int contrain, int node_num, int edge_num)
{
    int s = 0;
    int t = 3*node_num + 1;
    memset(capacity, 0, sizeof(capacity));
    for(int i = 1; i<=node_num; i++) {
        capacity[0][i] = INF;
        capacity[i][node_num+i] = gold[i-1];
    }
    for(int i = 0; i<edge_num; i++) {
        if(edge_list[i].length<=contrain) {
            capacity[edge_list[i].u + node_num][edge_list[i].v + node_num] = edge_list[i].length;
            capacity[edge_list[i].v + node_num][edge_list[i].u + node_num] = edge_list[i].length;
        }
    }
    for(int i = 1; i<=node_num; i++) {
        capacity[node_num + i][2*node_num + i] = storage[i-1];
        capacity[2*node_num + i][3*node_num + 1] = INF;
    }
    memset(flow, 0, sizeof(flow));
    memcpy(residual, capacity, sizeof(capacity));
    int aug_flow, total_flow;
    for(total_flow = 0; aug_flow = bfs(s,t); total_flow = total_flow + aug_flow) {
        for(int i = pre[t], j = t; i!=j; i=pre[j=i]) {
            flow[i][j] = flow[i][j] + aug_flow;
            flow[j][i] = -flow[i][j];
            residual[i][j] = capacity[i][j] - flow[i][j];
            residual[j][i] = capacity[j][i] - flow[j][i];
        }
    }
    return total_flow;
}

int main(void)
{
    int N,input,M,max_len,min_len,mid,sum;
    bool flag;
    while(scanf("%d",&N)!=EOF&&N!=0) {
        gold.clear();
        storage.clear();
        sum=0;
        for(int i = 0; i<N; i++) {
            scanf("%d",&input);
            sum+=input;
            gold.push_back(input);
        }
        for(int i = 0; i<N; i++) {
            scanf("%d",&input);
            storage.push_back(input);
        }
        scanf("%d",&M);
        edge_list.clear();
        max_len = 0;
        min_len = -1;
        for(int i = 0; i<M; i++) {
            struct edge tmp;
            scanf("%d %d %d",&tmp.u,&tmp.v,&tmp.length);
            edge_list.push_back(tmp);
            if(tmp.length>max_len) {
                max_len = tmp.length;
            }
        }
        flag = 0;
        while(max_len!=min_len) {
            mid = (min_len+max_len)>>1;
            if(max_flow(mid,N,M)>=sum) {
                max_len = mid;
                flag = 1;
            }
            else {
                min_len = mid+1;
            }
        }
        if(flag) {
            printf("%d\n",min_len);
        }
        else {
            printf("No Solution\n");
        }

    }
    return 0;
}
