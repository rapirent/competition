#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;



void backtracking(int y, int matrix[][10], int n)
{
    if(y>=n*n) {
        return;
    }
    int col[10] = {0}, row[10] = {0}, nine[10] = {0};
    int x;
    for(int count_y=0;count_y<n*n;count_y++) {
        if(matrix[county][])
    }
    for(x=0;x<n*n;x++)
        if(matrix[x][y]) {
            row[x] = 1;
        }
        else {
            
        }
    }
    if(x==n*n) {
        return;
    }
    for(int count_x=0;count_x<=n*n)
}

int main(void)
{
    int n;
    int matrix[10][10] = {0};

    while (scanf("%d",&n) != EOF) {
        memset(matrix,0,sizeof(matrix));
        for(int count=0;count<n;count++) {
            for(int count2=0;count2<n;count2++) {
                scanf("%d",&matrix[count2][count]);
            }
        }
        int col[10]={0},row[10] = {0};
    }
    
    return 0;
}
