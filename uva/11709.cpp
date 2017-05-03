#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>

using namespace std;
//bool edge[1001][1001];
vector<int>edge[1001];
map<string, int>trans;
//map<int, string>anti_trans;
vector<int> topo;
bool visited[1010];
void dfs(int i,int P)
{
    visited[i] = true;
    for(vector<int>::iterator it = edge[i].begin() ;it!=edge[i].end() ;it++) {
        if(!visited[(*it)]) {
            dfs((*it),P);
        }
    }
    topo.push_back(i);
}
void dfs_reverse(int i,int P)
{
    visited[i] = true;
    for(int k = 0;k<P;k++) {   
        for(vector<int>::iterator it = edge[k].begin() ;it!=edge[k].end() ;it++) {
            if((*it)==i&&!visited[k]) {
                dfs_reverse(k,P);
            }
        }
    }
}
int scc(int P)
{
    memset(visited,0,sizeof(visited));
    topo.clear();
    for(int i = 0;i<P;i++) {
        if(!visited[i]) {
            dfs(i,P);
        }
    }
    memset(visited,0,sizeof(visited));
    int result = 0;
    for(int i = topo.size()-1;i>=0;i--) {
        if(!visited[topo[i]]) {
            dfs_reverse(topo[i],P);
            result++;
        }
    }
    return result;
}
int main(void)
{
    int p,t;
    while(scanf("%d %d",&p,&t)==2&&p!=0&&t!=0) {
        trans.clear();
//        anti_trans.clear();
        while(getchar()!='\n');
        string input,input2;
        for(int i = 0;i<1001;i++) {
            edge[i].clear();
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
        }
        printf("%d\n",scc(p));
    }
    return 0;
}
