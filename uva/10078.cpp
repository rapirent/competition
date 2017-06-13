#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct point {
    int x;
    int y;
    bool operator< (const point& a) const {
        return x<a.x || (x==a.x && y<a.y);
    }
};

vector<struct point> point_set;

int cross(const point &o, const point &a ,const point &b)
{
    return (a.x -o.x)*(b.y - o.y) - (a.y-o.y)*(b.x - o.x);
}

bool monotone()
{
    int len = point_set.size();
    if(cross(point_set[0],point_set[1],point_set[2])<0) {
        for(int i = 1;i+2<len;i++) {
            if(cross(point_set[i],point_set[i+1],point_set[i+2])>=0) {
                return false;
            }
        }
        if(cross(point_set[len-2],point_set[len-1],point_set[0])>=0) {
            return false;
        }
        if(cross(point_set[len-1],point_set[0],point_set[1])>=0) {
            return false;
        }
  
    }
    else {
        for(int i = 1;i+2<len;i++) {
            if(cross(point_set[i],point_set[i+1],point_set[i+2])<0) {
                return false;
            }
        }
        if(cross(point_set[len-2],point_set[len-1],point_set[0])<0) {
            return false;
        }
        if(cross(point_set[len-1],point_set[0],point_set[1])<0) {
            return false;
        }
    }
    return true;
}

int main(void)
{
    int num;
    struct point input;
    while(scanf("%d",&num)!=EOF&&num!=0) {
        point_set.clear();
        for(int i = 0;i<num;i++) {
            scanf("%d %d",&input.x,&input.y);
            point_set.push_back(input);
        }
        if(!monotone()) {
            printf("Yes\n");
        }
        else {
            printf("No\n");
        }
    }
    return 0;
}
