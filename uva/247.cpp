#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <utility>
#include <map>

using namespace std;

vector<pair<string,string> > edge;
vector<int> topo;
void dfs(bool visited[],int i)
{
    for(int k = 0;k<edge.size();k++) {
        if(!visited[k]&&i!=k&&edge[k].first==edge[i].first) {
            visited[k] = true;
            dfs(visited,k);
        }
    }
    topo.push_back(i);
}
void dfs_reverse(bool visited[],int i,int count) {
    for(int k = 0;k<edge.size();k++) {
        if(!visited[k]&&i!=k&&edge[k].first==edge[i].second) {
            visited[k] = true;
            dfs_reverse(visited,k,1);
        }
    }
    cout << edge[i].second;
    if(count==1) {
        printf(", ");
    }

}
void scc()
{
    topo.clear();
    bool visited[2000] = {0};
    for(int i = 0;i<edge.size();i++) {
        if(!visited[i]) {
            visited[i] = true;
            dfs(visited,i);
        }
    } 
    memset(visited,0,sizeof(visited));
    for(int i = topo.size()-1;i>=0;i--) {
        if(!visited[i]) {
            visited[i] = true;
            dfs_reverse(visited,i,0);
            printf("\n");
        }
    }
}

int main(void)
{
    int n,m;
    char input[100];
    int count=0;
    while(scanf("%d %d",&n,&m)==2&&n!=0&&m!=0) {
        while(getchar()!='\n');
        edge.clear();
        for(int i = 0;i<m;i++) {
            memset(input,0,sizeof(input));
            fgets(input,sizeof(input),stdin);
            char *tmp = strtok(input," \n");
            char *tmp2 = strtok(NULL," \n");
            edge.push_back(make_pair(tmp,tmp2));     
        }
        if(count) {
            printf("\n");
        }
        printf("Calling circles for data set %d:\n",++count);
        scc();
    }
    return 0;
}
