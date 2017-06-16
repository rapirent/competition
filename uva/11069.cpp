#include <cstdio>
#include <iostream>

using namespace std;



int main(void)
{
    int momerized[80] = {0};
    momerized[1] = 1;
    momerized[2] = 2;
    momerized[3] = 2;
    for(int i = 4;i<=76;i++) {
        momerized[i] = momerized[i - 2] + momerized[i-3];
    }
    int input;
    while(scanf("%d",&input)!=EOF) {
        printf("%d\n",momerized[input]);
    }
    return 0;
}
