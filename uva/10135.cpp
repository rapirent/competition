#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct point {
    double x,y;
    bool operator< (const point& a) const {
        return (x<a.x) || (x == a.x && y < a.y);
    }
};

vector<struct point> point_set;
vector<struct point> result;

double cross(const point &o, const point &a ,const point &b) 
{
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) *(b.x-o.x);
}

void monotone()
{
    result.clear();
    int m = 0;
    int len = point_set.size();
    for(int i = 0;i<len; i++) {
        while(m>=2&&cross(result[m-2],result[m-1],point_set[i])<=0) {
            m--;
            result.pop_back();
        }
        m++;
        result.push_back(point_set[i]);
    }
    for(int i = len -2, t=m+1;i>=0;i--) {
        while(m>=t&&cross(result[m-2],result[m-1],point_set[i])<=0) {
            m--;
            result.pop_back();
        }
        m++;
        result.push_back(point_set[i]);
    }
    double print = 0.0;
    for(int i = 1;i<m;i++) {
        print += sqrt(pow(result[i-1].x - result[i].x,2) + pow(result[i-1].y - result[i].y, 2));
    }
    printf("%.2lf\n",print);
}

int main(void)
{
    int case_num;
    scanf("%d",&case_num);
    while(getchar()!='\n');
    int num;
    struct point input;
    while(case_num--) {
        while(getchar()!='\n');
        scanf("%d",&num);
        point_set.clear();
        for(int i = 0;i<num;i++) {
            scanf("%lf %lf",&input.x,&input.y);
            point_set.push_back(input);
        }
        sort(point_set.begin(),point_set.end());
        input.x = 0.0;
        input.y = 0.0;
        point_set.insert(point_set.begin(),input);
        monotone();
        if(case_num) {
            puts("");
        }
        while(getchar()!='\n');
    }
    return 0;
}
