#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int set[10000];
struct node {
    double x,y;
};

struct edge {
    int from,to;
    double weight;
    bool operator< (const edge&a) const {
        return weight<a.weight;
    }
};
int find(int x) {
    return x==set[x]?x:find(set[x]);
}
void union_node(int x, int y) {
    set[find(x)] = find(y);
}
int main(void)
{
    int repeat;
    const double eps = 1e-8;
    double sum;
    vector<struct node>node_array;
    vector<struct edge>edge_array;
    int num;
    while(scanf("%d",&num)!=EOF) {
        char discard;
        node_array.clear();
        edge_array.clear();
        for(int i = 0 ; i<=num; i++) {
            set[i] = i;
        }
        for(int i = 0 ; i < num; i++) {
            double x,y;
            scanf("%lf%lf",&x,&y);
            struct node tmp_node;
            tmp_node.x = x;
            tmp_node.y = y;
            node_array.push_back(tmp_node);
        }
        for(int i = 0; i < num; i++) {
            for(int j = i+1; j < num; j++) {
                struct edge tmp_edge;
                tmp_edge.from = i;
                tmp_edge.to = j;
                tmp_edge.weight = sqrt(pow((node_array[i].x-node_array[j].x),2)+pow((node_array[i].y-node_array[j].y),2));
                edge_array.push_back(tmp_edge);
            }
        }
        sum = 0.0;
        sort(edge_array.begin(),edge_array.end());
        for(int i = 0, j = 0; i< num-1 && j < edge_array.size();i++,j++) {
            while( find((edge_array[j]).from) == find((edge_array[j]).to)) {
                j++;
            }
            union_node(edge_array[j].from,edge_array[j].to);
            sum += edge_array[j].weight;
        }
        printf("%.2lf\n",sum);
    }
    return 0;
}
