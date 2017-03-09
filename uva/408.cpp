#include <cstdio>
#include <iostream>

using namespace std;

int gcd(int a, int b )
{
    if (a == 0) return b;
    return gcd(b%a, a);
}


int main(void)
{
    int a,b;
    while(scanf("%d %d",&a,&b)!=EOF) {
        printf("%10d%10d    ",a,b);
        if(gcd(a,b)==1) {
            printf("Good Choice\n\n");
        }
        else {
            printf("Bad Choice\n\n");
        }
    }
    return 0;
}
