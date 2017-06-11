#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const double eps = 1e-9;

struct point {
    double x;
    double y;
    bool operator<(const point& a) const {
        if(fabs(x-a.y) > eps) {
            return y<a.y;
        }
        return x<a.x;
    }
};
vector<struct point>point_set;
vector<struct point>result;
double cross(const point& o, const point&a ,const point &b)
{

	return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}
void monotone(int num)
{
    for(int i = 0;i<point_set.size();i++) {
        if(result.size()>=2 && cross(result[result.size()-2],result[result.size()-1],point_set[i])<=0.0) {
            result.pop_back();
        }
        result.push_back(point_set[i]);
    }
    for(int i = point_set.size()-1 , t=result.size()+1;i>=0;i--) {
        if(result.size()>=t && cross(result[result.size()-2],result[result.size()-1],point_set[i])<=0.0) {
            result.pop_back();
        }
        result.push_back(point_set[i]);
    }
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
        result.clear();
        scanf("%d",&num);
        point_set.clear();
        for(int i = 0;i<num;i++) {
            struct point tmp;
            scanf("%lf %lf",&x,&y);
            tmp.x = x;
            tmp.y = y;
            point_set.push_back(tmp);
        }
        if(case_num) {
            scanf("%d",&dump);
            //-1
        }
        sort(point_set.begin(),point_set.end());
        result.clear();
        monotone(num);
        printf("%d\n",(int)result.size());
        for(int i = 0;i<(int)result.size();i++) {
            printf("%.0lf %.0lf\n",result[i].x,result[i].y);
        }
        if(case_num) {
            printf("-1\n");
        }
    }
    return 0;
}
