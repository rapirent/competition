#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

struct point {
    int x;
    int y;
    bool operator< (const point& a) const {
        return x<a.x||(x==a.x && y<a.y);
    }
};

vector<struct point> point_set;
vector<struct point> ref;
struct point result[100000];

int cross(const point& o, const point& a, const point& b)
{
    return (a.x - o.x)*(b.y - o.y) - (a.y - o.y)*(b.x - o.x);
}

int monotone_chain()
{
    memset(result,0,sizeof(result));
    sort(point_set.begin(),point_set.end());
    int m = 0;
    for(int i = 0; i<point_set.size();i++) {
        while(m>=2&&cross(result[m-2],result[m-1],point_set[i])<=0) {
            m--;
        }
        result[m++] = point_set[i];
    }
    for(int i = point_set.size()-2, t=m+1;i>=0;i--) {
        while(m>=t&&cross(result[m-2],result[m-1],point_set[i])<=0) {
            m--;
        }
        result[m++] = point_set[i];
    }
    return m-1;
}


int main(void)
{
    int x0,y0;
    bool first = 0;
    int x,y;
    int m;
    char input[1000]={0};
    int case_num = 0;
    while(fgets(input,sizeof(input),stdin)!=0) {
        if(case_num) {
            puts("");
        }
        case_num++;
        sscanf(input,"%d, %d",&x0,&y0);
        struct point tmp;
        tmp.x = x0;
        tmp.y = y0;
        point_set.push_back(tmp);
        memset(input,0,sizeof(input));
        while(fgets(input,sizeof(input),stdin)!=0&&input[0]!='\n') {
            sscanf(input,"%d, %d",&x,&y);
            tmp.x = x;
            tmp.y = y;
            point_set.push_back(tmp);
            memset(input,0,sizeof(input));
        }
        ref.assign(point_set.begin(),point_set.end());
        m = monotone_chain();
        int pos = -1;
        for(int i = 0; i<ref.size()&&pos == -1; i++) {
            for(int j = 0;j<m;j++) {
                if(ref[i].x==result[j].x && ref[i].y == result[j].y) {
                    pos = j;
                    break;
                }
            }
        }
        for(int i = pos; i<m;i++) {
            printf("%d, %d\n",result[i].x,result[i].y);
        }
        for(int i =0;i<=pos;i++) {
            printf("%d, %d\n",result[i].x,result[i].y);
        }
        point_set.clear(); 
        ref.clear();
    }
    return 0;
}
