#include <cstdio>
#include <iostream>
#include <algorithm>


using namespace std;


int main(void)
{
    int array[10000] = {0}, index=0;
    while (scanf("%d",&array[index])!=EOF){
        sort(array, array+index+1);
        if( index%2 == 0 ){//median = 中位數
            printf("%d\n", array[index/2]);//因為起始點為0 所以在算中位數的時候可以直接/2 而得中間 （不然應該要相反 index%2 ==0 得兩兩平均） 
        }
        else{
            printf("%d\n", (array[index/2] + array[index/2 + 1])/2);//because the array start from 0
        }
        index++;
    }
    return 0;
}
