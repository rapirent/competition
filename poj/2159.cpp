#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>


using namespace std;

int main(void)
{
    char input[200]={0},input2[200]={0};
    int compare1[30]={0} , compare2[30] = {0};
    scanf("%s %s",input,input2);
    for(int i = 0;i<strlen(input);i++) {
        compare1[input[i]-'A']++;
        compare2[input2[i]-'A']++;
    }
    sort(compare1,compare1+26);
    sort(compare2,compare2+26);
    //反正可以存128個int
    int j;
    for(j = 0;j<26;j++) {
        if(compare1[j]!=compare2[j]) {
            printf("NO\n");
            break;
        }
    }
    if(j>=26) {
        printf("YES\n");
    }
    return 0;
}
