#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct node {
    int x,y;
};
struct edge {
    int from,to;
    double weight;
    bool operator< (const edge&a ) const {
        return weight<a.weight;
    }
};
int set[510];
vector<struct node>node_list;
vector<struct edge>edge_list;
vector<struct edge>result_edge_list;
bool compare(const struct edge& a, const struct edge& b) {
    return (a.weight) > (b.weight);
}

int find(int x){
    return x==set[x]?x:find(set[x]);
}

void union_node(int x, int y) {
    set[find(x)] = find(y);
}

int main(void)
{
    int case_num;
    int s,p;
    scanf("%d",&case_num);
    for(int case_count = 0; case_count<case_num; case_count++) {
        scanf("%d %d",&s,&p);
        node_list.clear();
        edge_list.clear();
        for(int i = 0; i<p; i++) {
            set[i] = i;
            struct node tmp;
            scanf("%d %d",&tmp.x,&tmp.y);
            node_list.push_back(tmp);
        }
        for(int i = 0; i<p; i++) {
            for(int j = 0; j<p; j++) {
                struct edge tmp;
                tmp.from = i;
                tmp.to = j;
                tmp.weight = sqrt(pow((node_list[i].x - node_list[j].x),2) + pow((node_list[i].y - node_list[j].y),2));
                edge_list.push_back(tmp);
            }
        }
        sort(edge_list.begin(),edge_list.end());
        int edge_num = 0;
        result_edge_list.clear();
        for(int i = 0; i<p - 1; i++,edge_num++) {
            while(find(edge_list[edge_num].from) == find(edge_list[edge_num].to)) {
                edge_num++;
            }
            union_node(edge_list[edge_num].from, edge_list[edge_num].to);
            result_edge_list.push_back(edge_list[edge_num]);
        }
        sort(result_edge_list.begin(),result_edge_list.end(),compare);
        printf("%.2lf\n",result_edge_list[s-1].weight);
    }
    return 0;
}
