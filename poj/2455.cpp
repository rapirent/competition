#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;


struct edge {
    int u;
    int v;
    int length;
};

vector<struct edge> edge_list;
int visit[210];
int path[210];
int capacity[210][210];
int flow[210][210];
int residual[210][210];
int bottleneck[210];

int bfs(int s, int t)
{
    //找出bottleneck
    memset(visit, 0, sizeof(visit));
    queue<int> Q;
    visit[s] = true;
    bottleneck[s] = 1e9;
    Q.push(s);
    while(!Q.empty()) {
        int i = Q.front();
        Q.pop();
        for(int j = 1; j<= t; j++) {
            if(!visit[j]&&residual[i][j]>0) {
                visit[j] = true;
                path[j] = i;//上一個是誰
                bottleneck[j] = min(bottleneck[i], residual[i][j]);
                Q.push(j);
                if(j==t) {
                    return bottleneck[j];
                }
            }
        } 
    }
    return 0;
}

int max_flow(int constrain, int t)
{
    int s = 1;
    int u,v;
    memset(flow, 0, sizeof(flow));
    memset(capacity, 0, sizeof(capacity));
    for(int i = 0; i<edge_list.size(); i++) {
        if(edge_list[i].length<=constrain) {
            u = edge_list[i].u;
            v = edge_list[i].v;
            capacity[u][v] = capacity[v][u] = capacity[v][u] + 1;
        }
    }
    memcpy(residual, capacity, sizeof(capacity));
    int aug_flow, total_flow;
    for(total_flow = 0; aug_flow=bfs(s, t); total_flow = total_flow + aug_flow) {
        for(int i = path[t], j=t; i!=j; i=path[j=i]) {
            //由後而前
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
    int N,P,T;
    int max_length = 0,min_length = 0;
    scanf("%d %d %d",&N,&P,&T);
    for(int i = 0; i<P; i++) {
        struct edge tmp;
        scanf("%d %d %d",&tmp.u,&tmp.v,&tmp.length);
        if(max_length<tmp.length) {
            max_length = tmp.length;
        }
        edge_list.push_back(tmp);
    }
    int mid, result = -1;
    while(max_length!=min_length) {
        mid = (max_length + min_length)/2;
        result = max_flow(mid,N);
        if(result>=T) {
            max_length = mid;
        }
        else if (result<T){
            min_length = mid + 1;
        }
    }
    printf("%d\n",max_length);
    
    return 0;
}
