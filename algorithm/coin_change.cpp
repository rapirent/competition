#include <cstdio>
#include <iostream>

using namespace std;


int price[2] = {2,5};
int number[2] = {1,1};//數量

bool dp[9];

int main(void)
{
    memset(dp,0,siezof(dp));//initialize to false
    dp[0] = true;//0元必可湊得
    for(int i = 8;i>=0;i--) {
        if(dp[i - price[i]] == true) {
            dp[i] = true;
        }
    }
    for (int i=0;i<2;i++) {
        for (int k = 0; k < price[i]; k++) {
            int left = number[i];
            for (int j = k; j<=m; j+=price[i])
                if(dp[j]) {
                    left = number[i];
                }
                else if(left > 0){
                    left--;
                    c[j] = true;
                }
        }
    }
    while()
    return 0;
}
