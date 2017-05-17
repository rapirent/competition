#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int cap[40][40], flow[40][40];
int bottleneck[40], pre[40];
int main()
{
    int T, Case = 1, N, M, K;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &N, &M);
        // Initial
        int T = N+M+1;    // super sink
        memset(cap, 0, sizeof(cap));
        memset(flow, 0, sizeof(flow));

        // Input & Build graph
        for (int i = 1; i <= N; ++i) {
            scanf("%d", &K);
            for (int j = 1, ki; j <= K; ++j) {
                scanf("%d", &ki);
                ++cap[i][N+ki];
            }
        }
        for (int i = 2; i <= N; ++i) {
            for (int j = N+1; j <= N+M; ++j) {
                if (cap[i][j]) --cap[i][j];  // 如果有該貼紙, 保留一個絕對不會交換
                else cap[j][i] = 1;       // 如果沒有, cap[j][i]容量為1表示可接受交換一個
            }
        }
        for (int i = N+1; i <= N+M; ++i)     // 建立貼紙到T容量為1
            cap[i][T] = 1;

        // Maximum Flow (bfs)
        int result = 0;
        while (1) {
            memset(bottleneck, 0, sizeof(bottleneck));
            queue<int> Q;
            Q.push(1);
            bottleneck[1] = 9999999;

            while (!Q.empty() && !bottleneck[T]) {
                int cur = Q.front(); Q.pop();
                for (int nxt = 1; nxt <= T; ++nxt) {
                    if (bottleneck[nxt] == 0 && cap[cur][nxt] > flow[cur][nxt]) {
                        Q.push(nxt);
                        pre[nxt] = cur;
                        bottleneck[nxt] = min(bottleneck[cur], cap[cur][nxt] - flow[cur][nxt]);
                    }
                }
            }
            if (bottleneck[T] == 0) break;

            for (int cur = T; cur != 1; cur = pre[cur]) {
                flow[pre[cur]][cur] += bottleneck[T];
                flow[cur][pre[cur]] -= bottleneck[T];
            }
            result += bottleneck[T];
        }
        // Output
        printf("Case #%d: %d\n", Case++, result);
    }
}
