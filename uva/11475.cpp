#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

//乾, Z algorithm TLE!!!!!

void fail(char B[],int pi[]) {
    int len = strlen(B),cur_pos = -1;
    pi[0] = -1;
    for(int i = 1;i<len;i++) {
        while(cur_pos!=-1&&B[cur_pos+1]!=B[i]) {
            cur_pos = pi[cur_pos];
        }
        if(B[cur_pos+1]==B[i]) {
            cur_pos++;
        }
        pi[i] = cur_pos;
    }
}

int main(void)
{
    char input[100100] = {0};
    char reverse[100100] = {0};
    int  pi[100100] = {0};
    while(fgets(input,sizeof(input),stdin)!=0) {
        int len = strlen(input) -1;
        input[len] = '\0';
        memcpy(reverse,input,sizeof(input));
        for(int i = 0;i<len/2;i++) {
            reverse[i]^=reverse[len - 1 -i]^=reverse[i]^=reverse[len - 1 -i];
        }
        printf("%s",input);
        fail(reverse,pi);
        int count = -1;
        for(int i = 0;i<len;i++) {
            while(count!=-1&&input[i]!=reverse[count+1]) {
                count = pi[count];
            }
            if(input[i] == reverse[count+1]) {
                count ++;
            }
        }
        for(int i = count+1;i< len ;i++) {
            printf("%c",reverse[i]);
        }
        printf("\n");
        /*
        if(count + 1 < len-1) {
            printf("%s\n",reverse + count + 1);
        }*/
        memset(input,0,sizeof(input));
        memset(pi,0,sizeof(pi));
    }
    return 0;
}
