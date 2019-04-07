#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void) {
    int t;
    scanf("%d",&t);
    char num[100000];
    char discard;
    int gogo;
    char input;
    for(int i = 1;i<=t;i++) {
        memset(num,0,sizeof(num));
        scanf("%d",&gogo);
        while((discard=getchar())!=EOF&&discard!='\n');
        fgets(num,sizeof(num),stdin);
        int len = strlen(num) - 1;
        num[len] = '\0';
        printf("Case #%d: ",i);//Case #1: 2 2
        for (int i = 0;i<len;i++) {
            if(num[i]=='S') {
                printf("E");
            }
            else {
                printf("S");
            }
        }
        printf("\n");
    }
}
