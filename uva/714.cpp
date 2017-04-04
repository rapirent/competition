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
    scanf("%d",&n);
    while(n-->0) {
        int upper = 0,lower = 0;
        scanf("%d%d",&m,&k);
        for(int a = 0;a<m;a++) {
            scanf("%d",&book[a]);
            if(lower<book[a]) {
                lower = book[a];
            }
            upper+=book[a];
        }
        int num = 0,mid;
        while(upper>lower) {
            long long int sum = 0;
            mid = (upper+lower)/2;
            for(int i = 0;i<m;i++) {
                if(sum + book[i] > mid) {
                    //這個值可以分給一個人
                    num++;
                    sum = 0;
                }
                sum+=book[i];
            }
            if(num>k) {
                lower = mid +1;
            }
            else {
                upper = mid;
            }
        }
        vector<int> stack[600];
        long long int sum = 0;
        int j = 0;
        printf("max= %d",mid);
        for(int i = 0;i<k;i++) {
            int shen_sha = lower;//剩下多少
            while(shen_sha>=0) {
                printf("j=%d\n",j);
                printf("book[j]=%d",book[j]);
                if(shen_sha-book[j] >= 0&&j<m) {
                    stack[i].push_back(book[j]);
                    j++;
                }
                shen_sha-=book[j];
            }
            i++;
        }
        
        for(int i = 0; i<k;i++) {
            int j;
            for(j = 0;j<stack[i].size();j++) {
                printf("%d ",(stack[i])[j]);
            }
            if(i>0) {
                printf("/");
            }
        }
        printf("\n");

    }
    return 0;
}
