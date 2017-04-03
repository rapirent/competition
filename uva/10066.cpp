#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main(void)
{
    int h1,h2;
    int tower1[200], tower2[200];
    int LCS[200][200];
    int case_num = 1;
    while(scanf("%d%d",&h1,&h2)==2&&h1&&h2) {
        memset(tower1,0,sizeof(tower1));
        memset(tower2,0,sizeof(tower2));
        
        for(int a = 1; a<=h1;a++) {
            scanf("%d",&tower1[a]);
        }
        for(int a = 1;a<=h2;a++) {
            scanf("%d",&tower2[a]);
        }
        memset(LCS,0,sizeof(LCS));
        int max_num = -1;
        for(int i = 1;i<=h1;i++) {
            for(int j = 1; j <=h2;j++) {
                if(tower1[i]==tower2[j]) {
                    LCS[i][j] = LCS[i-1][j-1]+1;
                }
                else {
                    LCS[i][j] = max(LCS[i-1][j],LCS[i][j-1]);
                }
                if(LCS[i][j]>max_num){
                    max_num = LCS[i][j];
                }
            }
        }
        printf("Twin Towers #%d\n",case_num++);
        printf("Number of Tiles : %d\n\n",max_num);

    }
    return 0;
}
