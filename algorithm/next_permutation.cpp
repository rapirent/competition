#include <cstdio>
#include <algorithm>

using namespace std;

int main(void)
{
    int p[10];
    for(int i =0;i<10;i++) {
        scanf("%d",&p[i]);
    }
    sort(p,p+10);
    do {
        for(int i =0;i<10;i++) {
            printf("%d",p[i]);
        }
        printf("\n");
    }while(next_permutation(p, p+10));
    return 0;
}
