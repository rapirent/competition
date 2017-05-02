#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
map<string,int>translate;
map<int,string>trans_reverse;
vector<string> result;

int trav_time;

void dfs(bool edge[][110],int dfn[],int low[],int u,int v,int N)
{
    dfn[v] = low[v] = ++trav_time;
    int child = 0;
    bool isArti = false;
    for(int i = 0;i<N;i++) {
        if(edge[v][i]&&i!=u) {
            //可能不是一個back edge
            if(dfn[i]) {
                low[v] = min(low[v],dfn[i]);
            }
            else {
                child++;
                dfs(edge,dfn,low,v,i,N);
                
                low[v] = min(low[v],low[i]);
                if(low[i]>=dfn[v]) {
                    isArti = true;
                }
            }
        }
    }
    if((u==v&&child>=2)||(u!=v&&isArti)) {
        result.push_back(trans_reverse[v]);
    }
}
void find(bool edge[][110],int N)
{
    trav_time = 0;
    result.clear();
    int dfn[110] = {0};
    int low[110] = {0};
    for(int i = 0;i<N;i++) {
        if(!dfn[i]) {
            dfs(edge,dfn,low,i,i,N);
        }
    }
    sort(result.begin(),result.end());
}
int main(void)
{
    int N,R;
    bool edge[110][110];
    int print_count = 0;
    while(scanf("%d",&N)==1&&N!=0) {
        translate.clear();
        trans_reverse.clear();
        string input;
        while(getchar()!='\n');
        for(int i = 0;i<N;i++) {
            cin >> input;
            translate[input] = i;
            trans_reverse[i] = input;
        }
        scanf("%d",&R);
        while(getchar()!='\n');
        char input2[100];
        memset(edge,0,sizeof(edge));
        for(int i = 0;i<R;i++) {
            memset(input2,0,sizeof(input2));
            fgets(input2,sizeof(input2),stdin);
            string tmp = strtok(input2," \n");
            string tmp2 = strtok(NULL," \n");
            edge[translate[tmp]][translate[tmp2]] = edge[translate[tmp2]][translate[tmp]] = true;
        }
        find(edge,N);
        if(print_count) {
            printf("\n");
        }
        printf("City map #%d: %ld camera(s) found\n",++print_count,result.size());
        for(int i = 0;i<result.size();i++) {
            cout << result[i] << endl;
        }
    }
    return 0;
}
