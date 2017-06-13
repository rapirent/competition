#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

struct point {
    double x,y;
    bool operator< (const point &a) const {
        return x<a.x||(x==a.x&&y<a.y);
    }
};

vector<struct point> point_set;
vector<struct point> result;

double cross(const point& o, const point& a, const point& b)
{
    return (a.x - o.x)*(b.y - o.y) - (a.y - o.y)*(b.x-o.x);
}

void monotone()
{
    result.clear();
    int len = point_set.size()-1;
    
    double area_poly = 0.0;
    int m = 0;
    struct point tmp;
    tmp.x = 0.0;
    tmp.y = 0.0;
    for(int i = 0;i<len;i++) {
        area_poly+=cross(tmp,point_set[i],point_set[i+1]);
    }
    point_set.pop_back();
    sort(point_set.begin(),point_set.end());
    for(int i = 0;i<len;i++) {
        while(m>=2&&cross(result[m-2],result[m-1],point_set[i])<=0) {
            m--;
            result.pop_back();
        }
        m++;
        result.push_back(point_set[i]);
    }
    for(int i = len - 2, t=m+1;i>=0;i--) {
        while(m>=t&&cross(result[m-2],result[m-1],point_set[i])<=0) {
            m--;
            result.pop_back();
        }
        m++;
        result.push_back(point_set[i]);
    }
    double area_hull = 0.0;
    for(int i = 0;i<m-1;i++) {
        area_hull+=cross(tmp,result[i],result[i+1]);
    }
    area_poly = fabs(area_poly)/2;
    area_hull = fabs(area_hull)/2;
    printf("Wasted Space = %.2lf %%\n",((area_hull - area_poly)/area_hull)*100);
}

int main(void)
{
    int num;
    struct point input;
    int case_num = 0;
    while(scanf("%d",&num)!=EOF&&num!=0) {
        point_set.clear();
        for(int i = 0;i<num;i++) {
            scanf("%lf %lf",&input.x,&input.y);
            point_set.push_back(input);
        }
        point_set.push_back(point_set.front());
        printf("Tile #%d\n",++case_num);
        monotone();
        puts("");
    }
    return 0;
}
