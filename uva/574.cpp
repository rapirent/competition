#include <cstdio>
#include <iostream>
#include <cstring>


int shu[15] = {0},num[15] = {0};
int fang_fa[1200] = {0};
int isPrinted = 0;
using namespace std;

void backtrack(int t,int printed,int anwser,int n)
{
    if(fang_fa[printed-1]<anwser&&printed!=0) {
        return;
    }
    fang_fa[printed] = anwser;
    if(t==0) {
        for(int a=0;a<printed;a++) {
            printf("%d+",fang_fa[a]);
        }
        printf("%d\n",fang_fa[printed]);
        isPrinted = 1;
        return;
    }
    for(int a=0;a<n;a++) {
        if(num[a]>=1&&t>=shu[a]) {
            num[a]--;
            backtrack(t-shu[a],printed+1,shu[a],n);
            num[a]++;
        }
    }
}


int main(void)
{
    int t,n;
    int index_count=0;
    while(scanf("%d",&t)!=EOF) {
        scanf("%d",&n);
        if(t==0&&n==0) {
            break;
        }
        index_count = 0;
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
                shu[index_count] = tmp;
                num[index_count] = 1;
            }
            index_count++;
        }
        isPrinted = 0;
        printf("Sums of %d:\n",t);
        for(int a = 0;a<n;a++) {
            if(num[a]>=1&&t>=shu[a]) {
                num[a]--;
                backtrack(t-shu[a],0,shu[a],n);
                num[a]++;
            }
        }
        if(isPrinted == 0) {
            printf("NONE\n");
        }
        memset(shu,0,sizeof(shu));
        memset(num,0,sizeof(num));
    }
    return 0;
}
