#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

queue<int> que;
void traversal(int i,int j, int depth[], int gold[], int anwser[][1200],int w)
{
    if(i==0||j==0) {
        return;
    }
    if(anwser[i][j] == anwser[i-1][j] ) {
        traversal(i-1,j,depth,gold,anwser,w);
        return;
    }
    traversal(i-1,j - depth[i-1]*3*w,depth,gold, anwser,w);
    que.push(i-1);
}
int main(void)
{
    int t,w,n;
    int print_line = 0;
    while(scanf("%d %d",&t,&w)==2) {
        scanf("%d",&n);
        if(print_line) {
            printf("\n");
        }
        print_line=1;
        int depth[50] = {0},gold[50] ={0};
        int anwser[50][1200] = {0};
        for(int count=0;count<n;count++) {
            scanf("%d %d",&depth[count],&gold[count]);
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<=t;j++) {
                if( j - depth[i]*3*w < 0 ) {
                    anwser[i+1][j] = anwser[i][j];
                }
                else {
                    anwser[i+1][j] = max(anwser[i][j] , (anwser[i][ j - depth[i]*3*w] + gold[i]));
                }
            }
        }
        printf("%d\n",anwser[n][t]);
        traversal(n,t,depth,gold,anwser,w);
        printf("%d\n",(int)que.size());
        while(!que.empty()) {
            int tmp = que.front();
            printf("%d %d\n",depth[tmp],gold[tmp]);
            que.pop();
        }
    }
    return 0;
}
