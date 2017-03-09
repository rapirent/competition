#include <cstdio>
#include <iostream>

using namespace std;

int main(void){
    int num;
    scanf("%d", &num);
    int casenum = 0,cal,fah;
    while(casenum++<num)
    {
        scanf("%d %d",&cal,&fah);
        double real_cal = (double)fah* 5 / 9;
        printf("Case %d: %.2lf\n",casenum,(double)cal +real_cal);
    }
    return 0;
}
