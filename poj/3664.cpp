#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;


struct node {
    int a,b,num;
    bool operator< (const node& tmp) const {
        return a>tmp.a || (a==tmp.a && b>tmp.b);
    }
};

bool compare (const node &foo, const node& bar) {
    return foo.b>bar.b || (foo.b==bar.b && foo.a>bar.a);
}

vector<struct node> node_set;

int main(void)
{
    int n,k;
    struct node tmp;
    while(scanf("%d %d",&n,&k)!=EOF) {
        node_set.clear();
        for(int i = 1;i<=n;i++) {
            scanf("%d %d",&tmp.a,&tmp.b);
            tmp.num = i;
            node_set.push_back(tmp);
        }
        sort(node_set.begin(),node_set.end());
        sort(node_set.begin(),node_set.begin()+k,compare);
        printf("%d\n",node_set[0].num);
    }
    return 0;
}
