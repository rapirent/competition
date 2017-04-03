#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
    int num,tmp;
    int answer[30] = {0};
    scanf("%d",&num);//只會輸入一個啦= =因為它根本辨別不出來
    memset(answer,-1,sizeof(answer));
    for(int a = 1;a<=num;a++) {
        scanf("%d",&tmp);
        answer[tmp] = a;
    }
    int trial[30] ={0};
    int LCS[30][30] = {0};
    while(scanf("%d",&tmp)!=EOF) {
        memset(trial,-1,sizeof(trial));
        trial[tmp] = 1;
        for(int a = 2;a<=num;a++) {
            scanf("%d",&tmp);
            trial[tmp] = a;
        }
        memset(LCS,0,sizeof(LCS));
        int max_num = -1;
        for(int i = 1;i<=num;i++) {
            for(int trial_trav = 1;trial_trav<=num; trial_trav++) {
                if(trial[trial_trav] == answer[i]) {
                    LCS[i][trial_trav] = LCS[i-1][trial_trav] + 1;
                }
                else {
                    LCS[i][trial_trav] = max(LCS[i-1][trial_trav],LCS[i][trial_trav-1]);
                }
                if(LCS[i][trial_trav]>max_num) {
                    max_num = LCS[i][trial_trav];
                }
            }
        }
        printf("%d\n",max_num);
    }
    return 0;
}
