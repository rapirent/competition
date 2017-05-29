#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#define N 35000

using namespace std;


int t[N];
int count[N];

int lower_bit(int n)
{
    return n&(-n);
}

int sum(int n)
{
    int s = 0;
    while(n>0) {
        s+=t[n];
        n-=lower_bit(n);
    }
    return s;
}


void add(int n, int d)
{
    while(n<N) {
        t[n]+=d;
        n+=lower_bit(n);
    }
}

int main(void)
{
    int star_num,x,y;
    while(scanf("%d",&star_num)!=EOF) {

        memset(t,0,sizeof(t));
        memset(count,0,sizeof(count));
        for(int i = 0; i<star_num; i++) {
            //y沒屁用, 因為它已經是升序了
            scanf("%d %d",&x,&y);
            count[sum(x+1)]++;
            add(x+1,1);

        }
        for(int i = 0; i<star_num; i++) {
            printf("%d\n",count[i]);
        }
    }
    return 0;
}
