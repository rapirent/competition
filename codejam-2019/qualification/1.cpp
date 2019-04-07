#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void)
{
    int t;
    scanf("%d",&t);
    char num1[100000];
    long long int num2;
    char discard;
    while((discard=getchar())!=EOF&&discard!='\n');
    for(int i = 1;i<=t;i++) {
        memset(num1,0,sizeof(num1));
        num2 = 0;
        fgets(num1,sizeof(num1),stdin);
        int len = strlen(num1) - 1;
        num1[len] = '\0';
        printf("Case #%d: ",i);//Case #1: 2 2
        for (int i = len-1;i>=0;i--) {
            if(num1[i]=='4') {
                num1[i] = '2';
                num2 += 2 * pow(10,len - 1 -i);
            }
        }
        printf("%lld ",num2);
        printf("%s\n", num1);
    }
}
