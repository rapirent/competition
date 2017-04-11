#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
    char input[1000010] = {0};
    int     pi[1000010] = {0};
    int len;
    int case_num = 1;
    char discard;
    while(scanf("%d",&len)!=EOF&&len!=0) {
        //fflush(stdin);
        while((discard=getchar())!='\n'&&discard!=EOF);
        fgets(input,sizeof(input),stdin);
        input[len] = '\0';
        int cur_pos = -1;
        pi[0] = -1;
        printf("Test case #%d\n",case_num++);
        for(int i = 1;i<len;i++) {
            while(cur_pos!=-1&&input[cur_pos+1]!=input[i]) {
                cur_pos = pi[cur_pos];
            }
            if(input[i] == input[cur_pos+1]) {
                cur_pos++;
            }
            pi[i] = cur_pos;
            //求後面字串中跟前面字串重複的字串長度
            if((cur_pos+1)&&(i+1)%(i - cur_pos)==0) {
                printf("%d %d\n",i+1,(i+1)/(i - cur_pos));
            }
        }
        memset(input,0,sizeof(input));
        memset(pi,0,sizeof(pi));
        printf("\n");
    }
    return 0;
}
