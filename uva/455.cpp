#include <cstdio>
#include <iostream>
#include <cstring>

void fail(char b[],int pi[])
{
    int len = strlen(b);
    for(int a = 1,cur_pos=-1;a<len;a++) {
        while(cur_pos>=0&&b[a]!=b[cur_pos + 1]) {
            cur_pos = pi[cur_pos];
        }
        if(b[a] == b[cur_pos+1]) {
            cur_pos++;
        }
        pi[a] = cur_pos;
    }
}

int main(void)
{
    int repeat;
    scanf("%d",&repeat);
    int pi[100];
    char b[100];
    char a[100];
    int count;
    while(repeat--) {
        scanf("%s",a);
        for(count=1;count<strlen(a);count++) {
            memset(b,0,sizeof(b));
            strncpy(b,a,count);
            memset(pi,-1,sizeof(pi));
            fail(b, pi);            
        }
    }
    return 0;
}
