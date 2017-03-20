#include <cstdio>
#include <iostream>

using namespace std;


//插入排序在實現上，通常採用in-place排序（即只需用到O(1)的額外空間的排序）
// **排好的** | **還沒排好的** (往右增長
int main(void)
{
    int arry[10] = {1,2,3,4,5,6,7,8,9,10};
    for (int i=1; i<10; i++){//必須寫i=1因為假設第一個已經排好!!!!
        int tmp = arry[i];
        for(int j=i-1; j>=0; j--){//i-1因為是左邊！
            if(arry[j]>tmp){
                arry [j+1] = arry[j];
            }
            else{
                 arry[j+1] = tmp;
                break;
            }
        }
    }
    for(int i=0;i<10;i++){
        printf("%d ",arry[i]);
    }
    return 0;
}
