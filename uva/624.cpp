#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>


using namespace std;


void travDP (int print[][1500],int shu[], int i, int j)
{
    if(i==0||j==0) {
        return;
    }
    if(print[i][j] == print[i-1][j]) {
        travDP(print,shu,i-1,j);
        return;
    }
    travDP(print, shu, i-1, j - shu[i-1]);
    printf("%d ",shu[i-1]);
}


int main(void)
{
    int n,t;
    int shu[100] ={0};
    int print[100][1500] ={0};
    while(scanf("%d",&n)!=EOF) {
        scanf("%d",&t);
        memset(shu,0,sizeof(shu));
        memset(print,0,sizeof(print));
        
        for(int count=0;count<t;count++) {
            scanf("%d",&shu[count]);
        }
        for(int i = 0; i<t;i++) {
            for(int j =0; j<=n;j++) {
                if(j - shu[i] <0) {
                    print[i+1][j] = print[i][j];
                }
                else {
                    print[i+1][j] = max(print[i][j], print[i][ j - shu[i] ] + shu[i]);//shu本身就是價值和負重
                }
            }
        }
        travDP(print, shu, t, n);
        printf("sum:%d\n",print[t][n]);
    }
    return 0;
}
