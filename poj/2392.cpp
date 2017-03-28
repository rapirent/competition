#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

struct node{
    int h,c,a;
};

bool compare(node a, node b) {
    return a.a < b.a;
}

int main(void)
{
    int k,sum,answer[1000000] = {0};
    while(scanf("%d",&k)!=EOF) {
        node tower[500];
        for(int i=0;i<k;i++) {
            scanf("%d %d %d",&tower[i].h,&tower[i].a,&tower[i].c);
        }
        sort(tower,tower+k,compare);
        memset(answer,0,sizeof(answer));
        for(int i = 0;i<k;i++) {
            for(int j = 0;j<tower[i].c;j++) {
                for(int m = tower[i].a;m>=tower[i].h;m--) {
                    answer[m] = max(answer[m],answer[m - tower[i].h] + tower[i].h);
                }
            }
        }
        int founded = 0;
        for(int i=0;i<=tower[k-1].a;i++) {
            if(founded < answer[i]) {
                founded = answer[i];
            }
        }
        printf("%d\n",founded);

    }
    return 0;
}
