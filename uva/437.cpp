#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

struct node {
    int x;
    int y;
    int length;
};
bool compare(node a, node b)
{
    if(a.x==b.x) {
        return a.y<b.y;
    }
    return a.x<b.x;
}
bool compare2(node a,node b)
{
    return a.x<b.x&&a.y<b.y;
}

int main(void)
{
    int case_num,input[3];
    vector<node> LIS;
    int repeat = 1;
    while(scanf("%d",&case_num)!=EOF&&case_num!=0) {
        for(int a=0;a<case_num;a++) {
            scanf("%d%d%d",&input[0],&input[1],&input[2]);
            sort(input,input+3);
            if(input[0]!=input[1]&&input[1]!=input[2]&&input[2]!=input[0]) {
                node tmp = {input[0],input[1],input[2]};
                LIS.push_back(tmp);
                tmp.x = input[0];
                tmp.y = input[2];
                tmp.length = input[1];
                LIS.push_back(tmp);
                tmp.x = input[1];
                tmp.y = input[2];
                tmp.length = input[0];
                LIS.push_back(tmp);
            }
            else if(input[0]!=input[1]) {
                //y==z
                node tmp = {input[0],input[1],input[2]};
                LIS.push_back(tmp);
                tmp.x = input[1];
                tmp.y = input[2];
                tmp.length = input[0];
                LIS.push_back(tmp);
            }
            else if(input[1]!=input[2]) {
                //x==z
                node tmp = {input[0],input[1],input[2]};
                LIS.push_back(tmp);
                tmp.x = input[0];
                tmp.y = input[2];
                tmp.length = input[1];
                LIS.push_back(tmp);
            }
            else {
                node tmp = {input[0],input[1],input[2]};
                LIS.push_back(tmp);
            }
        }
        sort(LIS.begin(),LIS.end(),compare);
        int max_num[100],max = -1;
        memset(max_num,-1,sizeof(max_num));
        for(int i = 0;i<LIS.size();i++) {
            max_num[i] = LIS[i].length;
            for(int j = 0;j<i;j++) {
                if(compare2(LIS[j],LIS[i])&&max_num[j] + LIS[i].length > max_num[i]) {
                    max_num[i] = max_num[j] + LIS[i].length;
                }
            }
            if(max_num[i]>max) {
                max = max_num[i];
            }
        }
        printf("Case %d: maximum height = %d\n",repeat++,max);
        LIS.clear();
    }
    return 0;
}
