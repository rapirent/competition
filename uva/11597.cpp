#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int set[450];

int find(int x)
{
    return x==set[x]?x:find(set[x]);
}

void union_node(int x, int y)
{
    set[find(x)] = set[find(y)];
}

struct edge {
    int from;
    int to;
};

vector<struct edge>edge_lis;

int main(void)
{
    int input;
    for(int count = 1;scanf("%d",&input)==1&&input!=0;count++) {
        /*
        edge_lis.clear();
        for(int i = 0; i<input; i++) {
            set[i] = i;
        }
        for(int i = 0; i<input; i++) {
            for(int j = i+1; j<input; j++) {
                struct edge tmp;
                tmp.from = i;
                tmp.to = j;
                edge_lis.push_back(tmp);
            }
        }
        */
        printf("Case %d: %d\n",count,input/2);
    }
    return 0;
}
