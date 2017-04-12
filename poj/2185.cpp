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
    char matrix[80][10002] = {0};
    int pi[10002];
    scanf("%d %d",&r,&c);
    for(int i = 0;i<r;i++) {
        scanf("%s",matrix[i]);
    }
    int cur_pos = -1;
    int period_2;
    int lem_row = 1,lem_col = 1;
    for(int j = 0;j<r;j++) {
        memset(pi,0,sizeof(pi));
        pi[0] = -1;
        cur_pos = -1;
        int i = 0;
        while(i<c) {
            if(cur_pos == -1||matrix[j][i] == matrix[j][cur_pos]) {
                i++;
                cur_pos++;
                pi[i] = cur_pos;
            }
            else {
                cur_pos = pi[cur_pos];
            }
        }

        period_2 = i - pi[i];
        lem_col = lem(lem_col,period_2);
        if(lem_col > c) {
            lem_col = c;
            break;
        }
    }
    cur_pos = -1;

    for(int j = 0;j<c;j++) {
        memset(pi,0,sizeof(pi));
        pi[0] = -1;
        cur_pos = -1;
        int i = 0;
        while(i<r) {
            if(cur_pos == -1 || matrix[i][j]==matrix[cur_pos][j]) {
                i++;
                cur_pos++;
                pi[i] = cur_pos;
            }
            else {
                cur_pos = pi[cur_pos];
            }
        }
        period_2 = i- pi[i];
        lem_row = lem(lem_row,period_2);
        if(lem_row > r) {
            lem_row = r;
            break;
        }
    }
    printf("%d\n",lem_col * lem_row);
    return 0;
}
