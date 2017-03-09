#include <cstdio>
#include <iostream>

using namespace std;

long long int merge(int array[],int l, int r, int med)
{
    int index_left = l, index_right = med +1,
        index_tmp = 0;
    int *tmp = new int[r-l+1];
    if (!tmp){
        cerr << "error" << endl;
        return 0;
    }
    long long int distance=0;
    while (index_left <= med && index_right <= r){
        if (array[index_left] <= array[index_right]){
            tmp[index_tmp++] = array[index_left++];
        }
        else{
            tmp[index_tmp++] = array[index_right++];
            //計算距離
            distance+=med-index_left+1;
        }
    }
    while (index_left <= med){
        tmp[index_tmp++] = array[index_left++];
    }
    while (index_right <= r){
        tmp[index_tmp++] = array[index_right++];
    }
    for (int i = l; i<=r; i++){
        array[i] = tmp[i-l];
    }
    delete []tmp;
    return distance;
}


long long int merge_sort(int array[],int l,int r)
{
    if(l<r&&array!=NULL){
        int med = (l+r)/2;
        long long int i = merge_sort(array,l,med);
        long long int j = merge_sort(array,med+1,r);
        long long int k = merge(array,l,r,med);
        return i+j+k;
    }
    return 0;
}



int main(void)
{
    int total=0;
    int array[500000]={0};
    while(scanf("%d",&total)&&total!=0){
        for(int a=0;a<total;a++){
            scanf("%d",&array[a]);
        }
        printf("%lld\n",merge_sort(array,0,total-1));
    }
    return 0;
}
