#include <cstdio>
#include <iostream>

using namespace std;

int main(void)
{
    int C;
    int a,b,c;
    scanf("%d",&C);
    while(C--) {
        scanf("%d %d %d",&a,&b,&c);
        for(int i = 1;i<1000000;i++) {
            if((i-a)%7==0&&(i+b)%11==0&&(i-c)%17==0) {
                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}
