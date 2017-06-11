#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

struct point {
    double x;
    double y;
};
double cross(point& o, point& a, point& b)
{
    return (a.x -o.x)*(b.y - o.y) - (a.y-o.y)*(b.x-o.x);
}

bool intersect1D(double a1, double a2, double b1, double b2)
{
    if(a1>a2) {
        swap(a1,a2);
    }
    if(b1>b2) {
        swap(b1,b2);
    }
    return max(a1,b1) <= min(a2,b2);
}

bool intersect(point a1, point a2, point b1, point b2)
{
    return intersect1D(a1.x , a2.x , b1.x , b2.x) && intersect1D(a1.y , a2.y , b1.y , b2.y) 
        && cross(a1, a2, b1)*cross(a1,a2,b2) <= 0 && cross(b1,b2,a1)*cross(b1,b2,a2) <= 0;   
}
bool intersection(point rec[], point line[])
{
    if(intersect(line[0],line[1],rec[0],rec[2])||
        intersect(line[0],line[1],rec[0],rec[3])||
        intersect(line[0],line[1],rec[1],rec[3])||
        intersect(line[0],line[1],rec[1],rec[2])) {
        return true;
    }
    return false;
}

int main(void)
{
    struct point line[2];
    struct point rec[4];
    int num;
    scanf("%d",&num);
    double input1,input2,input3,input4;
    double xmax, xmin, ymax, ymin;
    while(num--) {
        scanf("%lf %lf %lf %lf",&line[0].x,& line[0].y,& line[1].x,& line[1].y);
        scanf("%lf %lf %lf %lf",&input1,&input2,&input3,&input4);
        xmin = rec[0].x = rec[3].x = min(input1,input3);
        ymax = rec[0].y = rec[2].y = max(input2,input4);
        xmax = rec[2].x = rec[1].x = max(input1,input3);
        ymin = rec[3].y = rec[1].y = min(input2,input4);
        if(line[0].x >= xmin && line[0].x <= xmax && line[0].y >= ymin && line[0].y <= ymax) {
            printf("T\n");
            continue;
        }
        if(line[1].x >= xmin && line[1].x <= xmax && line[1].y >= ymin && line[1].y <= ymax) {
            printf("T\n");
            continue;
        }
        if(intersection(rec,line)==true) {
            printf("T\n");
        }
        else {
            printf("F\n");
        }

    }
    return 0;
}
