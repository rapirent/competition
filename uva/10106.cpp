#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
    char num1[300]={'\0'},num2[300]={'\0'};
    int result[70000]={0};
    while(fgets(num1,260,stdin)!=0) {
        fgets(num2, 260,stdin);
        memset(result,0,sizeof(result));
        //important!!! it will count '\n'
        int num1_len = strlen(num1)-1,num2_len = strlen(num2)-1;
        int carry;
        for(int count=num1_len-1,index=0;count>=0;count--,index++) {
            int count2,index2=0;
            for(count2=num2_len-1,carry=0;count2>=0;count2--,index2++) {
                int shu1 = num1[count] - '0';
                int shu2 = num2[count2] - '0';
                int tmp = result[index+index2];
                result[index+index2] = (tmp + shu1*shu2 + carry)%10;
                carry = (tmp + shu1*shu2 + carry)/10;
            }
            int carry_count=0;
            while(carry){
                int tmp = result[index+index2+carry_count];
                result[index+index2+carry_count] = (tmp + carry)%10;
                carry = (tmp + carry)/10;
                carry_count++;
            }
        }
        int print_count = num1_len + num2_len;
        while(result[print_count]==0&&print_count>0){
            print_count--;
        }
        for(;print_count>=0;print_count--) {
            printf("%d",result[print_count]);
        }
        printf("\n");
        memset(num1,0,sizeof(num1));
        memset(num2,0,sizeof(num2));
    }
    return 0;
}
