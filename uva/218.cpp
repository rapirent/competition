#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct point {
    double x;
    double y;
    bool operator<(const point& a) const {
        return x < a.x || (x == a.x && y < a.y);
    }
};

vector<struct point> point_set;
struct point result[10000];
double corss(const point &o, const point& a, const point& b)
{
    return (a.x - o.x)*(b.y - o.y) - (a.y - o.y)*(b.x - o.x);
}

int Andrew_monotone()
{
    memset(result,0,sizeof(result));
    int m = 0;
    for (int i = 0; i< point_set.size();i++) {
        while(m>=2 && corss(result[m-2],result[m-1],point_set[i])>=0) {
            m--;
        }
        result[m++] = point_set[i];
    }
    for(int i = point_set.size()-1, t=m+1; i>=0; i--)
    {
        while(m>=t && corss(result[m-2], result[m-1], point_set[i])>=0) {
            m--;
        }
        result[m++] = point_set[i];
    }
    return m;
}

int main(void)
{
    int num_count = 0;
    int case_num;
    double x,y;
    int m;
    while(scanf("%d",&case_num)!=EOF&&case_num!=0) {
        if(num_count) {
            puts("");
        }
        point_set.clear();
        for(int i = 0;i<case_num;i++) {
            scanf("%lf %lf",&x,&y);
            struct point tmp;
            tmp.x = x;
            tmp.y = y;
            point_set.push_back(tmp);
        }
        sort(point_set.begin(),point_set.end());
        m = Andrew_monotone();
        printf("Region #%d:\n",++num_count);
        double len = 0;
        for(int i = 0; i<m; i++) {
            if(i) {
                printf("-");
                len += sqrt(pow((result[i].x - result[i-1].x),2)+pow((result[i].y - result[i-1].y),2));
            }
            printf("(%.1lf,%.1lf)", result[i].x, result[i].y);
        }
        printf("\nPerimeter length = %.2lf\n",len);
    }
    return 0;
}
