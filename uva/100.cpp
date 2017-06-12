#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int cycle(int n)
{
    int count=1;
    while(n!=1) {
        count++;
        if(n%2) {
             n= 3*n+1;
        }
        else {
            n/=2;
        }
    }
    return count;
}

int main(void)
{
    int a,b;
    int max_num;
    int now_cycle;
    while(scanf("%d %d",&a,&b)!=EOF) {
        printf("%d %d ",a,b);
        max_num = -1;
        for(int i = a;i<=b;i++) {
            if(max_num<(now_cycle = cycle(i))) {
                max_num = now_cycle;
            }
        }
        printf("%d\n",max_num);
    }
    return 0;
}
