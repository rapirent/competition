#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int limit;
int solution[20]={0};
void backtrack(int index,int shu[],int print_count)
{
    if(print_count>=6) {
        printf("%d",solution[0]);
        for(int count=1;count<6;count++) {
            printf(" %d",solution[count]);
        }
        printf("\n");
        return;
    }
    for(int count=index;count<limit;count++) {
        solution[print_count] = shu[count];
        backtrack(count+1,shu,print_count+1);
    }
}

int main(void)
{
    int shu[15]={0};
    int printed = 0;
    while(scanf("%d",&limit)!=EOF&&limit!=0) {
        if(printed) {
            printf("\n");
        }
        memset(shu,0,sizeof(shu));
        for(int count=0;count<limit;count++) {
            scanf("%d",&shu[count]);
        }
        backtrack(0,shu,0);
        printed++;
        memset(solution,0,sizeof(solution));
    }
    return 0;
}
