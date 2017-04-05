#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int NOD[1000100] = {0};
int main(void)
{
    for(int i = 1;i<1000100;i++) {
        for(int tmp = i;tmp<100100;tmp+=i) {
            NOD[i]++;
        }
    }
    vector<int> n;
    n[0] = 1;
    for(int i = 1;i<100100;i++) {
        n.push_back(n.back() + NOD[n.back()]);
    }
    int input,input2;
    int repeat;
    scanf("%d",&repeat);
    int num = 1;
    while(repeat--) {
        scanf("%d%d",&input,&input2);
        printf("Case %d: %ld\n",num++,distance(lower_bound(n.begin(),n.end(), input),upper_bound(n.begin(),n.end(),input2)));
    }
    return 0;
}
