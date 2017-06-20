#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int main(void)
{
    int case_num = 0;
    int num,query;
    int input;
    vector<int> input_set;
    vector<int>::iterator result;
    while(scanf("%d %d",&num,&query)!=EOF&&(num!=0||query!=0)) {
        printf("CASE# %d:\n",++case_num);
        input_set.clear();
        for(int i =0;i<num;i++) {
            scanf("%d",&input);
            input_set.push_back(input);
        }
        sort(input_set.begin(),input_set.end());
        for(int i=0;i<query;i++) {
            scanf("%d",&input);
            result = lower_bound(input_set.begin(),input_set.end(),input);
            if(result!=input_set.end()&&*result == input) {
                printf("%d found at %d\n",input,(int)(result - input_set.begin())+1);
            }
            else {
                printf("%d not found\n",input);
            }
        }
    }
    return 0;
}
