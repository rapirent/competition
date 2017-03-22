#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
    int a;
    int price[5] = {50,25,10,5,1};
    int fang_fa[8000] = {0};
    while(scanf("%d",&a)!=EOF) {
        memset(fang_fa,0,sizeof(fang_fa));
        fang_fa[0] = 1;
        for(int i = 0;i<5;i++) {
            for(int k = price[i];k<=a;k++) {
                fang_fa[k] += fang_fa[k - price[i]];
            }
        }
        printf("%d\n",fang_fa[a]);
    }
    return 0;
}
