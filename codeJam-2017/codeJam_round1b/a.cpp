#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
    int repeat;
    scanf("%d",&repeat);
    double dest;
    int horse;
    double time = 0.0,max_time = 0.0;
    double eps = 1e-8;
    for(int case_num = 1;case_num<=repeat;case_num++) {
        scanf("%lf %d",&dest,&horse);
        max_time = 0;
        for(int i = 0;i<horse;i++) {
            double x,y;
            scanf("%lf %lf",&x,&y);
            time = ((double)dest - (double)x)/(double)y;
            if((time - max_time)>eps) {
                max_time = time;
            }
        }
        printf("Case #%d: %.6lf\n",case_num,dest/max_time);
    }
    return 0;
}
