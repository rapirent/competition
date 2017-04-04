#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
    char input1[1500] = {'\0'};
    char input2[1500] = {'\0'};
    int LCS[1050][1050] = {0};
    while(fgets(input1+1,1050,stdin)!=0) {
        fgets(input2+1,1050,stdin);
        memset(LCS,0,sizeof(LCS));
        int maxn = -1;
        if(strlen(input1+1)==1||strlen(input2+1)==1) {
            printf("0\n");
            continue;
        }
        for(int i = 1;i<strlen(input1+1);i++) {
            for(int j = 1;j<strlen(input2+1);j++) {
                if(input1[i]==input2[j]) {
                    LCS[i][j] = LCS[i-1][j-1]+1;
                }
                else {
                    LCS[i][j] = max(LCS[i-1][j],LCS[i][j-1]);
                }
                if(maxn<LCS[i][j]) {
                    maxn = LCS[i][j];
                }
            }
        }
        printf("%d\n",maxn);
        memset(input1,0,sizeof(input1));
        memset(input2,0,sizeof(input2));
    }
    return 0;
}
