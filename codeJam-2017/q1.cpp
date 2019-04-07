#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

void flip(char S[], int K)
{
    for(int i = 0;i<K;i++) {
        if(S[i]=='+') {
            S[i] = '-';
        }
        else {
            S[i] = '+';
        }
    }
}

int main(void)
{
    int repeat;
    scanf("%d",&repeat);
    char S[1100] = {0};
    int K;
    int flip_num = 0;
    int inpos = 0;
    for(int case_num = 1; case_num<=repeat;case_num++) {
        flip_num = 0;
        inpos = 0;
        memset(S,0,sizeof(S));
        for(int i = 0;i<1100;i++) {
            scanf("%c",&S[i]);
            if(S[i] == ' ') {
                S[i] = '\0';
                break;
            }
        }
        scanf("%d",&K);
        int len = strlen(S);
        for(int i = 0; i < len - (K - 1);i++) {
            if(S[i] == '-') {
                flip(&S[i],K);
                flip_num ++;                
            }
        }
        printf("Case #%d: ",case_num);
        for(int i = len - (K - 1); i<len;i++) {
            if(S[i]=='-') {
                printf("IMPOSSIBLE\n");
                inpos = 1;
                break;
            }
        }
        if(!inpos) {
            printf("%d\n",flip_num);
        }
    }
    return 0;
}
