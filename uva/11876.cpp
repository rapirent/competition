#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int NOD[1000100] = {0};
int n[1000100] = {0};
int main(void)
{
    for(int i = 1;i<1000100;i++) {
        for(int tmp = i;tmp<1000100;tmp+=i) {
            NOD[tmp]++;
        }
    }
    n[0] = 1;
    for(int i = 1;i<1000099;i++) {
        n[i] = n[i-1] + NOD[n[i-1]];
    }
    int input,input2;
    int repeat;
    scanf("%d",&repeat);
    int num = 1;
    while(repeat--) {
        scanf("%d%d",&input,&input2);
        int lower = lower_bound(n,n+1000100,input) - n - 1;
        int upper = upper_bound(n,n+1000100,input2) - n - 1;
        printf("Case %d: %d\n",num++,upper - lower);
    }
    return 0;
}
