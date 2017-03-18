#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
    long long int a,b;
    a=b=0;
    while(scanf("%lld %lld",&a,&b)!=EOF&&a!=0&&b!=0) {
        if(a>b) {
            long long int tmp = b;
            b = a;
            a = tmp;
        }
        printf("%lld\n",a*b*(b-1) + b*a*(a-1) 
                    + (b-a+1)*a*(a-1)*2
                    + 4*(a*(a-1)*(a-2)/6)*2);//朱世傑恆等(從3開始 然後加上1)

    }
    return 0;
}
