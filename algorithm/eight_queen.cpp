#include <cstdio>
using namespace std;

bool matrix_y[8], matrix_xie[15], matrix_xie2[15];
int solution[8]={0};
int matrix[3][30] = {0};
int count=0;
int solution_kai[8][100] = {0};
void search_kai(int x)
{
    if(x>=8){
        printf("count=%d\n",count);
        for(int a=0;a<8;a++) {
            printf("x=%d y=%d\n",a,solution_kai[a][count]);
        }
        printf("\n");
        count++;
        return;
    }
    for(int y = 0;y<8;y++) {
        if(!matrix[0][y]&&!matrix[1][x+y]&&!matrix[2][x-y+15]) {
            solution_kai[x][count] = y;
            matrix[0][y] = matrix[1][x+y] = matrix[2][x-y+15] = 1;
            search_kai(x+1);
            matrix[0][y] = matrix[1][x+y] = matrix[2][x-y+15] = 0;
        }
    }
}

void search(int x)
{
    if(x>=8) {
        for(int a=0;a<8;a++) {
            printf("x=%d y=%d\n",a,solution[a]);
        }
        printf("\n");
        return;
    }
    for(int y = 0;y<8;y++) {
        int xie = (x+y)%15, xie2 = (x-y+15)%15;
        if(!matrix_y[y]&&!matrix_xie[xie]&&!matrix_xie2[xie2]) {
            matrix_y[y] = matrix_xie[xie] = matrix_xie2[xie2] = true;
            solution[x] = y;
            search(x+1);
            matrix_y[y] = matrix_xie[xie] = matrix_xie2[xie2] = false;
        }
    }
}


int main(void)
{
    search_kai(0);
    return 0;
}
