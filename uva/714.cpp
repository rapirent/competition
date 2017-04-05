#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int main(void)
{
    int n,k,m;
    int book[600] = {0};
    int partition_index[600] = {0};
    scanf("%d",&n);
    while(n-->0) {
        long long int upper = 0,lower = 0;
        scanf("%d%d",&m,&k);
        for(int a = 0;a<m;a++) {
            scanf("%d",&book[a]);
            if(lower<book[a]) {
                lower = book[a];//低者為所有之中最大者
            }
            upper+=book[a];//高者為所有總和
        }
        int partition_num;
        long long int find;
        while(upper>lower) {
            long long int sum = 0;
            partition_num = 1;
            long long int mid = (upper+lower)/2;//目前p(x)之x為mid
            for(int i = 0;i<m;i++) {//試試看能不能使用吧!                
                if(sum + book[i] <= mid) {
                    sum += book[i];
                }
                else {
                    partition_num++;
                    sum = book[i];
                }
            }
            if(partition_num<=k) {
                //partition的總數小於員工數
                upper = mid;//這個可以!!!
                find = mid;
            }
            else {
                lower = mid + 1;//這個不行, 調整下界
                //因為mid不行, 所以我們調高
            }
        }
        //現在的最小臨界值就是mid
        long long int sum = 0;
        int j = 0;
        int remain_partition = k;
        memset(partition_index,0,sizeof(partition_index));
        for(int i = m-1;i>=0;i--) {
            if(sum + book[i]> find || remain_partition - 1>i) {
                //或是因為我們以greedy, 最後一個partition員工一定拿最多!!!
                remain_partition--;//換下一個
                sum = 0;
                sum = book[i];
                partition_index[i] = 1;
            }
            else {
                sum += book[i];
            }
        }
        for(int i = 0; i <m-1;i++) {
            printf("%d ",book[i]);
            if(partition_index[i]==1) {
                printf("/ ");
            }
        }
        printf("%d\n",book[m-1]);
    }
    return 0;
}
