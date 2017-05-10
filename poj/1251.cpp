#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int set[100000];

struct edge {
    int from;
    int to;
    int length;
    bool operator< (const edge &a) const {
        return length<a.length;
    }
};

int find(int x)
{
    return x==set[x]?x:set[x] = find(set[x]);
}

void union_node(int x, int y)
{
    set[find(x)] = find(y);
}


vector<struct edge>edge_list;
int main(void)
{
    int n;
    int input;
    int sum;
    while(scanf("%d",&n)!=EOF) {
        edge_list.clear();
        for(int i = 0;i<=n;i++) {
            set[i] = i;
        }
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<n;j++) {
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
        sort(edge_list.begin(),edge_list.end());
        sum = 0;
        for(int i = 0,j = 0;i<n-1;i++,j++) {
            while(find(edge_list[j].from)==find(edge_list[j].to)) {
                j++;
            }
            union_node(edge_list[j].from,edge_list[j].to);
            sum +=edge_list[j].length; 
        }
        printf("%d\n",sum);
    }

    return 0;
}
