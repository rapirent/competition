#include <cstdio>
#include <iostream>

using namespace std;

void backtrack(int route[][6],int record[],int drawed,int node)
{
    record[drawed] = node;
    if(drawed>=9) {
        for(int a = 1;a<=9;a++) {
            printf("%d",record[a]);
        }
        printf("\n");
        return;
    }
    for(int a = 1;a<=5;a++) {
        if(route[node][a] == 1) {
            //可走
            route[node][a] = route[a][node] = 0;
            backtrack(route,record,drawed+1, a);
            route[node][a] = route[a][node] = 1;
        }
    }
}


int main(void)
{
    int route[6][6] ={0};
    route[1][2] = 1;
    route[1][3] = 1;
    route[1][5] = 1;
    route[2][1] = 1;
    route[2][3] = 1;
    route[2][5] = 1;
    route[3][1] = 1;
    route[3][2] = 1;
    route[3][5] = 1;
    route[3][4] = 1;
    route[5][1] = 1;
    route[5][2] = 1;
    route[5][3] = 1;
    route[5][4] = 1;
    route[4][5] = 1;
    route[4][3] = 1;
    int record[10] = {0};
    backtrack(route,record,1,1);
    return 0;
}
