#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

void fail(char B[],int pi[]) {
    int len = strlen(B);
    pi[0] = -1;
    int cur_pos = -1;
    for(int i = 1;i<len;i++) {
        while(cur_pos!=-1&&B[i]!=B[cur_pos+1]) {
            cur_pos = pi[cur_pos];
        }
        if(B[i] == B[cur_pos +1]) {
            cur_pos++;
        }
        pi[i] = cur_pos;
    }
}

int main(void)
{
    int repeat;
    scanf("%d",&repeat);
    char input[10010];
    char input2[1000010];
    int pi[10010];
    while(repeat-->0) {
        memset(input,0,sizeof(input));
        memset(input2,0,sizeof(input2));
        memset(pi,0,sizeof(pi));
        scanf("%s",input);
        scanf("%s",input2);
        fail(input,pi);
        int len_b = strlen(input);
        int len_a = strlen(input2);
        int cur_pos = -1,print_count = 0;
        for(int i = 0;i<len_a;i++) {
            while(cur_pos!=-1&&input[cur_pos+1]!=input2[i]) {
                cur_pos = pi[cur_pos];
            }
            if(input[cur_pos+1]==input2[i]) {
                cur_pos++;
            }
            if(cur_pos+1==len_b) {
                print_count++;
                cur_pos = pi[cur_pos];
            }
        }
        printf("%d\n",print_count);
    }
    return 0;
}
