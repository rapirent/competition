#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

char input[10000]={'\0'};
int main(void)
{
    while(fgets(input,sizeof(input),stdin)!=0) {
        if(strcmp(input,"0")==0) {
            break;
        }
        int count;
        if(!((strlen(input)-1)%2)) {
            count = 2;
        }
        else {
            count = 1;
        }
        long long int surplus=0,multi=0;
        int kai_fun[10000]={0},kai_fun_index=0;
        for(int index=0;index<strlen(input)-1;index=index+2,kai_fun_index++) {
            multi*=10;
            char tmp[10000]={'\0'};
            strncpy(tmp,input+index,count);
            count=2;
            int num;
            sscanf(tmp,"%d",&num);
            surplus*=100;
            if(surplus == 0) {
                int squard = ((int)sqrt(num)*(int)sqrt(num));
                surplus = num - squard;
                if(index==0) {
                    multi = (int)sqrt(num) * 2;
                }
                else {
                    multi += (int)sqrt(num);
                }
                kai_fun[kai_fun_index] = (int)sqrt(num);
            }
            else {
                surplus = surplus + num;
                int i=0;
                while ((multi+i)*i<surplus) {
                    i++;
                }
                i--;
                surplus = surplus - (multi+i)*i; 
                multi = multi + i*2;
                kai_fun[kai_fun_index]= i;
            }
        }
        //printf("%lld\n",kai_fun*kai_fun);
        int result[10000]={0};
        for(int count=kai_fun_index-1,index_count=0;count>=0;count--,index_count++) {
            int carry = 0,result_index=index_count;
            for(int count2=kai_fun_index-1;count2>=0;count2--,result_index++) {
               int a = kai_fun[count];
               int b = kai_fun[count2];
               int tmp = result[result_index];
               result[result_index] = (tmp + a*b + carry)%10;
               carry = (tmp + a*b + carry)/10;
            }
            int result_index_add = 0;
            while(carry>0) {
                int tmp  = result[result_index + result_index_add];
                result[result_index + result_index_add] = (tmp + carry)%10;
                carry = (tmp + carry)/10;
                result_index_add++;
            }
        }
        int max_len;
        for(max_len = kai_fun_index*2;max_len>=0;max_len--) {
            if(result[max_len]!=0) {
                break;
            }
        }
        for(int count=max_len;count>=0;count--) {
            printf("%d",result[count]);
        }
        printf("\n");
        memset(input,0,sizeof(input));
    }
    return 0;
}
