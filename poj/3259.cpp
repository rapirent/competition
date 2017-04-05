#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

struct edge_node {
    int x,y;
    int length;
};

int main(void)
{
    int num;
    scanf("%d",&num);
    int n,m,w;
    int node[600] = {0};
    while(num-->0) {
        vector<edge_node> edge;
        scanf("%d %d %d",&n,&m,&w);
        for(int i = 0; i < m; i++) {
            edge_node tmp;
            scanf("%d%d%d",&tmp.x,&tmp.y,&tmp.length);
            edge.push_back(tmp);
            int tmp_x = tmp.x;
            tmp.x = tmp.y;
            tmp.y = tmp_x;
            edge.push_back(tmp);
        }
        for(int i = 0;i<w;i++) {
            edge_node tmp;
            scanf("%d%d%d",&tmp.x,&tmp.y,&tmp.length);
            tmp.length = -tmp.length;
            edge.push_back(tmp);
        }
        memset(node,-1,sizeof(node));
        node[1] = 0;
        for(int i = 0; i<n-1;i++) {
            for(int j = 0;j<edge.size();j++) {
                int x = edge[j].x;
                int y = edge[j].y;
                int length = edge[j].length;
                if(node[y]==-1||node[x] + length < node[y]) {
                    node[y] = node[x] + length;
                }
            }
        }
        bool isCan = false;
        for(int j = 0;j<edge.size();j++) {
            int x = edge[j].x;
            int y = edge[j].y;
            int length = edge[j].length;
            if(node[x] + length < node[y]) {
                isCan = true;
                break;
            }
        }
        if(isCan) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }
    return 0;
}
