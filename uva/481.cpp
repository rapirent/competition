#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>


using namespace std;

int main(void)
{
    int tmp;
    vector<int> input;
    while(scanf("%d",&tmp)!=EOF) {
        input.push_back(tmp);
    }
    if(input.size()==0) {
        printf("0\n");
    }
    else {
        vector<int> stack;
        stack.push_back(input[0]);
        int LIS[500000] = {0};
        LIS[0] = 1;
        for(int i = 1;i<input.size();i++) {
            int tmp_elemt = input[i];
            if(tmp_elemt>stack.back()) {
                stack.push_back(tmp_elemt);
                LIS[i] = stack.size();
            }
            else {
                LIS[i] = lower_bound(stack.begin(),stack.end(),tmp_elemt) - stack.begin() + 1;
                *lower_bound(stack.begin(),stack.end(),tmp_elemt) = tmp_elemt;
            }
        }
        printf("%ld\n-\n",stack.size());

        int index = stack.size();
        vector<int> print_queue;
        for(int i = input.size() - 1;i>=0&&index>=1;i--) {
            if(LIS[i]==index) {
                index--;
                print_queue.push_back(input[i]);
            }
        }
        for(int i = print_queue.size()-1;i>=0;i--) {
            printf("%d\n",print_queue[i]);
        }
    }
    return 0;
}
