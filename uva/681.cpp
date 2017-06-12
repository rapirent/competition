#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const double eps = 1e-9;

struct point {
    int x;
    int y;
    bool operator<(const point& a) const {
        if(y!=a.y) {
            return y<a.y;
        }
        return x<a.x;
    }
};
vector<struct point>point_set;
vector<struct point>result;
int cross(const point& o, const point&a ,const point &b)
{

	return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}
int monotone(int num)
{
    int m = 0;
    int len = point_set.size();
    for(int i = 0;i<len;i++) {
        while(m>=2 && cross(result[m-2],result[m-1],point_set[i])<=0) {
            result.pop_back();
            m--;
        }
        result.push_back(point_set[i]);
        m++;
    }
    for(int i = len-1 , t=m+1;i>=0;i--) {
        while(m>=t && cross(result[m-2],result[m-1],point_set[i])<=0) {
            result.pop_back();
            m--;
        }
        result.push_back(point_set[i]);
        m++;
    }
    return m;
}

int main(void)
{
    int case_num;
    scanf("%d",&case_num);
    printf("%d\n",case_num);
    int num;
    int dump;
    int m;
    double x,y;
    while(case_num--) {
        scanf("%d",&num);
        point_set.clear();
        for(int i = 0;i<num;i++) {
            struct point tmp;
            scanf("%d %d",&tmp.x,&tmp.y);
            point_set.push_back(tmp);
        }
        if(case_num) {
            scanf("%d",&dump);
            //-1
        }
        sort(point_set.begin(),point_set.end());
        result.clear();
        m = monotone(num);
        printf("%d\n",m);
        for(int i = 0;i<m;i++) {
            printf("%d %d\n",result[i].x,result[i].y);
        }
        if(case_num) {
            printf("-1\n");
        }
    }
    return 0;
}
