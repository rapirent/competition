#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
#define INF 999999999
struct Weight_type{
    int P;
    int W;
};
int main()
{
    int Case = 1, C, N, M, S, T;
    scanf("%d", &C);
    while (C--)
    {
        scanf("%d %d %d %d", &N, &M, &S, &T);
        vector<Weight_type> toNxt[20001];
        for (int i = 0, x, y, L; i < M; ++i) {
            scanf("%d %d %d", &x, &y, &L);
            toNxt[x].push_back({y,L});
            toNxt[y].push_back({x,L});
        }

        queue<int> Q;
        int Dis[20001];
        int inQueue[20001] = {0};
        int Count[20001] = {0};  // avoid infinite cycle
        for (int i = 0; i < N; ++i)
            Dis[i] = INF;
        Dis[S] = 0;
        inQueue[S] = true;
        Q.push(S);

        bool InfCycle = false;
        while (!Q.empty() && !InfCycle) {
            int now = Q.front();
            inQueue[now] = false;
            Q.pop();

            for (auto &nxt : toNxt[now]) {
                if (Dis[now] + nxt.W < Dis[nxt.P]) {
                    Dis[nxt.P] = Dis[now] + nxt.W;
                    if (!inQueue[nxt.P]) {
                        Q.push(nxt.P);
                        inQueue[nxt.P] = true;
                        ++Count[nxt.P];
                        if (Count[nxt.P] >= N) InfCycle = true;
                    }
                }
            }
        }
        printf("Case #%d: ", Case++);
        if (Dis[T] == INF) puts("unreachable");
        else printf("%d\n", Dis[T]);
    }
}
