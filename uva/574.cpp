#include <cstdio>
#include <iostream>
#include <cstring>


using namespace std;

int main(void)
{
    int t,n;
    int shu[12]={0},num[12]={0};
    int fang_fa[1000] = {0};
    while(scanf("%d",&t)!=EOF) {
        scanf("%d",&n);
        for(int count=0;count<n;count++) {
            int tmp;
            scanf("%d",&tmp);
            int index,founded=0;
            for(index=0;index<12;index++) {
                if(shu[index]==tmp) {
                    num[index]++;
                    founded = 1;
                    break;
                }
            }
            if(founded==0) {
                shu[index] = tmp;
                num[index] = 1;
            }
        }
        memset(shu,0,sizeof(shu));
        memset(num,0,sizeof(num));
    }
    return 0;
}
