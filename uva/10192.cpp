#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
    char input1[200] = {'\0'};
    char input2[200] = {'\0'};
    int LCS[150][150] = {0};
    int case_num = 1;
    while(fgets(input1+1,105,stdin)!=0) {
        if(input1[1] == '#') {
            break;
        }
        fgets(input2+1,105,stdin);
        memset(LCS,0,sizeof(LCS));
        int maxn = -1;
        for(int i = 1;i<strlen(input1+1);i++) {
            for(int j = 1;j<strlen(input2+1);j++) {
                if(input1[i]==input2[j]) {
                    LCS[i][j] = LCS[i-1][j-1] + 1;
                }
                else {
                    LCS[i][j] = max(LCS[i-1][j],LCS[i][j-1]);
                }
                if(LCS[i][j]>maxn) {
                    maxn = LCS[i][j];
                }
            }
        }
        printf("Case #%d: you can visit at most %d cities.\n",case_num++,maxn == -1?0:maxn);
    }
    return 0;
}
