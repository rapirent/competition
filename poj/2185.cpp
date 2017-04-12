#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;


int lem(int a,int b)
{
    int mux = a*b;
    int remind = a%b;
    while(remind) {
        a = b;
        b = remind;
        remind = a%b;
    }
    return mux / b;
}


int main(void)
{
    int r,c;
    char matrix[10100][80] = {0};
    int pi[10100] = {0};
    scanf("%d %d",&r,&c);
    for(int i = 0;i<r;i++) {
        scanf("%s",matrix[i]);
    }
    int cur_pos = -1;
    int period_2;
    int lem_row = 1,lem_col = 1;
    for(int j = 0;j<r;j++) {
        pi[0] = -1;
        cur_pos = -1;
        int i = 0;
        for(int i = 1;i<c;i++) {
            while(cur_pos!=-1&&matrix[j][i]!=matrix[j][cur_pos+1]) {
                cur_pos = pi[cur_pos];
            }
            if(matrix[j][i]==matrix[j][cur_pos+1]) {
                cur_pos++;
            }
            pi[i] = cur_pos;
        }

        period_2 = c - (pi[c-1]+1);
        lem_col = lem(lem_col,period_2);
        if(lem_col > c) {
            lem_col = c;
            break;
        }
    }
    cur_pos = -1;

    for(int j = 0;j<c;j++) {
        pi[0] = -1;
        cur_pos = -1;
        int i = 0;
        for(int i = 1;i<r;i++) {
            while(cur_pos!=-1&&matrix[i][j]!=matrix[cur_pos+1][j]) {
                cur_pos = pi[cur_pos];
            }
            if(matrix[i][j]==matrix[cur_pos+1][j]) {
                cur_pos++;
            }
            pi[i] = cur_pos;
        }
        period_2 = r- (pi[r-1] +1);
        lem_row = lem(lem_row,period_2);
        if(lem_row > r) {
            lem_row = r;
            break;
        }
    }
    printf("%d\n",lem_col * lem_row);
    return 0;
}
