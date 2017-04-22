#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct node {
    //int u;
    int v;
    int time;
};

int main(void)
{
    int repeat;
    scanf("%d",&repeat);
    int n,m,s,t;
    int dis[20010];
    bool inqueue[20010];
    int count[20010];
    int case_num = 1;
    while(repeat--) {
        scanf("%d %d %d %d",&n,&m,&s,&t);
        vector<struct node>w[20010];
        for(int i = 0;i<m;i++) {
            int u,v,time;
            scanf("%d %d %d",&u,&v,&time);
            struct node tmp;
//            tmp.u = u;
            tmp.v = v;
            tmp.time = time;
            w[u].push_back(tmp);
//            tmp.u = v;
            tmp.v = u;
            w[v].push_back(tmp);
        }
        for(int i = 0;i<=n;i++) {
            dis[i] = 1e9;
        }
        dis[s] = 0;
        memset(inqueue,0,sizeof(inqueue));
        memset(count,0,sizeof(count));
        inqueue[s] = true;
        queue<int>q;
        q.push(s);
        int inficycle = 0;
        while(!q.empty()) {
            int now = q.front();
            inqueue[now] = false;
            q.pop();
            for(vector<struct node>::iterator it = w[now].begin();it!=w[now].end();it++) {
                //if((*it).u == now) {
                    //int tra_u = (*it).u;
                if(dis[now] + (*it).time < dis[(*it).v]) {
                    dis[(*it).v] = dis[now] + (*it).time;
                    if(!inqueue[(*it).v]) {
                        q.push((*it).v);
                        inqueue[(*it).v] = true;
                        count[(*it).v]++;
                        if(count[(*it).v] >= n) {
                            inficycle = 1;
                            break;
                        }
                    }
                }
            }
            if(inficycle) {
                break;
            }
        }
        printf("Case #%d: ",case_num++);
        if(dis[t] == 1e9) {
            printf("unreachable\n");
        }
        else {
            printf("%d\n",dis[t]);
        }
    }
    return 0;
}
