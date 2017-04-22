#include <cstdio>
#include <algorithm>
using namespace std;
#define Inf 99999999
int dis[101][101];
int C, S, Q, Case = 1;

void Initial();
void Floyd();

int main()
{
    while (scanf("%d %d %d", &C, &S, &Q) && (C || S || Q)) {
        Initial();
        int a, b, sound;

        for (int i = 0; i < S; ++i) {
            scanf("%d %d %d", &a, &b, &sound);
            dis[a][b] = sound, dis[b][a] = sound;
        }

        Floyd();

        if (Case != 1) printf("\n");
        printf("Case #%d\n", Case++);

        for (int i = 0; i < Q; ++i) {
            scanf("%d %d", &a, &b);
            if (dis[a][b] == Inf)
                puts("no path");
            else
                printf("%d\n", dis[a][b]);
        }
    }
}
void Initial()
{
    for (int i = 1; i <= C; ++i){
        for (int j = 1; j <= C; ++j)
            dis[i][j] = Inf, dis[j][i] = Inf;
        dis[i][i] = 0;
    }
}
void Floyd()
{
    for (int k = 1; k <= C; ++k)
        for (int i = 1; i <= C; ++i)
            for (int j = 1; j <= C; ++j)
                if (dis[i][j] > max(dis[i][k], dis[k][j]))
                    dis[i][j] = max(dis[i][j], dis[k][j]);
}
