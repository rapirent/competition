#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<int> gogo;

int gcd (int x,int y) {
    if(y==0) {
        return x;
    }
    return gcd (y,x%y);
}

int main(void)
{
    int input1;
    while( scanf("%d",&input1)==1&&input1!=0 )
    {
        int input,ans=0;
        while(scanf("%d",&input)==1&&input!=0) {
            ans = gcd(abs(input1 - input),ans);
        }
        printf("%d\n",ans);
    }
    return 0;
}
