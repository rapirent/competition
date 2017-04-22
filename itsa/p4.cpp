#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
    int repeat;
    scanf("%d",&repeat);
    int r,c;
    int matrix1[20][20],matrix2[20][20],result[20][20];
    while(repeat-->0) {
        scanf("%d %d",&r,&c);
        memset(matrix1,0,sizeof(matrix1));
        memset(matrix2,0,sizeof(matrix2));
        memset(result,0,sizeof(result));
        int index1,index2,tmp;
        char discard;
        fflush(stdin);
        for(int i =0;i<c;i++) {
            discard = getchar();
            discard = getchar();
            scanf("%d",&index1);
            discard = getchar();
            scanf("%d",&index2);
            discard = getchar();
            discard = getchar();
            scanf("%d",&tmp);
            matrix1[index1-1][index2-1] = tmp;
            matrix2[index2-1][index1-1] = tmp;
            fflush(stdin);
        }
         
        for(int i = 0;i<r;i++) {
            for(int j = 0;j<r;j++) {
                result[i][j] = 0;
                for(int i1 = 0;i1<r;i1++) {
                    result[i][j] += matrix1[i][i1]*matrix2[i1][j];
                }
                printf("%d",result[i][j]);
                if(j<r-1) {
                    printf(" ");
                }
                else {
                    printf("\n");
                }
            }

        }
    }
    return 0;
}

