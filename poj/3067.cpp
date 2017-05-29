#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

struct connect {
    int east,west;
    bool operator< (const connect& a) const {
        if(east==a.east) {
            return west>a.west;
        }
        return east>a.east;
    }
};
long long t[1500];

int low_bit(int n)
{
    return n&(-n);
}

void add(int n,long long d)
{
    while(n<1500) {
        t[n]+=d;
        n+=low_bit(n);
    }
}

long long sum(int x)
{
    long long s = 0;
    while(x>0) {
        s+=t[x];
        x-=low_bit(x);
    }
    return s;
}

vector<struct connect> connection;
int main(void)
{
    int case_num;
    scanf("%d",&case_num);
    int n,m,k;
    for(int case_count = 1;case_count<=case_num;case_count++) {
        memset(t,0,sizeof(t));
        connection.clear();
        scanf("%d %d %d",&n,&m,&k);
        for(int i = 0; i<k;i++) {
            struct connect tmp;
            scanf("%d %d",&tmp.east,&tmp.west);
            connection.push_back(tmp);
        }
        sort(connection.begin(),connection.end());
        long long ans=0;
        for(int i = 0; i<(int)connection.size(); i++) {
            ans+=sum(connection[i].west-1);
            add(connection[i].west,1);
        }
        printf("Test case %d: %lld\n",case_count,ans);
    }
    return 0;
}
