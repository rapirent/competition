#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int num[10000000] = {0};
int result[1010] = {0};

inline void big_num()
{
    int digit = 0;
    num[0] = 1;
    for(int i = 2;i<=1000;i++) {
        for(int j = 0;j<=digit;j++) {
            num[j]*=i;
        }
        for(int j = 0;j<=digit;j++) {
            num[j+1] += num[j]/10;
            if(j+1>digit&&num[j+1]) {
                digit++;
            }
            num[j] =num[j]%10;
            result[i] += num[j];
        }
    }
}

int main(void)
{
    big_num();
    int input;
    while(scanf("%d",&input)!=EOF) {
        printf("%d\n",result[input]);
    }
    return 0;
}
