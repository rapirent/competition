#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
    int cash,N;
    int n[100000];
    int d[100000];
    int answer[1000050];
    while(scanf("%d %d",&cash,&N)!=EOF) {
        for(int a = 0;a<N;a++) {
            scanf("%d %d",&n[a],&d[a]);
        } 
        memset(answer,0,sizeof(answer[0])*(cash + 1));
        for(int i = 0; i<N;i++) {
            int num = n[i];//幾張
            for(int j = 1;num>0;j*=2) {
                if(j>num) {
                    j = num;
                }
                num = num - j;
                for(int k = cash;k>=d[i]*j;k--) {
                    answer[k] = max(answer[k], answer[k - d[i]*j] + d[i]*j);
                }
            }
        }
        printf("%d\n",answer[cash]);
    }
    return 0;
}
