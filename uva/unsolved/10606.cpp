#include <cstdio>
#include <iostream>

using namespace std;

long long int ex_gcd (long long int a, 
                        long long int b,
                        long long int *x,
                        long long int *y) {
    if(b==0) {
        *x = 1, *y = 0;
        return a;
    }
    long long int gcd = ex_gcd(a,b,x,y);
    long long int tmp = *x;
    *x = *y;
    *y = tmp - b/a**y;
    return gcd;
}


int main(void)
{
    long long int input;
    long long int c1,c2,n1,n2;
    while (scanf("%ld",&input)&&input!=) {
        scanf("%ld %ld %ld %ld",&c1,&n1,&c2,&n2);
        long long int x, y, gcd = ex_gcd(n1,n2,&x,&y);
        if(input % gcd!=0) {
            printf("failed\n");
        }
        else {

        }
    }
    return 0;
}
