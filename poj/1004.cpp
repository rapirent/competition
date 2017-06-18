#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
    double sum=0;
    double input;
    for(int i = 0;scanf("%lf",&input)!=EOF&&i<12;i++) {
        sum+=input;
    }
    printf("$%.2lf\n",sum/12);
    return 0;
}
