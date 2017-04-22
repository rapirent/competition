#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
    int repeat;
    scanf("%d",&repeat);
    const double eps = 1e-8;
    while(repeat-->0) {
        double maxn = -1e9;
        double minn = 1e9;
        double tmp;
        for(int i = 0;i<10;i++) {
            scanf("%lf",&tmp);
            if(tmp - minn < - eps) {
                minn = tmp;
            }
            if(tmp - maxn >eps){
                maxn = tmp;
            }
        }
        printf("maximum:%.2lf\n",maxn);
        printf("minimum:%.2lf\n",minn);
    }
    return 0;
}
