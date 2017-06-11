#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

struct point {
    double x;
    double y;
};

struct line {
    struct point a,b;
};

vector<struct line> line_set;
vector<int> result;
double cross(const point& o, const point& a, const point& b)
{
    return (a.x-o.x)*(b.y-o.y) - (a.y-o.y)*(b.x-o.x);
}

bool intersect1D(double a1, double a2, double b1, double b2)
{

    if(a1>a2) {
        swap(a1,a2);
    }
    if(b1>b2) {
        swap(b1,b2);
    }
    return max(a1,b1)<=min(a2,b2);
}


bool intersection(const point&a1, const point& a2, const point & b1, const point&b2)
{
    return intersect1D(a1.x,a2.x, b1.x, b2.x) &&
            intersect1D(a1.y,a2.y, b1.y, b2.y) &&
            cross(a1,a2,b1)*cross(a1,a2,b2) <= 0.0 &&
            cross(b1,b2,a1)*cross(b1,b2,a2) <= 0.0;
}


int main(void)
{
    int num;
    double x1,x2,y1,y2;
    while(scanf("%d",&num)!=EOF&&num!=0) {
        line_set.clear();
        for(int i = 0; i<num; i++) {
            scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);
            struct line tmp;
            tmp.a.x = x1;
            tmp.a.y = y1;
            tmp.b.x = x2;
            tmp.b.y = y2;
            line_set.push_back(tmp);
        }
        result.clear();
        for(int i = 0;i< num;i++) {
            int j;
            for(j = i + 1 ; j<num;j++) {
                if(intersection(line_set[i].a,line_set[i].b,line_set[j].a,line_set[j].b)) {
                    break;
                    //跟其他某個人相交
                }
            }
            if(j>=num) {
                //沒有跟其他人相交!!
                result.push_back(i+1);
            }
        }
        printf("Top sticks: ");
        for(int i = 0;i<result.size();i++) {
            if(i) {
                printf(", %d",result[i]);
            }
            else {
                printf("%d",result[i]);
            }
        }
        printf(".\n");
    }
    return 0;
}
