#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


struct edge {
    int u,v,weight;
    bool operator< (const edge &a) const {
        return weight>a.weight;
    }
};

vector<struct edge> edge_list;

int set[10010];
int find(int x) {
    return (x==set[x])?x:(set[x] = find(set[x]));
}

void union_node(int x, int y)
{
    set[find(x)] = find(y);
}

int main(void)
{
    int n,m,sum;
    scanf("%d %d",&n,&m);
    for(int i = 0;i<m;i++) {
        struct edge tmp;
        scanf("%d %d %d",&tmp.u,&tmp.v,&tmp.weight);
        edge_list.push_back(tmp);
    }
    sort(edge_list.begin(),edge_list.end());
    sum = 0;
    for(int i = 0;i<=n;i++) {
        set[i] = i;
    }
    int count=0;
    for(int j=0;j<edge_list.size();j++) {
        if(find(edge_list[j].u)!=find(edge_list[j].v)) {
            union_node(edge_list[j].u,edge_list[j].v);
            sum+=edge_list[j].weight;
            count++;
        }
    }
    if(count==n-1) {
        printf("%d\n",sum);
    }
    else {
        printf("-1\n");
    }
    return 0;
}
