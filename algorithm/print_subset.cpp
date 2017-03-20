#include <cstdio>
#include <iostream>
using namespace std;

void print_subset_kai_otsu(int n,int s) {
    for(int i = 0;i<n;i++) {
        if(s&(1<<i)) {//1 = 1*i
            printf("%d",i);
        }
    }
    printf("\n");
}

void print_subset_kai(int n, int matrix[], int cur)
{
    if(cur >= n){
        for(int i = 0; i< cur;i++) {
            if(matrix[i]!=0) {
                printf("%d ", i);
            }
        }
        printf("\n");
        return;
    }
    matrix[cur] = 1;
    print_subset_kai(n,matrix,cur+1);
    matrix[cur] = 0;
    print_subset_kai(n,matrix,cur+1);
}

void print_subset(int n, int matrix[], int cur)
{
    for(int i =0;i<cur;i++) {
        printf("%d ",matrix[i]);
    }
    printf("\n");
    //int s = cur;
    //不能這樣寫, 因為matrix[cur]有可能不是cur!!!
    int s = cur!=0?matrix[cur - 1] + 1:0;
    //如果cur=0，則是一開始的index，故不變，如果不是, 則將s指定成
    for(int i = s;i<n;i++){
        matrix[cur] = i;
        print_subset(n, matrix, cur+1);
    }
}

int main(void)
{
//    int A[3] = {0};
//    print_subset_kai_otsu(3,A,0);
    for(int i = 0; i< (1<<5);i++) {
        print_subset_kai_otsu(5,i);
    }
    return 0;
}
