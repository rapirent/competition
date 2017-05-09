#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int set[600];
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

vector<struct edge> edge_list;
int main(void)
{
    int n;
    int input;
    int a,b;
    int q;
    int sum;
    int case_num;
    scanf("%d",&case_num);
    while(case_num--) {
        scanf("%d",&n);
        for(int i = 0;i<=n;i++) {
            set[i] = i;
        }
        sum = 0;
        edge_list.clear();
        for(int i = 1;i<=n;i++) {
            for(int j = 1;j<=n;j++) {
                scanf("%d",&input);
                if(input) {
                    struct edge tmp;
                    tmp.from = i;
                    tmp.to = j;
                    tmp.length = input;
                    edge_list.push_back(tmp); 
                }
            }
        }
        int count = 0;
        sort(edge_list.begin(),edge_list.end());
        for(int j = 0; count<n-1&&j<edge_list.size(); count++,j++) {
            while(find(edge_list[j].from)==find(edge_list[j].to)) {
                j++;
            }
            union_node(edge_list[j].from,edge_list[j].to);
            sum = edge_list[j].length;
        }
        printf("%d\n",sum);
    }
    return 0;
}
