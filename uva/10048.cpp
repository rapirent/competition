#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;


int main(void)
{
    int c,s,q;
    int dis[110][110];
    int case_num = 1;
    while(scanf("%d %d %d",&c,&s,&q)!=EOF&&c!=0&&s!=0&&q!=0) {
        if(case_num!=1) {
            printf("\n");
        } 
        for(int i = 1;i<=c;i++) {
            for(int j = 1;j<=c;j++) {
                dis[i][j] = 1e9;
            }
            dis[i][i] = 0;
        }
        for(int i = 0;i<s;i++) {
            int u,v,deci;
            scanf("%d %d %d",&u,&v,&deci);
            dis[u][v] = deci;
            dis[v][u] = deci;
        }
        for(int k = 1;k<=c;k++) {
            for(int i = 1;i<=c;i++) {
                for(int j = 1;j<=c;j++) {
                    if(dis[i][k]<dis[i][j]&&dis[k][j]<dis[i][j]) {
                        dis[i][j] = max(dis[i][k],dis[k][j]);
                    }

                }
            }
        }
        printf("Case #%d\n",case_num++);
        int start,end;
        for(int i = 0;i<q;i++) {
            scanf("%d %d",&start,&end);
            if(dis[start][end]==1e9) {
                printf("no path\n");
            }
            else {
                printf("%d\n",dis[start][end]);
            }
        }
    }
    return 0;
}
