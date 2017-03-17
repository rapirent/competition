#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>


using namespace std;

int limit;
int solution[15];
void backtrack(int index,int shu[],int now_shu)
{
    if(index==6) {
        for(int count=0;count<6;count++) {
            printf("%d",solution[count]);
        }
        printf("\n");
        return;
    }
    for(int count=index;count<limit;count++) {
        if(now_shu<solution[count]) {
            solution[index] = shu[count];
            backtrack(count+1,shu,shu[count]);
        }
    }
}

int main(void)
{
    int shu[15]={0};
    while(scanf("%d",&limit)&&limit!=0) {
        memset(shu,0,sizeof(shu));
        for(int count=0;count<limit;count++) {
            scanf("%d",&shu[count]);
        }
        sort(shu,shu+limit);
        backtrack(0,shu,-1);
    }
    return 0;
}
