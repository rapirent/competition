#include <cstdio>
#include <iostream>
#include <cstring>


using namespace std;

int main(void)
{
    int T;//repeat
    scanf("%d",&T);
    int p[1000],w[1000];
    int answer[10000];
    int E,F,repeat_times;
    const int large = 1e9;
    while(T--) {
        scanf("%d %d",&E,&F);
        scanf("%d",&repeat_times);
        memset(p,0,sizeof(p));
        memset(w,0,sizeof(w));
        for(int a = 0; a<repeat_times;a++) {
            scanf("%d %d",&p[a],&w[a]);
        }
        for(int a = 0; a<sizeof(answer)/sizeof(answer[0]); a++) {
            answer[a] = large;
        }
        answer[0] = 0;
        for(int i = 0;i<repeat_times;i++) {
            for(int j = 0;(j + w[i])<=(F-E);j++) {
                answer[j + w[i]] = min(answer[j + w[i]],answer[j] + p[i]);
            }
        }
        if(answer[F-E]==large) {
            printf("This is impossible.\n");
        }
        else {
            printf("The minimum amount of money in the piggy-bank is %d.\n",answer[F-E]);
        }
    }
    return 0;
}
