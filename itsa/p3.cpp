#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
    double t0 = 0,ti;
    int repeat;
    scanf("%d",&repeat);
    int i;
    const double c = 2.71828;
    while(repeat-->0) {
        t0 = 0;
        scanf("%lf,%d",&ti,&i);
        for(int count =1; count<=i;count++) {
            ti = ti + count*c;
        }
        printf("%.4lf\n",ti);
    } 
    return 0;
}
