#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>

using namespace std;
//bool edge[1001][1001];
vector<int>edge[1010];
vector<int>rever_edge[1010];
map<string, int>trans;
//map<int, string>anti_trans;
vector<int> topo;
bool visited[1010];
void dfs(int i,int P)
{
    visited[i] = true;
    for(int it = 0 ;it<edge[i].size() ;it++) {
        if(!visited[edge[i][it]]) {
            dfs(edge[i][it],P);
        }
    }
    topo.push_back(i);
}
void dfs_reverse(int i,int P)
{
    visited[i] = false;
    for(int it = 0 ;it<rever_edge[i].size() ;it++) {
        if(visited[rever_edge[i][it]]) {
            dfs_reverse(rever_edge[i][it],P);
        }
    }
}
int scc(int P)
{
    memset(visited,false,sizeof(visited));
    topo.clear();
    for(int i = 0;i<P;i++) {
        if(!visited[i]) {
            dfs(i,P);
        }
    }
    int result = 0;
    for(int i = topo.size()-1;i>=0;i--) {
        if(visited[topo[i]]) {
            dfs_reverse(topo[i],P);
            result++;
        }
    }
    return result;
}
int main(void)
{
    int p,t;
    while(scanf("%d %d",&p,&t)==2&&(p!=0||t!=0)) {
        trans.clear();
        //        anti_trans.clear();
        while(getchar()!='\n');
        string input,input2;
        for(int i = 0;i<1010;i++) {
            edge[i].clear();
            rever_edge[i].clear();
        }
        for(int i = 0;i<p;i++) {
            getline(cin,input);
            trans[input] = i;
            //            anti_trans[i] = input;
        }
        for(int i = 0;i<t;i++) {
            getline(cin,input);
            getline(cin,input2);
            edge[trans[input]].push_back(trans[input2]);
            rever_edge[trans[input2]].push_back(trans[input]);
        }
        printf("%d\n",scc(p));
    }
    return 0;
}
