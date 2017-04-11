#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

void fail(char B[], int pi[])
{
    int len = strlen(B);
    pi[0] = -1;
    int cur_pos = -1;
    for(int i = 1;i<len;i++) {
        while(~cur_pos&&B[i]!=B[cur_pos+1]) {
            //cur_pos除了第一個位置外都不是-1
            //我們要求最長「前綴」, 所以在讀完前面重複的部份前都會是-1
            //前面重複即B[i] == B[cur_pos+1], 代表當前讀到的B[i]和前面cur_pos+1重複
            //所以cur_pos!=-1(找到有重複的前綴)但是已經不能再和前面match時進入, 並且將cur_pos更新為最後一個match的元素陣列元素值
            //最前面可以被match的前綴字串的pi值都是-1
            //abzabzabc, 最前面abc都是-1
            cur_pos = pi[cur_pos];
        }
        if(B[i]==B[cur_pos+1]) {
            ++cur_pos;
            //一直等於, 那就cur_pos就一直加上去
        }
        //藉由上面兩個式子更新cur_pos
        pi[i] = cur_pos;
        //更新目前輔助陣列pi的元素值
    }
}

void match(char A[], char B[], char pi[])
{
    int len_A = strlen(A);
    int len_B = strlen(B);
    int cur_pos = -1;
    for(int i =1 ; i<len_A;i++) {
        while(~cur_pos && A[i] !=B[cur_pos+1]) {
            cur_pos = pi[cur_pos];
        }
        if(A[i]==B[cur_pos+1]) {
            cur_pos++;
        }
        if(cur_pos+1==len_B) {
            //match
            cur_pos = pi[cur_pos];
        }
    }
}


int main(void)
{
    
    return 0;
}
