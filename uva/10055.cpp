#include <cstdio>
#include <cmath>
#include <cstdlib>

int main(void)
{
    long long int a,b;
    while(scanf("%lld %lld",&a,&b)!=EOF) {
        printf("%lld\n",llabs(a-b));
    }
    return 0;
}
