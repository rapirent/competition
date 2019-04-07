#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
    int repeat;
    scanf("%d",&repeat);
    int case_num = 1;
    int dis[120][120];
    int w[120][2];
    while(repeat--) {
        printf("Case #%d: ",case_num++);
        int n,q;
        scanf("%d %d",&n,&q);
        for(int i = 1;i<=n;i++) {
            scanf("%d %d",&w[i][0],&w[i][1]);           
        }        
        for(int i = 1;i<=n;i++) {
            for(int j = 1;j<=n;j++) {
                int x;
                scanf("%d",&x);
                if(x!=-1) {
                    dis[i][j] = x;
                }
                dis[i][j] = 1e9;
            }
            dis[i][i] = 0;
        }
        for(int k = 1;k<=n;k++) {
            for(int i = 1;i<=n;i++) {
                for(int j = 1;j<=n;j++) {
                    if(dis[i][k] + dis[k][j] < dis[i][j]) {
                        dis[i][j] = dis[i][k] + dis[k][j];
                    }
                }
            }
        }
        int now_cost = (double)dis[0][n]/(double)w[i][0];
        int now = 0;
        int now_life = w[i][1];
        for(int i = 1;i<=n;i++) {
        
        }
    }
    return 0;
}



