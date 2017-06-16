#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
    long long int memorized[110][110] = {0};
    //第i個水球, 第j次
    for(int i = 1;i<110;i++) {
        for(int j = 1;j<64;j++) {
            memorized[i][j] = memorized[i][j-1] + memorized[i-1][j-1] + 1;
        }
    }
    int input;
    long long int input2;
    while(scanf("%d %lld",&input,&input2)!=EOF&&input!=0) {
        int i;
        for(i = 1;i <=63;i++) {
            if(memorized[input][i] >= input2) {
                //找到了，因為比對過個層數大於總層數，一定可以確定
                break;
            }
        }
        if(i>63) {
            printf("More than 63 trials needed.\n");
        }
        else {
            printf("%d\n",i);
        }
    }
    return 0;
}
