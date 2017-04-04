#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>



using namespace std;

int main(void)
{
    int num;
    scanf("%d",&num);
    int input[50000] = {0};
    int LIS[50000] = {0};
    int p;
    while(num-->0) {
        memset(input,0,sizeof(input));
        memset(LIS,0,sizeof(LIS));
        scanf("%d",&p);
        for(int i = 0;i<p;i++) {
            scanf("%d",&input[i]);
        }
        vector<int> stack;
        stack.push_back(input[0]);
        for(int i = 1;i<p;i++) {
            int tmp = input[i];
            if(tmp>stack.back()) {
                stack.push_back(tmp);
            }
            else {
                *lower_bound(stack.begin(),stack.end(),tmp) = tmp;
            }
        }
        printf("%ld\n",stack.size());
    }
    return 0;
}

