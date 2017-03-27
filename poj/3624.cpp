#include <cstdio>
#include <iostream>

using namespace std;

int main(void)
{
    int N,M;
    scanf("%d %d",&N,&M);
    int W[4000] = {0}, D[4000] = {0};
    for(int a=0;a<N;a++) {
        scanf("%d %d",&W[a],&D[a]);
    }
    int print[50000] = {0};
    for(int a=0;a<N;a++) {
        for(int b = M;(b - W[a])>=0;b--) {
            print[b] = max(print[b], print[ b - W[a] ] + D[a]);    
        }
    }
    printf("%d\n",print[M]);
    return 0;
}
