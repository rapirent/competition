#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
    int n,m;
    int A[150], C[150];
    int answer[1000000] = {0};
    int num[1000000] = {0};
    while(scanf("%d %d",&n,&m)==2&&n!=0&&m!=0) {
        for(int a = 0;a<n;a++) {
            scanf("%d",&A[a]);
        }
        for(int a = 0;a<n;a++) {
            scanf("%d",&C[a]);
        }
        memset(answer,0,sizeof(answer[0])*(m+1));
        answer[0] = 1;
        for(int i = 0;i < n;i++) {
            memset(num,0,sizeof(num[0])*(m+1));
            for(int j = 0;j<=(m - A[i]);j++) {
                if(answer[j]&& !answer[j + A[i]] && num[j]<C[i]) {
                    //answer[某個數]確定可以達到
                    //而answer[某個數 + A[i]]還沒有達到但可以被達到
                    answer[j + A[i]] = 1;
                    num[j + A[i]] = num[j] + 1;
                }
            }
        }
        /*
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<C[i];j++) {
                for(int k = m;k>=A[i];k--) {
                    if(answer[k - A[i]]) {
                        answer[k] += answer[k - A[i]];
                    }     
                }
            }
        }
        */
        int sum=0;
        for(int i = 1 ; i<=m;i++) {
            if(answer[i]) {
                sum++;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
