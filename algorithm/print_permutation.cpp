//丁國騰
#include <cstdio>

using namespace std;

void print_permutation_kai(int n, int matrix_A[], int cur, int input_P[])
{
    if(cur >= n) {
        for(int i = 0; i < n ; ++i) {
            printf("%d ",matrix_A[i]);
        }
        printf("\n");
        return;
    }
    for(int i = 0; i<n ;i++) {
        if(!i||input_P[i]!=input_P[i-1]) {
            int count1 = 0,count2 = 0;
            for(int j =0; j<cur;j++) {
                if(matrix_A[j] == input_P[i]) {
                    count1++;
                }
            }
            for(int j = 0;j<n;j++) {
                if(input_P[j] == input_P[i]) {
                    count2++;
                }
            }
            if(count1<count2) {
                matrix_A[cur] = input_P[i];
                print_permutation_kai(n, matrix_A, cur+1, input_P);
            }
        }
    }
}

//生成1～n的排列
void print_permutaion(int n,int matrix_A[], int cur)
{
    if(cur >= n) {
        for(int i = 0;i<n; i++) {
            printf("%d",matrix_A[i]);
        }
        printf("\n");
        return;
    }
    for(int i = 1;i<=n;i++) {
        int ok = 1;
        for(int j =0;j<cur;j++) {
            if(matrix_A[j] == i) {
                ok = 0;
            } 
        }
        if(ok) {
            matrix_A[cur] = i;//新增到目前最後面
            print_permutaion(n,matrix_A, cur+1);//下次遞迴
        }
    }
}

int main(void)
{
    int P[5]={0,1,1,5,6};
    int A[5]={0};
    //print_permutaion(5,A,0);
    print_permutation_kai(5,A,0,P);
    return 0;
}
