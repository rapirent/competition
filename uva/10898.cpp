#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
int dp(int answer[],int index, int special_meal[][2], int total_num)
{
    if(answer[index]||index==0) {
        return answer[index];
    }
    int minimum = 1e9;
    for(int i=0;i<total_num;i++) {
        if(index - special_meal[i][0] >=0) {
            minimum = min(minimum,dp(answer,index - special_meal[i][0], special_meal, total_num) 
                    + special_meal[i][1]);
        }
    }
    answer[index] = minimum;
    return answer[index];
}
int main(void)
{
    int item_num,special_meal_num;
    int item[10] = {0},special_meal[30][2];
    int answer[1000000];
    int order_num,order,max_price;
    while(scanf("%d",&item_num)!=EOF) {
        memset(special_meal,0,sizeof(special_meal));
        for(int a=0;a<item_num;a++) {
            special_meal[a][0] = 1;
            for(int b=1;b<(item_num- a);b++) {
                special_meal[a][0]*=10;
            }
            scanf("%d",&special_meal[a][1]);

        }
        scanf("%d",&special_meal_num);
        for(int input_count=item_num;input_count<(special_meal_num+item_num);input_count++) {
            for(int input_count2=0;input_count2<item_num;input_count2++) {
                int tmp;
                scanf("%d",&tmp);
                special_meal[input_count][0]*=10;
                special_meal[input_count][0]+=tmp;
            }
            scanf("%d",&special_meal[input_count][1]);
        }
        scanf("%d",&order_num);
        while(order_num-->0) {
            order=0;
            for(int a=0;a<item_num;a++) {
                int tmp;
                order*=10;
                scanf("%d",&tmp);
                order+=tmp;
            }
            //使用DP找出要哪些特餐
            /*
            for(int i=0;i<special_meal_num;i++) {
                for(int j=order;j>=special_meal[i][0];j++) {
                    answer[j] = min(answer[j],answer[j-special_meal[i][0]] + special_meal[i][1]);
                }
            }
            */
            memset(answer,0,sizeof(answer));
            max_price = dp(answer, order, special_meal, special_meal_num+item_num);
           /* 
            int founded=order;
            while(founded>=0&&answer[founded]==answer[founded-1]) {
                founded--;
            }
            
            if(founded<order) {
                int tmp,count=item_num-1;
                tmp = order - founded;
                while(tmp<=0) {
                    max_price+=(tmp%10)*item[count];
                    tmp/=10;
                    count--;
                }
                printf("%d\n",max_price);
                continue;
            }
            */
            printf("%d\n",max_price);
        }
    }
    return 0;
}
