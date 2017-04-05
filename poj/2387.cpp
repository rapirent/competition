#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;


struct edge_node{
    int x,y;
    int length;
};

int main(void)
{
    int t,n;
    int x,y;
    int node[1010] = {0};
    while(scanf("%d%d",&t,&n)!=EOF) {
        vector<edge_node> edge;
        int count = 0;
        for(;count<t;count++) {
            edge_node tmp;
            scanf("%d %d",&tmp.x,&tmp.y);
            scanf("%d",&tmp.length);
            edge.push_back(tmp);
            int temp_x = tmp.x;
            tmp.x = tmp.y;
            tmp.y = temp_x;
            edge.push_back(tmp);
        }
        fill(node,node+n+1,1e9);
        node[1] = 0;
        for(int i = 0;i<n-1;i++) {
            for(int j =0;j<edge.size();j++) {
                int x = edge[j].x;
                int y = edge[j].y;
                int length = edge[j].length;
                if(node[x] + length < node[y]) {
                    node[y] = node[x] + length;
                    
                }
            }
        }
        printf("%d\n",node[n]);
        edge.clear();
    }
    return 0;
}
