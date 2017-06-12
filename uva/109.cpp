#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct point{
    double x,y;
    bool operator< (const point& a) const {
        return ( x < a.x )||(x == a.x && y < a.y);
    }
};

vector<struct point> point_set;
vector<struct point> result[10000];
bool disable[10000] = {0};
int result_front = 0;

double cross(const point& o, const point& a, const point& b)
{
    return (a.x -o.x)*(b.y - o.y) - (a.y - o.y)*(b.x - o.x);
}

int Andrew_monotone()
{
    int m =0;
    result[result_front].clear();
    for(int i =0;i<point_set.size();i++)
    {
        while(m>=2&&cross(result[result_front][m-2],result[result_front][m-1],point_set[i])>=0) {
            m--;
            result[result_front].pop_back();
        }
        result[result_front].push_back(point_set[i]);
        m++;
    }
    for(int i = point_set.size()-2, t=m+1;i>=0;i--) {
        while(m>=t && cross(result[result_front][m-2],result[result_front][m-1],point_set[i])>=0) {
            m--;
            result[result_front].pop_back();
        }
        result[result_front].push_back(point_set[i]);
        m++;
    }
    m--;
    return m;
}

bool area_intersect(vector<point> a, point& input)
{
    double cross_result;
    if(a.size()<=2) {
        return false;
    }
    double direct = cross(input, a[0], a[1])*cross(input, a[1],a[2]);
    int len = a.size();
    for(int i = 0; i<len-1;i++) {
        cross_result = cross(input, a[i],a[i+1]);
        if(cross_result * direct <0.0 ) {
            return true;
        }
    }
    return false;
}


int main(void)
{
    int n;
    while(scanf("%d",&n)==1&&n!=-1) {
        point_set.clear();
        for(int i = 0;i<n;i++) {
            struct point tmp;
            scanf("%lf %lf",&tmp.x,&tmp.y);
            point_set.push_back(tmp);
        }
        sort(point_set.begin(),point_set.end());
        Andrew_monotone();
        result_front++; 
    }
    struct point input;
    double area = 0.0;
    memset(disable,0,sizeof(disable));
    while(scanf("%lf %lf",&input.x,&input.y)!=EOF) {
        for(int i = 0; i < result_front ; i++) {
            if(!disable[i]&&area_intersect(result[i],input)) {
                disable[i] = true;
            }            
        }
    }

    for(int i = 0; i < result_front ; i++) {
        if(!disable[i]) {
            for(int j = 1; j<result[i].size();j++) {
                area+=(result[i][j-1].x*result[i][j].y) - (result[i][j-1].y*result[i][j].x);
            }
        }
    }
    printf("%.2lf\n",fabs(area/2));

    return 0;
}
