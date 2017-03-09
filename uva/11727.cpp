#include <cstdio>
#include <iostream>

using namespace std;

int main(void){
    int num;
    scanf("%d", &num);
    int a[3];
    int number = 0;
    while(number++<num){
        int max = 999, min = 10001, max_num, min_num;
        for(int count =0;count<3;count++){
            scanf("%d",&a[count]);
            if(max <= a[count]){
                max = a[count];
                max_num = count;
            }
            if(min >= a[count]){
                min_num = count;
                min = a[count];
            }
        }
        printf("Case %d: %d\n",number, min_num == max_num ? a[0]:a[3-max_num-min_num]);
    }
}
