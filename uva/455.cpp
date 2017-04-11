#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;


int main(void)
{
    int repeat;
    scanf("%d",&repeat);
    int count;
    char discard;
    char input[1000] = {0};
    while(repeat-->0) {
        while((discard=getchar())!=EOF&&discard!='\n');
        memset(input,0,sizeof(input));
        scanf("%s",input);
        int length = 1;
        int fail = 0,printed = 0;
        int i,j = 0;
        int string_len=strlen(input);
        for(;length<string_len;length++) {
            if(string_len%length) {
                continue;
            }
            for(i = 0;i<length;i++) {
                for(j = i + length;j<string_len;j = j+length) {
                    fail = 0;
                    if(input[i]!=input[j]) {
                        fail = 1;
                        break;
                    }
                }
                if(fail==1) {
                    break;
                }
            }
            if(fail==0) {
                printed = 1;
                printf("%d\n",length);
                break;
            }
        }
        if(printed==0) {
            printf("%ld\n",strlen(input));
        }
        if(repeat) {
            printf("\n");
        }
    }
    return 0;
}
