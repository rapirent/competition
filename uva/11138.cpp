#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;
bool fits[510][510];
int right_match[510];
int left_match[510];
bool visited[510];

bool dfs(int x, int m)
{
    for(int y = 0; y<m; y++) {
        if(fits[x][y]&&!visited[y]) {
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


int bimatch(int n,int m)
{
    memset(right_match, -1, sizeof(right_match));
    memset(left_match, -1, sizeof(left_match));

    int count = 0;
    for(int x = 0; x<n; x++) {
        memset(visited, 0, sizeof(visited));
        if(dfs(x, m)) {
            count++;
        }
    }
    return count;
}
int main(void)
{
    int case_num;
    int bolts,nuts,input;
    scanf("%d",&case_num);
    for(int case_count = 1; case_count<=case_num; case_count++) {
        memset(fits, 0, sizeof(fits));
        scanf("%d%d",&bolts,&nuts);
        for(int b=0;b<bolts;b++) {
            for(int n=0;n<nuts;n++) {
                scanf("%d",&input);
                if(input) {
                    fits[b][n] = true;
                }
            }
        }
        printf("Case %d: ",case_count);
        printf("a maximum of %d nuts and bolts ",bimatch(bolts, nuts));
        printf("can be fitted together\n");
    }
    return 0;
}
