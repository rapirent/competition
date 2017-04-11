#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

void fail(char B[],int pi[])
{
    int len = strlen(B);
    pi[0] = -1;
    int cur_pos=-1;
    for(int i = 1;i<len;i++) {
        while(cur_pos!=-1&&B[i]!=B[cur_pos+1]) {
            cur_pos = pi[cur_pos];
        }
        if(B[i]==B[cur_pos+1]) {
            cur_pos++;
        }
        pi[i] = cur_pos;
    }
}


int main(void)
{
    char input[1000100] = {0};
    int pi[1000100] = {0};
    while(fgets(input,sizeof(input),stdin)!=0&&input[0]!='.') {
        int len = strlen(input) - 1;
        input[len] = '\0';//刪除\n
        fail(input,pi);
        if(pi[len-1]==-1||(len%(len - pi[len-1] - 1))) {
            printf("1\n");
        }
        else {
            printf("%d\n",len/(len - pi[len-1] - 1));
        }
        memset(input,0,sizeof(input[0])*len);
        memset(input,0,sizeof(pi[0])*len);
    }
    return 0;
}
