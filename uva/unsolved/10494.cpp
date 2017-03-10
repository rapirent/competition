#include <cstdio>
#include <iostream>
#include <cstring>


using namespace std;

int main(void)
{
    char input[7000] = {'\0'};
    long long int num2;
    while(fgets(input,5000,stdin)!=0) {
        char *num1  = strtok(input," ");
        char sign;
        sscanf(strtok(NULL," "),"%c",&sign);
        sscanf(strtok(NULL," "),"%lld",&num2);
        long long int shu_stack=0;
        int first = 0;
        for(int count=0;count<strlen(input);count++) {
            int tmp = num1[count] - '0';
            shu_stack =shu_stack*10 + tmp;
            if(shu_stack/num2) {
                if(sign == '/') {
                    printf("%lld",shu_stack/num2);
                }
                shu_stack = shu_stack%num2;
                first = 1;
            }
            else if(sign == '/'&&(first||count==strlen(input)-1)){
                printf("0");
            }
        }
        if(sign == '%') {
            printf("%lld",shu_stack);
        }        
        printf("\n");
        memset(input,0,sizeof(input));
    }
    return 0;
}
