#include <cstdio>
#include <iostream>


using namespace std;


int main(void)
{
    const double epsilon = 1e-8;
    int a,b;
    while(scanf("%d %d",&a,&b)!=EOF) {
        double eps;
        scanf("%lf",&eps);
        long double a_divide_b = (long double)a/(long double)b;
        int c,d=0;
        do{
            d++;
            c = 1;
            //我試過用a/b < c/d 跟epsilon比較, 無效 QQ
            while (a*d >= c*b) {
                c++;
            }
        }while(a_divide_b - (long double)c / (long double)d <= eps);
        printf("%d %d\n",c,d);
    }
    return 0;
}
