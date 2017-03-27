#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
    int m,n;
    int item[200][2];
    while(scanf("%d %d",&m,&n)!=EOF) {
        memset(item,0,sizeof(item));
        for(int count=0;count<n;count++) {
            scanf("%d %d",&item[count][0],&item[count][1]);
        }
        int c[10500]={0};
        if(m>=1800) {
            m+=200;
        }
        //因為我們DP是從m開始走回去, 但1800可能買到兩千的東西!!!!
        //因為打折
        for(int i = 0;i<n;i++) {
            for(int j = m;(j-item[i][0])>=0;j--) {
                c[j] = max(c[j - item[i][0]] + item[i][1],c[j]);//買或不買
            }
        }
        int founded=m;
        while(founded>=0&&c[founded]==c[founded-1]) {
            founded--;
        }//真正能夠買的最高價格
        if(founded<=2000&&m>=2000) {
            //打折後最高也買不到2000塊的東西, 代表根本不需要打折
            printf("%d\n",c[m-200]);
            continue;
        }
        printf("%d\n",c[m]);




    }
    return 0;
}
