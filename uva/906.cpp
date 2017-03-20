#include <cstdio>
#include <iostream>


using namespace std;


int main(void)
{
    const double epsilon = 1e-8;
    long long int a,b;
    while(scanf("%lld %lld",&a,&b)!=EOF) {
        double eps;
        scanf("%lf",&eps);
        long long int c,d=0;
        do{
            d++;
            c = (long double)a/(long double)b*d;
            while(a*d>=b*c) ++c;
        }while( ((long double)c/(long double)d - (long double)a / (long double)b ) > eps);
        printf("%lld %lld\n",c,d);
    }
    return 0;
}
