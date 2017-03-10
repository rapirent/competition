#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;
int main(void)
{
    long long int a,b;
    char num1[15] = {'\0'},num2[15] = {'\0'};
    int result[225] = {0};
    int print_line[225] = {0};
    char input[225] = {0};
    while(fgets(input,100,stdin)!=0&&input[1] != '\n') {
        sscanf(input ,"%lld %lld",&a,&b);
        memset(input,0,sizeof(input));
        sprintf(num1,"%lld",a);
        sprintf(num2,"%lld",b);
        int num1_len = strlen(num1), num2_len = strlen(num2);
        for (int count = num1_len - 1,index = 0;count>=0;count--,index++) {
            int carry=0,index2=0;
            for (int count2 = num2_len -1;count2>=0;count2--,index2++) {
                int shu1 = num1[count] - '0';
                int shu2 = num2[count2] - '0';
                int tmp = result[index+index2];
                result[index+index2] = (tmp + carry + shu1*shu2)%10;
                carry = (tmp+carry+shu1*shu2)/10;
            }
            int carry_count=0;
            while(carry) {
                int tmp = result[index+index2+carry_count];
                result[index+index2+carry_count] = (tmp + carry)%10;
                carry = (tmp + carry)/10;
                carry_count++;
            }
        }
        int result_count = num1_len + num2_len - 1;
        while(result[result_count]==0&&result_count>0){
            result_count--;
        }
        int real_print = max(num1_len,max(num2_len,result_count+1));
        for(int count=0;count<real_print - num1_len;count++) {
            printf(" ");
        }
        printf("%lld\n",a);
        for(int count=0;count<real_print - num2_len;count++) {
            printf(" ");
        }
        printf("%lld\n",b);
        for(int count=0;count<real_print - max(num1_len,num2_len);count++) {
            printf(" ");
        }
        for(int count=0;count<max(num1_len,num2_len);count++) {
            printf("-");
        }
        printf("\n");
        if(num2_len!=1&&a!=0&&b!=0) { 
            int first = 0;
            for (int count2 = num2_len - 1,index = 0;count2>=0;count2--,index++) {
                memset(print_line,0,sizeof(print_line));
                int carry=0,index2=0;
                for (int count = num1_len - 1;count>=0;count--,index2++) {
                    int shu1 = num1[count] - '0';
                    int shu2 = num2[count2] - '0';
                    if (shu2==0) {
                        break;
                    }
                    if (count2!=0) {
                        first =1;
                    }
                    int tmp = print_line[index+index2];
                    print_line[index+index2] = (tmp+carry+shu1*shu2)%10;
                    carry = (tmp + carry + shu1*shu2)/10;
                }
                if(first == 0) {
                    continue;
                }
                if((num2[count2] - '0') != 0) {
                    int carry_count = 0;
                    while(carry) {
                        int tmp = print_line[index+index2+carry_count];
                        print_line[index+index2+carry_count] = (tmp + carry)%10;
                        carry = (tmp + carry)/10;
                        carry_count++;
                    }
                    int print_count = num1_len + num2_len - 1;
                    while(print_line[print_count]==0&&print_count>0) {
                        print_count--;
                    }
                    for (int i = 0;i<real_print - print_count-1;i++) {
                        printf(" ");
                    }
                    for (int i = print_count;i >= index;i--) {
                        printf("%d",print_line[i]);
                    }
                    printf("\n");
                }
            }
            if(first == 1 ){
                for (int count = 0;count<real_print;count++) {
                    printf("-");
                }
                printf("\n");
            }
        }
        for(int count=0;count<max(result_count,max(num1_len,num2_len)) - result_count - 1;count++) {
            printf(" ");
        }
        for (int count = result_count;count>=0;count--) {
            printf("%d",result[count]);
        }
        printf("\n\n");
        memset(num1,0,sizeof(num1));
        memset(num2,0,sizeof(num2));
        memset(result,0,sizeof(result));
    }
    return 0;
}
