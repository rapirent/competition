#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int fail_row(char B[],int pi[],int len)
{
    int cur_pos = -1;
    pi[0] = -1;
    for(int i = 0;i<len;i++) {
        while(cur_pos!=-1&&B[cur_pos+1]!=B[i]) {
            cur_pos = pi[cur_pos];
        }
        if(B[i]==B[cur_pos+1]) {
            cur_pos++;
        }
        pi[i] = cur_pos;
    }
    return cur_pos;
}

int gcd(int a,int b)
{
    if(!a) {
        return b;
    }
    return gcd(b%a,a);
}


int main(void)
{
    int r,c;
    char matrix[80][10010];
    int pi[10010];
    while(scanf("%d %d",&r,&c)!=EOF) {
        memset(matrix,0,sizeof(matrix));
        for(int i = 0;i<r;i++) {
            for(int j = 0;j<c;j++) {
                scanf("%c",&matrix[i][j]);
            }
        }
        int period_1 = r - fail_row(matrix[r],pi,c) + 1, period_2;
        int lem = 1;
        for(int i = 1;i<r;i++) {
            memset(pi,0,sizeof(pi));
            period_2 = r - fail_row(matrix[r],pi,c) +1;
            int temp = period_1 * period_2/gcd(period_1,period_2);
            if(lem<temp) {
                lem = temp;
            }
        }
        memset(pi,0,sizeof(pi));
        pi[0] = -1;
        int cur_pos = -1;
        for(int i = 0;i<c;i++) {
            while(cur_pos!=-1&&matrix[i][0]!=matrix[cur_pos+1][0]) {
                cur_pos = pi[cur_pos];
            }
            if(matrix[i][0]==matrix[cur_pos+1][0]) {
                cur_pos++;
            }
            pi[i] = cur_pos;
        }
        cur_pos = c - cur_pos +1;
        printf("%d\n",cur_pos * lem);
    }
    return 0;
}
