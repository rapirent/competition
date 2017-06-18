#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int main(void)
{
    char input[400] = {0};
    while(fgets(input,sizeof(input),stdin)) {
        if(strncmp(input,"ENDOFINPUT",10)==0) {
            break;
        }
        memset(input,0,sizeof(input));
        fgets(input,sizeof(input),stdin);
        for(int i = 0;i<strlen(input)-1;i++) {
            if(input[i]>=70&&input[i]<=90) {
                input[i]-=5;
            }
            else if(input[i]>=65&&input[i]<70) {
                input[i] = input[i] - 65 + 90 - 4;
            }
        }
        printf("%s",input);
        fgets(input,sizeof(input),stdin);
        memset(input,0,sizeof(input));
    }
    return 0;
}
