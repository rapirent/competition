#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

bool edge[300][300];
bool node[300];
bool visit[300];
bool dfs(int i,int n,bool color)
{
    if(visit[i]) {
        if(node[i]==color) {
            return true;
        }
        else {
            return false;
        }
    }
    visit[i] = true;
    node[i] = color;
    for(int j = i+1;j<n;j++) {
        if(edge[i][j]) { 
            if(!dfs(j,n,!color)) {
                return false;
            }
        }
    } 
    return true;
}

int main(void)
{
    int n;
    int edge_num;
    int x,y;
    while(scanf("%d",&n)!=EOF&&n!=0) {
        memset(edge,0,sizeof(edge));
        scanf("%d",&edge_num);
        for(int i = 0;i<edge_num;i++) {
            scanf("%d %d",&x,&y);
            edge[x][y] = edge[y][x] = true;
        }
        memset(visit,0,sizeof(visit));
        memset(node,0,sizeof(node));
        int count;
        bool insert_color = false;
        for(count = 0;count<n;count++) {
            if(!visit[count]) {
                insert_color = !insert_color;
                if(!dfs(count,n,insert_color)) {
                    puts("NOT BICOLORABLE.");
                    break;
                }
            }
        }
        if(count>=n) {
            puts("BICOLORABLE.");
        }
    }
    return 0;
}
