#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>


using namespace std;
struct node {
    int weight,cost;
};

bool compare(node a,node b) 
{
    return a.weight>b.weight;
}


int main(void)
{
    int repeat;
    scanf("%d",&repeat);

    int c[30000];
    char discard[100];
    while(repeat-->0) {
        memset(c,0,sizeof(c));
        int n;
        int count;
        node m[15];
        memset(m,0,sizeof(m));
        scanf("%d",&n);
        scanf("%d",&count);
        for(int i = 0;i<count;i++) {
            scanf("%d %d %s",&(m[i].weight),&(m[i].cost),discard);
        }
        sort(m,m+count,compare);
 
        for(int i =0;i<count;i++) {
            for(int j = m[i].weight;j<=n;j++) {
                c[j] = max(c[j],(c[j-m[i].weight] + m[i].cost));
            }
        }
        printf("Total: %d\n",c[n]); 
    }
    return 0;
}
