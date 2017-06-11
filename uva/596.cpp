#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct point{
    int x;
    int y;
    bool operator< (const point& a) const {
        return x < a.x || (x == a.x && y<a.y);
    }
};

vector<struct point> point_set;
struct point result[10000];
int cross(const point &o, const point &a, const point &b)
{
    return (a.x - o.x)*(b.y - o.y) - (a.y-o.y)*(b.x -o.x);
}

int Andrew_monotone(int limit)
{
    sort(point_set.begin(),point_set.begin()+limit);
    memset(result,0,sizeof(result));
    int m = 0;
    for(int i =0;i<limit;i++) {
        while(m>=2&&cross(result[m-2], result[m-1], point_set[i])<0) {
            m--;
        }
        result[m++] = point_set[i];
    }
    for(int i=limit-2, t=m+1;i>=0;i--) {
        while(m>=t&&cross(result[m-2],result[m-1],point_set[i])<0) {
            m--;
        }
        result[m++] = point_set[i];
    }
    return m-1;
}

int main(void)
{
    char input[100] = {0};
    int case_num;
    bool flag = 0;
    int m;
    int pos;
    int case_count = 0;
    while(fgets(input,sizeof(input),stdin)!=0) {
        if(input[0] == 'P') {
            flag = 1;
            char *tmp = strtok(input,"P ");
            sscanf(tmp,"%d",&case_num);
            for(int i = 0; i<case_num; i++) {
                struct point tmp_point;
                tmp = strtok(NULL," \n");
                sscanf(tmp,"%d",&tmp_point.x);
                tmp = strtok(NULL," \n");
                sscanf(tmp,"%d",&tmp_point.y);
                point_set.push_back(tmp_point);
            }
            memset(input,0,sizeof(input));
        }
        if(input[0] == 'S' && flag || input[0] == 'E' && flag) {
            flag = 0;
            int len = point_set.size();
            int j = 0;
            sort(point_set.begin(),point_set.end());
            for(int i = 1; i < len;i++) {
                if((point_set[j].x != point_set[i].x) || (point_set[j].y != point_set[i].y)) {
                    point_set[++j] = point_set[i];
                }
            }
            m = Andrew_monotone(j+1);
            //print
            pos = 0;
            for(int i = 0;i<m;i++) {
                if(result[i].x > result[pos].x || 
                    (result[i].x == result[pos].x && result[i].y < result[pos].y)) {
                    pos = i;
                }
            }
            for(int i = pos; i<m;i++) {
                printf(" (%d,%d)",result[i].x, result[i].y);
            }
            for(int i = 0;i < pos; i++) {
                printf(" (%d,%d)",result[i].x, result[i].y);
            }
            puts("");
            point_set.clear(); 
        }
        if(input[0] == 'S') {
            printf("%s convex hull:\n", strtok(input+2,"\n"));
            memset(input,0,sizeof(input));
        }
        if(input[0] == 'E') {
            break;
        }
 
    }
    return 0;
}
