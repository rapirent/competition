#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
    int num,w,v,repeat;
    int dis[150][150];
    while(scanf("%d",&num)!=EOF&&num!=0) {
        //memset(dis,-1,sizeof(dis));//無限大
        for(int i = 0; i<150;i++) {
            for(int j = 0;j<150;j++) {
                dis[i][j] = 1e9;
            }
            dis[i][i] = 0;
        }
        for(int u=1;u<=num;u++) {
            scanf("%d",&repeat);
            for(int i = 0;i<repeat;i++) {
                scanf("%d %d",&v,&w);
                dis[u][v] = w;
            }
        }
        for(int k = 1;k<=num;k++) {
            for(int i = 1;i<=num;i++) {
                for(int j = 1;j<=num;j++) {
                    if(dis[i][k] + dis[k][j] < dis[i][j]) {
                        dis[i][j] = dis[i][k] + dis[k][j];
                    }
                }
            }
        }
        int min_path = 1e9;
        int indi_path;
        int count,whichManager=-1;
        int isDisjoint;
        for(count = 1;count<=num;count++) {
            indi_path = 0;
            isDisjoint = 0;
            for(int j = 1;j<=num;j++) {
                if(dis[count][j] == 1e9) {
                    //不能從count出發而到j
                    //但可能可以由其他count到
                    //不一定~
                    isDisjoint = 1;                   
                    break;
                }
                if(dis[count][j]>indi_path) {
                    indi_path = dis[count][j];
                }
            }
            if(min_path>indi_path&&!isDisjoint) {
                min_path = indi_path;
                whichManager = count;
            }
        }
        if(whichManager != -1) {
            printf("%d %d\n",whichManager,min_path);
        }
        else {
            printf("disjoint\n");
        }
    }
    return 0;
}
