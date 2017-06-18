#include <cstdio>
#include <iostream>

using namespace std;

int main(void)
{
    int num;
    scanf("%d",&num);
    int n,m;
    for(int case_num = 1;case_num<=num;case_num++) {
        printf("Scenario #%d:\n",case_num);
        scanf("%d %d",&n,&m);
        if(n%2 && m%2) {
            printf("%.2lf\n",(double)n*m + 1.414 - 1);
        }
        else {
            printf("%.2lf\n",(double)n*m);
        }
        puts("");
    }
    return 0;
}
