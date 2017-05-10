#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct node {
    int x,y;
};

struct edge {
    int from;
    int to;
    double length;
    bool operator< (const edge &a) const {
        return length<a.length;
    }
};



int set[1010];
vector<struct node> node_list;
vector<struct edge> edge_list;

int find(int x)
{
    return x==set[x]?x:(set[x] = find(set[x]));
}

void union_node(int x, int y)
{
    set[find(x)] = find(y);
}

int main(void)
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 1;i<=n;i++) {
        struct node tmp;
        scanf("%d %d",&tmp.x,&tmp.y);
        node_list.push_back(tmp);
        set[i] = i;
    }
    set[0] = 0;
    int a,b;
    for(int i = 0;i<m;i++) {
        scanf("%d %d",&a,&b);
        union_node(a,b);
    }
    for(int i = 1;i<=n;i++) {
        for(int j = i+1;j<=n;j++) {
            struct edge tmp;
            tmp.from = i;
            tmp.to = j;
            tmp.length = sqrt(pow((double)(node_list[i-1].x - node_list[j-1].x),2) + pow((double)(node_list[i-1].y - node_list[j-1].y),2));
            edge_list.push_back(tmp);
        }
    }
    double sum = 0.0;
    sort(edge_list.begin(),edge_list.end());
    for(int i = 0;i<edge_list.size();i++) {
        if(find(edge_list[i].from)!=find(edge_list[i].to)) {
            union_node(edge_list[i].from,edge_list[i].to);
            sum+=edge_list[i].length;
        }
    }
    printf("%.2lf\n",sum);

    return 0;
}
