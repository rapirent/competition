#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main(void)
{
    int n,m;//n=case num, m=vessel num
    int milk[1500];
    while(scanf("%d%d",&n,&m)!=EOF) {
        memset(milk,0,sizeof(milk));
        long long int upper = 0,lower=0;
        for(int i = 0; i<n;i++) {
            scanf("%d",&milk[i]);
            if(lower<milk[i]) {
                lower = milk[i];
            }
            upper += milk[i];
        }
        while(upper>lower) {
            long long int mid = (upper + lower)/2;
            //現在臨界值為mid
            int count = 1;
            long long int sum = 0;
            for(int i = 0;i<n;i++) {
                if(sum + milk[i]>mid) {
                    count++;
                    sum = 0;
                }
                sum+=milk[i];
            }
            if(count<=m) {
                upper = mid;
                //有可能不會進來這邊, (有可能不會進來while迴圈), 所以都把答案視作upper
                //不必要為了可讀性而增加一個find變數, 因為可能不會被賦值
            }
            else {
                lower = mid + 1;
            }
        }
        printf("%lld\n",upper);
    }
    return 0;
}
