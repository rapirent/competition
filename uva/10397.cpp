#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


int set[1000];
bool have_road[1000][1000];

struct node {
    int x,y;
};

struct edge {
    int from,to;
    double length;
    bool operator< (const edge& a) const {
        return length<a.length;
    }
};

vector<struct node> node_list;
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
    int n,m;
    int a,b;
    double sum;
    while(scanf("%d",&n)!=EOF) {
        node_list.clear();
        edge_list.clear();
        memset(have_road,0,sizeof(have_road));
        for(int i = 0;i<n;i++) {
            set[i+1] = i+1;
            struct node tmp;
            scanf("%d %d",&tmp.x,&tmp.y);
            node_list.push_back(tmp);
        }
        scanf("%d",&m);
        for(int i = 0;i<m;i++) {
            scanf("%d %d",&a,&b);
            have_road[a][b] = have_road[b][a] =  true;
        }
        for(int i = 1;i<=n;i++) {
            for(int j = i+1;j<=n;j++) {
                struct edge tmp;
                tmp.from = i;
                tmp.to = j;
                if(!have_road[i][j]) {
                    tmp.length = sqrt(pow((double)(node_list[i-1].x - node_list[j-1].x),2) + pow((double)(node_list[i-1].y - node_list[j-1].y),2));
                }
                else {
                    tmp.length = 0.0;
                }
                edge_list.push_back(tmp);
            }
        }
        sum = 0.0;
        sort(edge_list.begin(),edge_list.end());
        for(int i = 0,j=0;i<n-1;i++,j++) {
            while(find(edge_list[j].from)==find(edge_list[j].to)) {
                j++;
            }
            union_node(edge_list[j].from,edge_list[j].to);
            if(!have_road[edge_list[j].from][edge_list[j].to]) {
                sum+=edge_list[j].length;
            }
        }
        printf("%.2lf\n",sum); 
    }
    return 0;
}
