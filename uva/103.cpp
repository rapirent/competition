#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

struct BOX{
    int contain[100];
    int num;//編號
};

void stack(vector<BOX> box, int pre_index[] , int index)
{
    if(index == -1) {
        return;
    }
    stack(box,pre_index,pre_index[index]);
    printf("%d ",box[index].num);
}

bool compare(BOX a,BOX b)
{
    return a.contain[0]<b.contain[0];
}

int isContain(BOX b,BOX a,int n) {
    for(int num = 0;num<n;num++) {
        if(b.contain[num]>=a.contain[num]) {
            return 0;
        }
    }
    return 1;//b的元素全部小於a
}

int main(void)
{
    int k,n;
    while(scanf("%d%d",&k,&n)==2) {
        vector<BOX> box;
        for(int a = 0;a<k;a++) {
            BOX tmp;
            for(int b = 0; b<n;b++) {
                scanf("%d",&(tmp.contain[b]));
            }
            sort(tmp.contain,tmp.contain+n);
            tmp.num = a+1;
            box.push_back(tmp);
        }
        
        sort(box.begin(),box.end(),compare);
        int contain_index[50] = {0};
        int pre_index[50] = {0};
        fill(pre_index,pre_index+50,-1);
        fill(contain_index,contain_index+50,1);
        for(int a = 0;a<k;a++) {
            for(int b = 0;b<a;b++) {
                if(isContain(box[b],box[a],n)==1&&(contain_index[b] + 1>contain_index[a])) {
                    contain_index[a] = contain_index[b] + 1;
                    pre_index[a] = b;
                }
            }
        }        
        int max_num = -1;
        int index;
        for(int trav = 0;trav<k;trav++) {
            if(max_num<contain_index[trav]) {
                max_num = contain_index[trav];
                index = trav;
            }
        }
        
        printf("%d\n",max_num);
        int tag;
        stack(box,pre_index,pre_index[index]);
        printf("%d\n",box[index].num);
    }
    return 0;
}
