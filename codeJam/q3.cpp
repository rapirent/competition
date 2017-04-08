#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>


using namespace std;

int main(void)
{
    int repeat;
    int k,n;
    scanf("%d",&repeat);
    int l,avg,index,index_num,maxn,minn;
    int remind;
    for(int case_num = 1;case_num<=repeat;case_num++) {
        scanf("%d%d",&k,&n);
        l = floor(log2(n));
        avg =( k - (1<<l)) / (1<<l);
        index = n - (1<<l);
        remind = ( k - (1<<l))%(1<<l);
        
        if(index <= (remind)) {
            index_num = avg + 1;
        }
        else {
            index_num = avg;
        }
        if(index_num==0) {
            printf("Case #%d: 0 0\n",case_num);
            continue;
        }
        maxn = index_num/2;
        minn = (index_num - maxn) == 1 + maxn ? maxn: maxn - 1;
        printf("Case #%d: %d %d\n",case_num,max(maxn,minn),min(maxn,minn));
    }
    return 0;
}
