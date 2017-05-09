#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int set[110];
int find(int x)
{
    return x==set[x]?x:(set[x] = find(set[x]));
}

void union_node (int x, int y)
{
    set[find(x)] = find(y);
}

struct edge {
    int from;
    int to;
    int length;
    bool operator< (const edge&a) const {
        return length<a.length;
    }
};

//是算後來才建好的道路= = 
int edge_init[110][110];
vector<struct edge> edge_list;
int main(void)
{
    int n;
    int input;
    int a,b;
    int q;
    int sum;
    while(scanf("%d",&n)!=EOF) {
        for(int i = 0;i<=n;i++) {
            set[i] = i;
        }
        sum = 0;
        memset(edge_init,-1,sizeof(edge_init));
        edge_list.clear();
        for(int i = 1;i<=n;i++) {
            for(int j = 1;j<=n;j++) {
                scanf("%d",&input);
                if(input) {
                    edge_init[i][j] = input;
                }
            }
        }
        scanf("%d",&q);
        int count = 0;
        for(int i = 0;i<q;i++) {
            scanf("%d %d",&a,&b);
            //count++;
            edge_init[a][b] = 0;
        }
        for(int i = 1;i<=n;i++) {
            for(int j = 1;j<=n;j++) {
                if(edge_init[i][j]!=-1) {
                    struct edge tmp;
                    tmp.from = i;
                    tmp.to = j;
                    tmp.length = edge_init[i][j];
                    edge_list.push_back(tmp);
                }
            }
        }
        sort(edge_list.begin(),edge_list.end());
        for(int j = 0; count<n-1&&j<edge_list.size(); count++,j++) {
            while(find(edge_list[j].from)==find(edge_list[j].to)) {
                j++;
            }
            union_node(edge_list[j].from,edge_list[j].to);
            sum+=edge_list[j].length;
        }
        printf("%d\n",sum);
    }
    return 0;
}
