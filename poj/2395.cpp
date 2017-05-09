#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

struct edge {
    int from;
    int to;
    int length;
    bool operator< (const edge &a) const {
        return length<a.length;
    }
};

vector<struct edge> edge_list;
int set[3000];

int find(int x)
{
    return (x==set[x])?x:(set[x] = find(set[x]));
}

void union_node(int x, int y)
{
    set[find(x)] = set[find(y)];
}

int main(void)
{
    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF) {
        edge_list.clear();
        for(int i = 1;i<=n;i++) {
            set[i] = i;
        }
        for(int i = 0; i<m; i++) {
            struct edge tmp;
            scanf("%d %d %d",&tmp.from,&tmp.to,&tmp.length);
            edge_list.push_back(tmp);
        }
        sort(edge_list.begin(),edge_list.end());
        int result;
        for(int i = 0, j = 0; i<n-1; i++,j++) {
            while(find(edge_list[j].from)==find(edge_list[j].to)) {
                j++;
            }
            union_node(edge_list[j].from,edge_list[j].to);
            result = edge_list[j].length;
        }
        printf("%d\n",result);
    }
    return 0;
}
