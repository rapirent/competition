#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int low[1010];
int dfn[1010];
int subnet[1010];
bool edge[1010][1010];
vector<int> arti;

int dfs_time;
void dfs(int i,int j,int N)
{
    dfn[j] = low[j] = ++dfs_time;
    int child=0;
    for(int k = 1;k<=N;k++) {
        if(edge[j][k]&&k!=i) {
            if(dfn[k]) {
                low[j] = min(low[j],dfn[k]);
            }
            else {
                child++;
                dfs(j,k,N);
                low[j] = min(low[j],low[k]);
                if((i==j&&child>=2)||(i!=j&&low[k]>=dfn[j])) {
                    if(subnet[j]==1) {
                        arti.push_back(j);
                    }
                    subnet[j]++; 
                }
 
            }
       }
    }
}

void find(int N)
{
    dfs_time = 0;
    for(int i = 0;i<1010;i++) {
        low[i] = dfn[i] = 0;
        subnet[i] = 1;
    }
    for(int i = 1;i<=N;i++) {
        if(!dfn[i]) {
            //還沒拜訪過
            dfs(i,i,N);
        }
    }
}

int main(void)
{
    int x,y;
    int max;
    int case_count = 0;
    while(scanf("%d %d",&x,&y)==2&&x!=0) {
        max = -1;
        if(x>max) {
            max = x;
        }
        memset(edge,0,sizeof(edge));
        if(y>max) {
            max = y;
        }
        edge[x][y] = edge[y][x] = true;
        while(scanf("%d",&x)&&x!=0) {
            if(x>max) {
                max = x;
            }
            scanf("%d",&y);
            if(y>max) {
                max = y;
            }
            edge[x][y] = edge[y][x] = true;
        }
        arti.clear();
        find(max);
        if(case_count) {
            puts("");
        }

        printf("Network #%d\n",++case_count);
        if(arti.size()==0) {
            printf("  No SPF nodes\n");
        }
        else {
            sort(arti.begin(),arti.end());
            for(int i =0;i<arti.size();i++) {
                printf("  SPF node %d leaves %d subnets\n",arti[i],subnet[arti[i]]);
            }
        }
    }

    return 0;
}
