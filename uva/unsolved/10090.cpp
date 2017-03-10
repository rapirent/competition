#include <cstdio>
#include <iostream>

using namespace std;

int ex_gcd(int a, int b, int *x, int *y)
{
    if(b==0) {
        *x = 1;
        *y = 0;
        return a;
    }
    int gcd = ex_gcd(b, a%b, x, y);
    int tmp = *x;
    *x = *y;
    *y = tmp - (a/b)* *y;
}

int main(void)
{
    int marble;
    while(scanf("%d",&marble)&&marble!=0) {
        int n1,n2,c1,c2;
        scanf("%d %d %d %d",&c1,&n1,&c2,&n2);
        int x,y;
        int gcd = ex_gcd(n1,n2,&x,&y);
        printf("gcd = %d\n",gcd );
        if(x<0||y<0) {
            printf("failed\n");
            continue;
        }
        int new_x = x * marble / gcd, new_y = y * marble / gcd;
        printf("%d %d\n", x, y);
    }
    return 0;
}
