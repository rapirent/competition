#include <cstdio>
#include <iostream>

using namespace std;

int main(void){
    int a;
    int num[1000]={0};
    while(scanf("%d",&a)!=EOF){
        for(int count = 0; count<a;count++){
            scanf("%d",&num[count]);
        }
        int oper = 0;
        for(int count = 0; count<a;count++){
            for(int count2 = a - 1; count2 >  count ; count2 --){
                if(num[count2] < num[count2-1]){
                    int tmp = num[count2];
                    num[count2] = num[count2 - 1 ];
                    num[count2 - 1 ] = tmp;
                    oper ++ ;
                }
            }
        }
        printf("Minimum exchange operations : %d\n", oper);
    }
    return 0;
}
