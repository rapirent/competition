#include <cstdio>
#include <iostream>

using namespace std;

int main(void)
{
    int a[1000] = {0},lis[1000]={0},num;
    scanf("%d",&num);
    for(int count=0;count<num;count++) {
        scanf("%d",&a[count]);
    }
    for(int i = 0;i<num;i++) {
        lis[i] = 1;
        for(int start = 0; start<i;start++) {
            if(a[start]>a[i]) {
                lis[i] = lis[start] + 1;
            }
        }
    }
    printf("123\n");
    for(int i = 0;i<num;i++) {
        printf("%d  ",lis[i]);
    }
    printf("\n");
    int max = 0;
    for(int i = 0;i<num;i++) {
        if(max <= lis[i]) {
            max = lis[i];
        }
    }
    printf("%d\n",max);
    return 0;
}
