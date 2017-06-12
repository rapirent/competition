#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

struct point {
    long long x,y;
    bool operator< (const point &a) const {
        return x<a.x || (x==a.x&&y<a.y);
    }
};

vector<struct point>point_set;
vector<struct point>result;

long long cross(const point &o, const point &a, const point &b)
{
    return (a.x - o.x)*(b.y - o.y) - (a.y-o.y)*(b.x-o.x);
}

int monotone()
{
    int m = 0;
    int len = point_set.size();
    for(int i = 0;i<len;i++) {
        while(m>=2&&cross(result[m-2],result[m-1],point_set[i])<0) {
            m--;
            result.pop_back();
        }
        m++;
        result.push_back(point_set[i]);
    }
    for(int i = len -2, t=m+1;i>=0;i--) {
        while(m>=t&&cross(result[m-2],result[m-1],point_set[i])<0) {
            m--;
            result.pop_back();
        }
        m++;
        result.push_back(point_set[i]);
    }
    if(m==1) {
        return m;
    }
    return m-1;
}
int main(void)
{
    int test_case;
    scanf("%d",&test_case);
    int num;
    struct point input;
    char dump;
    while(test_case--) {
        scanf("%d",&num);
        point_set.clear();
        for(int i = 0;i<num;i++) {
            scanf("%lld %lld %c",&input.x,&input.y,&dump);
            point_set.push_back(input);
        }
        sort(point_set.begin(),point_set.end());
        result.clear();
        int m = monotone();
        printf("%d\n",m);
        for(int i = 0;i<m;i++) {
            printf("%lld %lld\n",result[i].x,result[i].y);
        }

    }
    return 0;
}
