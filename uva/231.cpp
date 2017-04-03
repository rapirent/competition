#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int main(void)
{
    vector<int> input;
    int input_tmp;
    int trial_num = 1;
    while(scanf("%d",&input_tmp)!=EOF&&input_tmp!=-1) {
        if(trial_num!=1) {
            printf("\n");
        }
        input.clear();//也可以resize(0);
        input.push_back(input_tmp);
        while(scanf("%d",&input_tmp)!=EOF&&input_tmp!=-1) {
            input.push_back(input_tmp);            
        }
        vector<int> stack;
        stack.push_back(input.back());
        for(int i = input.size()-1;i>=0;i--) {
            int tmp = input[i];
            if(tmp>stack.back()) {
                stack.push_back(tmp);
            }
            else {
                *lower_bound(stack.begin(),stack.end(),tmp) = tmp;
            }
        }
        printf("Test #%d:\n",trial_num++);
        printf("  maximum possible interceptions: %ld\n",stack.size());
        stack.clear();
    }
    return 0;
}
