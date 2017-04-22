#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

struct node{
    int d;
    int l;
    int t;
    bool operator< (const struct node &a) const{
        if(a.l == l) {
            return a.t < t;
        }
        return a.l < l;
    }
};

struct vector_node {
    vector<int> d;
    vector<int> l;
    vector<int> t;
};


int main(void)
{
    int k,n,r;
    scanf("%d %d %d",&k,&n,&r);
    int s,d,l,t;
    struct vector_node road[120];
    memset(road,0,sizeof(road));
    for(int i = 0;i<r;i++) {
        scanf("%d %d %d %d",&s,&d,&l,&t);
        (road[s].d).push_back(d);
        (road[s].l).push_back(l);
        (road[s].t).push_back(t);
    }
    priority_queue<struct node>q;
    struct node start;
    start.d = 1;
    start.l = 0;
    start.t = 0;
    q.push(start);
    while(!q.empty())
    {
        struct node now = q.top();
        q.pop();
        if(now.d >= n) {
            printf("%d\n",now.l);
            return 0;
        }
        for(int i = 0;i<road[now.d].d.size();i++) {
            if(now.t + road[now.d].t[i] <= k) {
                struct node tmp;
                tmp.t = now.t + road[now.d].t[i];
                tmp.l = now.l + road[now.d].l[i];
                tmp.d = road[now.d].d[i];
                q.push(tmp);
            }
        }
    }
    printf("-1\n");

    return 0;
}
