#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <cstring>

using namespace std;

int main(void)
{
    map<string,string> dict;
    char input[100100] = {0};
    char string1[50] = {0},string2[50] = {0};
    while(fgets(input,sizeof(input),stdin)!=0&&input[0]!='\n') {
        sscanf(input,"%s %s",string1,string2);
        dict[string2] = string1;
        fflush(stdin);
        memset(input,0,sizeof(input));
        memset(string1,0,sizeof(string1));
        memset(string2,0,sizeof(string2));
    }
    char discard;
    map<string,string>::iterator iter;
    memset(input,0,sizeof(input));
    while(scanf("%s",input)!=EOF) {
        iter = dict.find(input);
        if(iter != dict.end()) {
            cout << dict[input] <<endl;
        }
        else {
            printf("en\n");
        }
        memset(input,0,sizeof(input));
    }
    return 0;
}
