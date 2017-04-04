#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

vector<string> str1;
vector<string> str2;

int main(void)
{
    char input1[2000] = {'\0'},input2[2000] = {'\0'};
    int num = 1;
    int LCS[1000][1000] = {0};
    while(fgets(input1,sizeof(input1),stdin)!=0) {
        if(fgets(input2,sizeof(input2),stdin)==0) {
            break;
        }
        if(input1[0] == '\n' || input2[0] == '\n') {
            printf("%2d. Blank!\n",num++);
            memset(input1,0,sizeof(input1));
            memset(input2,0,sizeof(input2));
            continue;
        }
        str1.clear();
        str2.clear();
        string tmp;
        str1.push_back(tmp);
        bool isEmpty = true;
        for(int i = 0; i<strlen(input1) - 1;i++) {
            if((input1[i]>='A'&&input1[i]<='Z')||
                    (input1[i]>='0'&&input1[i]<='9')||
                    (input1[i]>='a'&&input1[i]<='z')) {
                tmp.push_back(input1[i]);
                isEmpty = false;
            }
            else {
                if(!isEmpty) {
                    str1.push_back(tmp);
                    tmp.clear();
                    isEmpty = true;
                }
            }
        }
        if(!isEmpty) {
            str1.push_back(tmp);
            tmp.clear();
        }
        str2.push_back(tmp);
        isEmpty = true;
        for(int i = 0;i<strlen(input2)-1;i++) {
            if((input2[i]>='A'&&input2[i]<='Z')||
                    (input2[i]>='0'&&input2[i]<='9')||
                    (input2[i]>='a'&&input2[i]<='z')) {
                tmp.push_back(input2[i]);
                isEmpty = false;
            }
            else {
                if(!isEmpty) {
                    str2.push_back(tmp);
                    tmp.clear();
                    isEmpty = true;
                }
            }
        }
        if(!isEmpty) {
            str2.push_back(tmp);
            tmp.clear();
        }
        memset(LCS,0,sizeof(LCS));
        int max_num = -1;

        if(str1.size()==1||str1.size()==1) {
            printf("%2d. Blank!\n",num++);
            memset(input1,0,sizeof(input1));
            memset(input2,0,sizeof(input2));
            continue;
        }
        for(int i = 1;i<str1.size();i++) {
            for(int j = 1;j<str2.size();j++) {
                if((str1[i])==(str2[j])&&((str1[i])!="")) {
                    LCS[i][j] = LCS[i-1][j-1] + 1;
                }
                else {
                    LCS[i][j] = max(LCS[i-1][j],LCS[i][j-1]);
                }
                if(max_num<LCS[i][j]) {
                    max_num = LCS[i][j];
                }
            }
        }
        printf("%2d. Length of longest match: %d\n",num++,max_num);
        memset(input1,0,sizeof(input1));
        memset(input2,0,sizeof(input2));
    }
    return 0;
}
