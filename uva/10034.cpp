#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;

struct node {
    double x,y;
};

int main(void)
{
    int repeat;
    scanf("%d",&repeat);
    const double eps = 1e-8;
    while(repeat--) {
        char discard;
        while((discard=getchar())!=EOF&&discard!='\n');
        int num;
        scanf("%d",&num);
        vector<struct node>vec;
        double sum=0.0;
        
        while(num--) {
            double x,y;
            scanf("%lf%lf",&x,&y);
            double min=1e9;
            int flag = 1;
            for(int i = 0;i<vec.size();i++) {
                double tmp = sqrt(pow((x-vec[i].x),2)+pow((y-vec[i].y),2));
                if((min - tmp)>eps) {
                    flag = 0;
                    min = tmp;
                }
            }
            struct node tmp_node;
            tmp_node.x = x;
            tmp_node.y = y;
            vec.push_back(tmp_node);
            if(!flag) {
                sum += min;
            }
        }
        printf("%.2lf\n",sum);
    }
    return 0;
}
