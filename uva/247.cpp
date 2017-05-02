#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <utility>
#include <map>

using namespace std;
map<string,int>translator;
map<int,string>anti_trans;
vector<int> topo;
void dfs(bool visited[],int i,bool edge[][2010],int N)
{
    for(int k = 0;k<N;k++) {
        if(!visited[k]&&edge[i][k]) {
            visited[k] = true;
            dfs(visited,k,edge,N);
        }
    }
    topo.push_back(i);
}
void dfs_reverse(bool visited[],int i,int flag,int N,bool edge[][2010])
{
    for(int k = 0;k<N;k++) {
        if(!visited[k]&&edge[k][i]) {
            visited[k] = true;
            dfs_reverse(visited,k,1,N,edge);
        }
    }
    cout << anti_trans[i];
    if(flag==1) {
        printf(", ");
    }

}
void scc(bool edge[][2010],int N)
{
    topo.clear();
    bool visited[2000] = {0};
    for(int i = 0;i<N;i++) {
        if(!visited[i]) {
            visited[i] = true;
            dfs(visited,i,edge,N);
        }
    } 
    memset(visited,0,sizeof(visited));
    for(int i = topo.size()-1;i>=0;i--) {
        if(!visited[topo[i]]) {
            visited[topo[i]] = true;
            dfs_reverse(visited,topo[i],0,N,edge);
            printf("\n");
        }
    }
}

int main(void)
{
    int n,m;
    char input[100];
    int count=0;
    bool edge[2010][2010];
    while(scanf("%d %d",&n,&m)==2&&n!=0&&m!=0) {
        while(getchar()!='\n');
        memset(edge,0,sizeof(edge));
        translator.clear();
        anti_trans.clear();
        int k = 0;
        for(int i = 0;i<m;i++) {
            memset(input,0,sizeof(input));
            fgets(input,sizeof(input),stdin);
            string tmp = strtok(input," \n");
            string tmp2 = strtok(NULL," \n");
            if(translator.find(tmp)==translator.end()) {
                translator[tmp] = k;
                anti_trans[k] = tmp;
                k++;
            }
            if(translator.find(tmp2)==translator.end()) {
                translator[tmp2] = k;
                anti_trans[k] = tmp2;
                k++;
            }
            edge[translator[tmp]][translator[tmp2]] = true;
        }
        if(count) {
            printf("\n");
        }
        printf("Calling circles for data set %d:\n",++count);
        scc(edge,n);
    }
    return 0;
}
