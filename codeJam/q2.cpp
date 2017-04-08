#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

bool compare(char a,char b)
{
    return a<=b;
}

int main(void)
{
    int repeat;
    long long input;
    char number[200] = {0};
    char cpy_number[200] = {0};
    scanf("%d",&repeat);
    long long print_num;
    char discard;
    while((discard=getchar())!=EOF&&discard!='\n');
    for(int case_num = 1;case_num<=repeat;case_num++) {
        memset(number,0,sizeof(number));
        fgets(number,sizeof(number),stdin);
        int len = strlen(number) - 1;
        number[len] = '\0';
        for(int i = 0;i<len-1;i++) {
            if(number[i]>number[i+1]) {
                for(int j = i+1;j<len;j++) {
                    number[j] = '9';
                }
                number[i]--;
                i = -1;
                continue;
            }
        }
        int index;
        for(index = 0;index<len;index++) {
            if(number[index]!='0') {
                break;
            }
        }
        printf("Case #%d: ",case_num);
        printf("%s\n",number+index);
    }
    return 0;
}
