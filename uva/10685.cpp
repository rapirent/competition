#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <cstring>


using namespace std;

map<string,int> trans; 

int set[6000];
int num[6000];

void init()
{
    for(int i = 0;i<6000;i++) {
        set[i] = i;
        num[i] = 1;
    }
}

int find(int x)
{
    return x == set[x] ? x : (set[x] = find(set[x]));
}

void union_set(int x, int y)
{
    x = find(x);
    y = find(y);
    //有可能是union一樣的set!
    if(x!=y) {
        set[x] = y;
        num[y]+=num[x];
    }
}

int main(void)
{
    int c,r;
    char input[100];
    string tmp;
    string tmp2;
    char *tmp_str = NULL;
    char *tmp_str2 = NULL;
    while(scanf("%d %d",&c,&r)!=EOF&&(c!=0||r!=0)) {
        trans.clear();
        while(getchar()!='\n');
        init();
        for(int i = 0;i<c;i++) {
            memset(input,0,sizeof(input));
            fgets(input,sizeof(input),stdin);
            tmp = strtok(input," \n");
            trans[tmp] = i;
        }
        for(int i = 0;i<r;i++) {
            memset(input,0,sizeof(input));
            fgets(input,sizeof(input),stdin);
            tmp_str = strtok(input," \n");
            tmp_str2 = strtok(NULL, " \n");
            tmp = tmp_str;
            tmp2 = tmp_str2;
            union_set(trans[tmp],trans[tmp2]);
        }
        int max_num = -1;
        for(int i = 0;i<c;i++) {
            if(max_num<num[i]) {
                max_num = num[i];
            }
        }
        printf("%d\n",max_num);
        fgets(input,sizeof(input),stdin);
    }
    return 0;
}
