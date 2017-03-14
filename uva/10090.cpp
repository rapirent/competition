#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;


long long int ex_gcd(long long int a,long long int b,long long  int *x,long long int *y)
{
    if(b==0) {
        *x = 1;
        *y = 0;
        return a;
    }
    long long int gcd = ex_gcd(b, a%b, x, y);
    long long int tmp = *x;
    *x = *y;
    *y = tmp - (a/b)* *y;
    return gcd;
}

int main(void)
{
    long long int marble;
    while(scanf("%lld",&marble)&&marble!=0) {
        long long int n1,n2,c1,c2;
        scanf("%lld %lld %lld %lld",&c1,&n1,&c2,&n2);
        long long int x,y;
        long long int gcd = ex_gcd(n1,n2,&x,&y);
        
        if(marble%gcd!=0) {
            printf("failed\n");
            continue;
        }
        //exgcd可以解不定方程, 如果不能整除(倍數關係)則無解
        long long int new_x = x * (marble/gcd);
        long long int new_y = y * (marble/gcd);
        long long int low_bound = ceil(-(double)new_x*gcd/n2),
                    up_bound = floor((double)new_y*gcd/n1);
        if(low_bound>up_bound) {
            printf("failed\n");
            continue;
        }
        //n1*x' +n2*y' = gcd , n1*(x*marble/gcd) + n2*(y*marble/gcd) = gcd*marble/gcd = marble
        //n1*x + n2*y = marble
        //m1 = m1 + n2 / g * t  , m2 = m2 –  n1 / g * t  
        //x'' = x + n2 / gcd *t, y'' = y - n1 / gcd *t ''代表最終決定值
        //new_x、new_y
        long long int cost = (c1 * n2 - c2 * n1)/gcd;
        //cost = c1* x'' + c2 * y'' = c1*(x + n2/gcd*t) + c2*(y - n1/gcd*t)
        //      = (c1*x+c2*y)+(c1*n2 - c2*n1)/gcd*t
        if(cost * low_bound > cost * up_bound) {
            //found t!!!
            new_x = new_x + (n2/gcd) * up_bound;
            new_y = new_y - (n1/gcd) * up_bound;
        }
        else {
            new_x = new_x + (n2/gcd) * low_bound;
            new_y = new_y - (n1/gcd) * low_bound;
        }
        printf("%lld %lld\n", new_x, new_y);
    }
    return 0;
}
