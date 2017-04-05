#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> str1;
vector<string> str2;

int main(void)
{
    string input1,input2;
    int num = 1;
    int LCS[1000][1000] = {0};
    while(getline(cin,input1)) {
        getline(cin,input2);
        string tmp;
        bool isEmpty = true;
        for(int i = 0; i<input1.size();i++) {
            if(!islower(input1[i]) && !isupper(input1[i]) && !isdigit(input1[i])) {
                input1[i] = ' ';
            }
        }
        isEmpty = true;
        for(int i = 0;i<input2.size();i++) {
            if(!islower(input2[i]) && !isupper(input2[i]) && !isdigit(input2[i])) {
                input2[i] = ' ';
            }
        }
        string string1 , string2;
        istringstream istring1(input1);
        istringstream istring2(input2);
        str1.push_back("");
        str2.push_back("");
        while (istring1 >> string1) {
            str1.push_back(string1);
        }
        while (istring2 >> string2) {
            str2.push_back(string2);
        }
        memset(LCS,0,sizeof(LCS));
        int max_num = -1;

        if(str1.size()==1||str2.size()==1) {
            printf("%2d. Blank!\n",num++);
            input1.clear();
            input2.clear();
            istring1.clear();
            istring2.clear();
            str1.clear();
            str2.clear();
            continue;
        }
        for(int i = 1;i<str1.size();i++) {
            for(int j = 1;j<str2.size();j++) {
                if((str1[i])==(str2[j])) {
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
        input1.clear();
        input2.clear();
        istring1.clear();
        istring2.clear();
        str1.clear();
        str2.clear();
    }
    return 0;
}
