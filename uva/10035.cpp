#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
    int a,b;
    char a_shu[10000], b_shu[10000];
    while(scanf("%d %d",&a,&b)==2&&(a!=0||b!=0)) {
        memset(a_shu,0,sizeof(a_shu));
        memset(b_shu,0,sizeof(b_shu));
        sprintf(a_shu,"%d",a);
        sprintf(b_shu,"%d",b);
        int carry = 0;
        int len_a,len_b;
        int result = 0;
        for(carry = 0,len_a = strlen(a_shu)-1,len_b = strlen(b_shu)-1
                ;len_a>=0&&len_b>=0
                ;len_a--,len_b--) {
            int shu1 = a_shu[len_a] - '0';
            int shu2 = b_shu[len_b] - '0';
            if( (shu1 + shu2 + carry)>= 10) {
                result ++;
            }
            carry = (shu1 + shu2 + carry)/10;
        }
        while(len_b>=0){
            int shu = b_shu[len_b--] - '0';
            if(shu + carry>=10) {
                result++;
            } 
            carry =( shu +carry ) /10;
        }
        while(len_a>=0){
            int shu = a_shu[len_a--] - '0';
            if(shu + carry>=10) {
                result++;
            }        
            carry = (carry + shu)/10;
        }
        if(result == 0 ) {
            printf("No carry operation.\n");
        }
        else if(result == 1){
            printf("1 carry operation.\n");
        }
        else {
            printf("%d carry operations.\n",result);
        }
    }
    return 0;
}
