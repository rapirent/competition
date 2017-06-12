#include <cstdio>
#include <iostream>

using namespace std;
int ans;
int p[100000];
void init(int n)
{
    for(int i = 1;i<=n;i++) {
        p[i] = i;
    }
}
int find(int x)
{
    return x == p[x]?x:(p[x]=find(p[x]));
}
void union_set(int x,int y)
{
    int index_x = find(x);
    int index_y = find(y);
    if(index_x!=index_y) {
        ans--;
        p[index_x] = index_y;
    }
//    return p[find(x)] = find(y);
}
int main(void)
{
    int m;
    int i,j;
    int case_num = 0;
    while(scanf("%d %d",&ans,&m)!=EOF&&(ans!=0||m!=0)) {
        init(ans);
        for(int count = 0;count<m;count++) {
            scanf("%d %d",&i,&j);
            union_set(i,j);
        }
        printf("Case %d: %d\n",++case_num,ans);
    }
    return 0;
}
