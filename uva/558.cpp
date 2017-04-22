#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

struct node {
    int u;
    int v;
    int t;
};


int main(void)
{
    int repeat;
    int n,m;
    scanf("%d",&repeat);
    int dis[1100];
    int x,y,t;
    while(repeat--) {
        scanf("%d %d",&n,&m);
        for(int i = 1;i<=n+1;i++) {
            dis[i] = 1e9;
        }
        dis[0] = 0;
        vector<struct node>w;
        for(int i = 0;i<m;i++) {
            scanf("%d %d %d",&x,&y,&t);
            struct node tmp;
            tmp.u = x;
            tmp.v = y;
            tmp.t = t;
            w.push_back(tmp);
        }
        for(int i = 0;i<n-1;i++) {
            for(vector<struct node>::iterator data = w.begin();data!=w.end();data++) {
                int u = (*data).u;
                int v = (*data).v;
                int data_t = (*data).t;
                if(dis[u]+data_t<dis[v]) {
                    dis[v] = dis[u] + data_t;
                }
            }
        }
        int isPossi = 0;
        for(vector<struct node>::iterator data = w.begin();data!=w.end();data++) {
            int u = (*data).u;
            int v = (*data).v;
            int data_t = (*data).t;
            if(dis[u]+data_t<dis[v]) {
                isPossi = 1;
                printf("possible\n");
                break;
            }
        }
        if(!isPossi) {
            printf("not possible\n");
        }
    }
    return 0;
}
