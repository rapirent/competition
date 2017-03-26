#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

bool backtracking(int index,int matrix[][10],int n)
{
    if(index>=n*n*n*n) {
        return true;
    }
    int x = index%(n*n);
    int y = index/(n*n);
    if(matrix[x][y]) {
        return backtracking(index+1,matrix,n);
    }
    int row[10] = {0},col[10] = {0}, box[10] = {0};
    for(int count= 0; count<n*n ; count++) {
        if(matrix[x][count]) {
            row[matrix[x][count]] = 1;
        }
        if(matrix[count][y]) {
            col[matrix[count][y]] = 1;
        }
    }
    for(int count=0; count<n;count++) {
        for(int count2=0;count2<n;count2++) {
            if( ( (x-x%n) + count) == x||((y-y%n) + count2)==y) {
                continue;
            } 
            if(matrix[(x - x%n) + count][(y - y%n) + count2]) {
                box[matrix[(x - x%n) + count][(y - y%n) + count2]] = 1;
            }
        }
    }
    for(int count = 1; count<=n*n; count++) {
        if(row[count]==0&&box[count]==0&&col[count]==0) {
            matrix[x][y]=count;
            if(backtracking(index+1,matrix,n)) {
                //有可能錯誤但不是真錯
                return true;
            }
            matrix[x][y]=0;
        }
    }
    return false;
}
int main(void)
{
    int n;
    int matrix[10][10] = {0};
    int printed = 0;
    while(scanf("%d",&n)!=EOF) {
        memset(matrix,0,sizeof(matrix));
        for(int count=0;count<n*n;count++) {
            for(int count2=0;count2<n*n;count2++) {
                scanf("%d",&matrix[count2][count]);
            }
        }
        if(printed==1) {
            printf("\n");
        }
        if(backtracking(0,matrix,n)==true) {
            for(int count=0;count<n*n;count++) {
                for(int count2=0;count2<n*n-1;count2++) {
                    printf("%d ",matrix[count2][count]);
                }
                printf("%d\n",matrix[n*n-1][count]);
            }
        }   
        else {
            printf("NO SOLUTION\n");
        }
        printed = 1;
    }
    return 0;
}
