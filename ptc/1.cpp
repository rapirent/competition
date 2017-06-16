#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
char target[10000] = {0};

bool check(int index,int limit)
{
    printf("i = %d l = %d\n",index,limit);
    if(index==limit) {
        if(target[index]>=97&&target[index]<=122) {
            return true;
        }
        else {
            return false;
        }
    }
    if(target[index]>=97&&target[index]<=122) {
        return check(index+1,limit);
    }
 
    if(target[index]==90) {
        return check(index+1,limit);
    }
    if(target[index]==85||target[index]==77||target[index]==84||target[index]==82) {
        int first = index+1;
        int second = -1;
        for(int i = index+1;i<strlen(target);i++) {
            if(target[i]>=97&&target[i]<=122) {
                second = i;
                break;
            }
        }
        if(second == -1) {
            return check(index+1,limit);
        }
        printf("fuck\n");
        return check(index+1,second-1) & check(second,limit);
    }
    return false;
}

int main(void)
{
    int num;
    scanf("%d",&num);
    while(getchar()!='\n');
    char input[10000];
    while(num--) {
        memset(input,0,sizeof(input));
        fgets(input,sizeof(input),stdin);
        memset(target,0,sizeof(target));
        for(int i = strlen(input) - 2,j=0;i>=0;i--) {
            target[j++] = input[i];
        }
        if(check(0,strlen(target))) {
            printf("Yes\n");
        }
        else {
            printf("No\n");
        }
    }
    return 0;
}
