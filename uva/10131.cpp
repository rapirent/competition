#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

struct node {
    int telgent;
    int weight;
    int num;
};

void print(int pre_trav[] , int index, node elephant[])
{
    if(index==-1) {
        return;
    }
    print(pre_trav,pre_trav[index],elephant);
    printf("%d\n",elephant[index].num);
}


bool compare(node a,node b)
{
    return a.weight<=b.weight;
}

int main(void)
{
    node elephant[2000];
    int a,b;
    int case_num = 0;
    while(scanf("%d%d",&a,&b)!=EOF) {
        elephant[case_num].weight = a;
        elephant[case_num].telgent = b;
        elephant[case_num].num = case_num+1;
        case_num++;
    }
    sort(elephant,elephant+case_num,compare);
    int LIS[1500] = {0};
    int pre_trav[1500] = {0};
    memset(pre_trav,-1,sizeof(pre_trav));
    int maxn = -1;
    int maxn_index = 0;
    for(int a = 0; a<case_num;a++) {
        LIS[a] = 1;
        for(int b = 0;b<a;b++) {
            if((elephant[b].weight<elephant[a].weight)
                &&(elephant[b].telgent>elephant[a].telgent)
                &&LIS[b]+1>LIS[a]) {
                LIS[a] = LIS[b] + 1;
                pre_trav[a] = b;
            }
        }
        if(maxn<LIS[a]) {
            maxn = LIS[a];
            maxn_index = a;
        }
    }
    printf("%d\n",maxn);
    print(pre_trav,maxn_index,elephant);
    return 0;
}
