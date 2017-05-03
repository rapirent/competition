#include <vector>
#include <set>
#include <cstdio>
#include <algorithm>
using namespace std;

vector<int> edge[1005];
int dfs_clock, dfn[1005], low[1005];
set<int> ans;   // 存有哪些割點
int cut[1005];  // cut[i]=j表示割點i能把圖切成j個分支

void Initial(int N);
void dfs(int cur, int parent);

int main()
{
    int a, Case = 1;
    while (scanf("%d", &a) && a) {
        Initial(1000);

        // Input
        int b, c;
        scanf("%d", &b);
        edge[a].push_back(b);
        edge[b].push_back(a);

        int nOfnode = 1;
        while (scanf("%d", &b) && b) {
            scanf("%d", &c);
            edge[b].push_back(c);
            edge[c].push_back(b);
        }

        // Find Cut Vertex
        dfs(a, -1);

        // Output
        if (Case != 1) putchar('\n');
        printf("Network #%d\n", Case++);
        if (ans.size() == 0)
            puts("  No SPF nodes");
        else
            for (set<int>::iterator iter = ans.begin(); iter != ans.end(); ++iter)
                printf("  SPF node %d leaves %d subnets\n", *iter, cut[*iter]);
    }
}
void Initial(int N)
{
    for (int i = 0; i <= N; ++i) {
        edge[i].clear();
        dfn[i] = low[i] = 0;
        cut[i] = 1;
    }
    dfs_clock = 0;
    ans.clear();
}
void dfs(int cur, int parent)
{
    int child = 0;
    low[cur] = dfn[cur] = ++dfs_clock;

    for (int i = 0; i < edge[cur].size(); ++i) {
        int nxt = edge[cur][i];
        if (!dfn[nxt]) {
            ++child;
            dfs(nxt, cur);
            low[cur] = min(low[cur], low[nxt]);

            if ((parent == -1 && child > 1) || (parent != -1 && low[nxt] >= dfn[cur])) {
                ++cut[cur];
                ans.insert(cur);
            }
        }
        else if (nxt != parent)
            low[cur] = min(low[cur], dfn[nxt]);
    }
}
