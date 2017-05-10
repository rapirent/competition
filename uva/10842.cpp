#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int set[150];
struct edge {
    int u,v,c;
    bool operator< (const edge &a) const {
        return c>a.c;
    }
};

vector<struct edge> edge_list;

int find(int x)
{
    return (x==set[x])?x:(set[x] = find(set[x]));
}

void union_node(int x, int y)
{
    set[find(x)] = find(y);
}

int main(void)
{
    int repeat;
    scanf("%d",&repeat);
    int n,m; 
    int result;
    for(int case_count = 1;case_count<=repeat;case_count++) {
        scanf("%d %d",&n,&m);
        for(int i = 0;i<=n;i++) {
            set[i] =i;
        }
        result = 0;
        edge_list.clear();
        for(int i = 0;i<m;i++) {
            struct edge tmp;
            scanf("%d %d %d",&tmp.u,&tmp.v,&tmp.c);
            edge_list.push_back(tmp);
        }
        sort(edge_list.begin(),edge_list.end());
        for(int i = 0, j = 0; i<n-1; i++,j++) {
            while(find(edge_list[j].u)==find(edge_list[j].v)) {
                j++;
            }
            union_node(edge_list[j].u,edge_list[j].v);
            result = edge_list[j].c;            
        }
        printf("Case #%d: %d\n",case_count,result);
    }
    return 0;
}
