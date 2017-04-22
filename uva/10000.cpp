#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

struct node {
    int u;
    int v;
};


int main(void)
{
    int n;
    int p,q;
    int start;
    int dis[110];
    int case_num = 1;
    while(scanf("%d",&n)!=EOF&&n!=0) {
        vector<struct node>w;
        scanf("%d",&start);
        while(scanf("%d %d",&p,&q)!=EOF&&p!=0&&q!=0) {
            struct node tmp;
            tmp.u = p;
            tmp.v = q;
            w.push_back(tmp);
        }
        for(int i = 0; i <= n;i++) {
            dis[i] = -1e9;
        }
        dis[start] = 0;
        for(int i = 0; i <n;i++) {
            for(vector<struct node>::iterator it = w.begin();it!=w.end();it++) {
                int u = (*it).u;
                int v = (*it).v;
                if(dis[u] + 1 >dis[v]) {
                    dis[v] = dis[u] + 1;
                }
            }
        }
        int max = -1e9,max_index;
        for(int i=0;i<=n;i++) {
            if(dis[i] > max) {
                max = dis[i];
                max_index = i;
            }
        }
        printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n",case_num++,start,max,max_index);
    }
    return 0;
}
