#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    int input_num;
    scanf("%d",&input_num);
    int input[60000] = {0};
    for(int i = 0;i<input_num;i++) {
        scanf("%d",&input[i]);
    }
    sort(input,input+input_num);
    int quest_num;
    scanf("%d",&quest_num);
    int target;
    while(quest_num-->0) {
        scanf("%d",&target);
        int minn = 0,maxn = input_num-1;
        int find = -1;
        while(minn<=maxn) {
            int mid = (minn + maxn) /2;
            if(input[mid]<target) {
                minn = mid + 1;
            }
            else if(input[mid]>target) {
                maxn = mid - 1;
            }
            else {
                find = mid;
                break;
            }
        }
        if(find!=-1) {
            int last = find;
            while(last>=0&&input[last]==target) {
                last--;
            }
            if(last>=0&&input[last]!=target) {
                printf("%d ",input[last]);
            }
            else {
                printf("X ");
            }
            int first = find;
            while((first<=input_num-1)&&input[first]==target) {
                first++;
            }
            if((first<= input_num - 1)&&input[first]!=target) {
                printf("%d\n",input[first]);
            }
            else {
                printf("X\n");
            }
        }
        else {
            if(maxn>=0) {
                if(input[maxn]==91) {
                    printf("maxn = %d\n",maxn);
                }
                printf("%d ",input[maxn]);
            }
            else {
                printf("X ");
            }
            if(minn<=input_num - 1) {
                printf("%d\n",input[minn]);
            }
            else {
                printf("X\n");
            }
        }

    }
    return 0;
}
