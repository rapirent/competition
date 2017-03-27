#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
    int repeat;
    scanf("%d",&repeat);
    int input;
    int dp[10100] = {0};
    for(int a=1;a<=10100;a++) {
        for(int b=1;b*b<=a;b++) {
            if(dp[a]) {
                dp[a] = min(dp[a], dp[a - b*b] + 1);
                continue;
            }
            if(dp[a - b*b]||(a - b*b)==0) {
                dp[a] = dp[a - b*b] + 1;
            }
        }
    }
    while(repeat--) {
        scanf("%d",&input);
        printf("%d\n",dp[input]);
    }
    return 0;
}
