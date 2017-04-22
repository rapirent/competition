#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

struct node {
    int u;
    int v;
    int time;
};


void stack(int now,int start,int pre[])
{
    if(now == start) {
        printf(" %d",now);
        return;
    }
    stack(pre[now],start,pre);
    printf(" %d",now);
}

int main(void)
{
    int ni;
    int dis[20];
    int pre[20];
    int case_num = 0;
    while(scanf("%d",&ni)!=EOF&&ni!=0) {
        char discard;
        vector<struct node>w;
        while((discard = getchar())!='\n'&&discard!=EOF);
        for(int u = 1;u<=ni;u++){
            int repeat;
            scanf("%d",&repeat);
            while(repeat--) {
                int v,cost;
                scanf("%d",&v);
                scanf("%d",&cost);
                struct node tmp;
                tmp.u = u ;
                tmp.v = v;
                tmp.time = cost;
                w.push_back(tmp);
            }
        }
        int start,end;
        scanf("%d %d",&start,&end);
        memset(pre,-1,sizeof(pre));
        for(int i = 0; i <20;i++) {
            dis[i] = 1e9;
        }
        dis[start] = 0;
        for(int i =0;i<ni;i++) {
            for(vector<struct node>::iterator it = w.begin();it!=w.end();it++) {
                int tra_u = (*it).u;
                int tra_v = (*it).v;
                int tra_w = (*it).time;
                if(dis[tra_u]+tra_w<dis[tra_v]) {
                    dis[tra_v] = dis[tra_u] + tra_w;
                    pre[tra_v] = tra_u;
                }
            }
        }
        printf("Case %d: Path =",++case_num);
        stack(end,start,pre);
        printf("; %d second delay\n",dis[end]);
    }
    return 0;
}
