#include <cstdio>
#include <map>
#include <cstring>
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <vector>
using namespace std;

map<string,string> strmap;
map<string, string>::iterator iter;
vector<string> result;
char easytolower(char in){
  if(in<='Z' && in>='A')
    return in-('Z'-'z');
  return in;
} 
int main(void)
{
    int num;
    scanf("%d",&num);
    while(getchar()!='\n');
    char input[1000] = {0};
    while(num--) {
        strmap.clear();
        result.clear();
        fgets(input,sizeof(input),stdin);
        char *tmp = strtok(input," \n");
        while(tmp!=NULL) {
            for(int i = 0;i<strlen(tmp);i++) {
                tmp[i] = tolower(tmp[i]);
            }

            if((iter = strmap.find(tmp))==strmap.end()) {
                string data = tmp;
                strmap.insert(pair<string, string>(tmp,tmp));
                result.push_back(data);
            }
            tmp  = strtok(NULL, " \n");
        }
        for(int i = 0;i<result.size();i++) {
            if(i) {
                printf(" ");
            }
            cout << result[i];
        }
        puts("");
    }

    return 0;
}
