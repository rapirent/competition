#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;


struct job{
    int num;
    int day;
    int t;
    double weight;
    bool operator<(const struct job& p){//其實是> 不過我懶得重刻
        return weight == p.weight ? num < p.num : weight > p.weight;
    }//因為相同權重時是看誰先輸入的 所以寫num < p.num 找出最小者
};


int main(void)
{
    //lexicographically. 字典順序, 題目是要我們印出最低順序(3在4前面, 若權重一樣)
    int total,test_num;
    job jobs[100100];
    long long int sum=0,ans=0;
    while(scanf("%d",&total)!=EOF){
        double fine;
        for(int input_shu=0;input_shu<total;input_shu++){
            scanf("%d %lf", &jobs[input_shu].day, &fine);
            jobs[input_shu].weight = fine/(double)jobs[input_shu].day;
            jobs[input_shu].t = (int)fine;
            jobs[input_shu].num = input_shu+1;
            sum+=jobs[input_shu].t;
        }
        sort(jobs,jobs+total);
        for(int input_shu=0;input_shu<total-1;input_shu++){
            sum-=jobs[input_shu].t;
            ans+=(sum*2*jobs[input_shu].day);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
