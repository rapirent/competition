#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

typedef pair<int, int> pr;
#define x first
#define y second

pr mk(int x, int y)
{
    if( x > y ) swap(x, y);
    return pr(x, y);
}

vector<int> v[2000000];
bool visit[2000000];
vector<pr> Ans;

int N;

int id[2000000];
int low[2000000];
int clk;

void DFS(int O, int P)
{
    visit[O] = true;
    id[O] = low[O] = ++clk;

    for(int vi = 0; vi < v[O].size(); vi++)
    {
        int t = v[O][vi];

        if( t == P ) continue;

        if( visit[t] ) low[O] = min(low[O], id[t]);
        else
        {
            DFS(t, O);
            low[O] = min(low[O], low[t]);

            if( low[t] > id[O] ) Ans.push_back(mk(O, t) );
        }
    }
}

int main()
{
    while( scanf("%d", &N) != EOF )
    {

        Ans.clear();
        clk = 0;

        for(int Ni = 0; Ni < N; Ni++)
            v[Ni].clear(), visit[Ni] = false;

        for(int Ni = 0; Ni < N; Ni++)
        {
            int p;
            scanf("%d", &p);

            int K;
            scanf(" (%d)", &K);

            for(int Ki = 0; Ki < K; Ki++)
            {
                int q;
                scanf("%d", &q);

                v[p].push_back(q);
            }
        }

        for(int Ni = 0; Ni < N; Ni++)
            if( !visit[Ni] ) DFS(Ni, Ni);

        printf("%d critical links\n", Ans.size());

        sort(Ans.begin(), Ans.end());

        for(int Ai = 0; Ai < Ans.size(); Ai++)
            printf("%d - %d\n", Ans[Ai].x, Ans[Ai].y);

        puts("");
    }
}
