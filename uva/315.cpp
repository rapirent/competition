#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>


using namespace std;

int dfs_time = 0;
int arti_list;
void dfs(int i,int j,bool edge[][200],int dfn[],int low[],int N)
{
    dfn[j] = low[j] = ++dfs_time;
    int child = 0;
    bool isArti = false;

    for(int k = 1;k<=N;k++) {
        if(edge[j][k]&&k!=i) {
            //存在(j,k)，
            if(dfn[k]) {//k是i的祖先
                //k被拜訪, 是回邊
                low[j] = min(low[j],dfn[k]);
            }
            else {
                //j,k有可能不是回邊，也有可能是
                child++;
                dfs(j,k,edge,dfn,low,N);
                //繼續找找看！！！
                low[j] = min(low[k],low[j]);
                if(low[k]>=dfn[j]) {
                    isArti = true;
                }
            }
        }
    }
    if((i==j&&child>=2)||((i!=j)&&isArti)) {
        arti_list++;
    }
}

void arti(bool edge[][200],int N)
{
    int dfn[200] = {0};
    int low[200] = {0};
//    arti_list.clear();
    arti_list = 0;
    dfs_time = 0;
    for(int i = 1;i<=N;i++) {
        if(!dfn[i]) {
            dfs(i,i,edge,dfn,low,N);
        }
    }
}

int main(void)
{
    int N;
    char input[200];
    bool edge[200][200];
    while(scanf("%d",&N)!=EOF&&N!=0) {
        memset(edge,0,sizeof(edge));
        while(getchar()!='\n');
        //input
        for(;;) {
            memset(input,0,sizeof(input));
            fgets(input,sizeof(input),stdin);
            char *tmp = strtok(input," \n");
            int from,to;
            sscanf(tmp,"%d",&from);
            if(from == 0) {
                break;
            }
            tmp = strtok(NULL," \n");
            while(tmp!=NULL) {
                sscanf(tmp,"%d",&to);
                edge[to][from] = edge[from][to] = true;//無向圖= =
                tmp = strtok(NULL," \n");
            }
        }
        arti(edge,N);        
        printf("%d\n",arti_list);
    }
    return 0;
}
