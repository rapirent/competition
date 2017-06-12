#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> result;

int main(void)
{
    int case_num;
    int input_num;
    while(scanf("%d",&case_num)!=EOF && case_num!=0) {
        result.clear();
        for(int i = 0;i<case_num;i++) {
            scanf("%d",&input_num);
            result.push_back(input_num);
        }
        sort(result.begin(),result.end());
        for(int i = 0;i<(int)result.size();i++) {
            if(i) {
                printf(" ");
            }
            printf("%d",result[i]);
        }
        puts("");
    }
    return 0;
}
