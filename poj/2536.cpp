#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;


struct node{
    double x,y;
};

vector<struct node> gopher;
vector<struct node> hole;

bool edge[110][110];
int right_match[110];
int left_match[110];
bool visited[110];
bool dfs(int x, int m)
{
    for(int y = 0;y<m;y++) {
        if(edge[x][y]&&!visited[y]) {
            visited[y] = true;

            if(right_match[y]==-1||dfs(right_match[y],m)) {
                left_match[x] = y;
                right_match[y] = x;
                return true;
            }
        }
    }
    return false;
}

int bi_match(int n, int m)
{
    memset(right_match, -1, sizeof(right_match));
    memset(left_match, -1, sizeof(left_match));

    int count = 0;

    for(int i = 0; i < n; i++) {
        memset(visited, 0, sizeof(visited));
        if(dfs(i,m)) {
            count++;
        }
    }
    return count;
}


int main(void)
{
    int n,m,s,v;
    while(scanf("%d %d %d %d",&n,&m,&s,&v)!=EOF) {
        gopher.clear();
        hole.clear();
        memset(edge, 0, sizeof(edge));
        for(int i = 0; i<n; i++) {
            struct node tmp;
            scanf("%lf %lf",&tmp.x,&tmp.y);
            gopher.push_back(tmp);
        }
        for(int i = 0; i<m; i++) {
            struct node tmp;
            scanf("%lf %lf",&tmp.x,&tmp.y);
            hole.push_back(tmp);
        }
        for(int i = 0; i<(int)gopher.size(); i++) {
            for(int j = 0; j<(int)hole.size(); j++) {
                if(sqrt(pow((gopher[i].x - hole[j].x),2) + pow((gopher[i].y - hole[j].y),2)) <= (double)s*v) {
                    edge[i][j] = true;
                }
            }
        }
        printf("%d\n",n-bi_match(n,m));

    }
    return 0;
}
