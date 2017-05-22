#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

bool edge[110][110];
int right_match[110];
int left_match[110];
bool visited[110];
bool dfs(int x, int m)
{
    for(int y = 1;y<m;y++) {
        if(edge[x][y]&&!visited[y]) {
            visited[y] = true;
            if(left_match[y]==-1||dfs(left_match[y],m)) {
                right_match[x] = y;
                left_match[y] = x;
                return true;
            }
        }
    }
    return false;
}

int bi_match(int n, int m)
{ 
    memset(left_match,-1, sizeof(left_match));
    memset(right_match, -1, sizeof(right_match));

    int count = 0;
    for(int x = 1;x<n;x++) {
        memset(visited,0,sizeof(visited));
        if(dfs(x,m)) {
            count++;
        }
    }
    return count;
}


int main(void)
{
    int n,m,k;
    int x,y;
    while(scanf("%d %d %d",&n,&m,&k)==3&&n!=0) {
        memset(edge, 0, sizeof(edge));
        for(int i = 0; i<k; i++) {
            scanf("%d",&x);
            scanf("%d %d",&x,&y);
            if(x==0||y==0) {
                continue;
            }
            edge[x][y] = true;
        }
        printf("%d\n",bi_match(n,m));
    }
    return 0;
}
