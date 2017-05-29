#include <cstdio>
#include <iostream>
#include <cstring>
#define MAX 100010
using namespace std;

int N,Q;

long long lower_bit(long long n)
{
    return n&(-n);
}


void add (long long n,long long d, long long t[])
{
    
    while(n<=N) {
        t[n] += d;
        n+=lower_bit(n);
    }
}
long long sum(long long n, long long t[])
{
    long long s = 0;
    while(n>0) {
        s+=t[n];
        n-=lower_bit(n);
    }
    return s;
}
/*
long long query(long long a,long long b)
{
    if(a>b) {
        swap(a,b);
    }
    return sum(b) - sum(a-1);
}

這樣不行= =  這題的均增範圍太大了 網路上有公式解
void modify(long long a, long long b, long long c)
{
    a--;
    while(a<=b) {
        add(a+1,c);
        a++;
    }

}
*/

int main(void)
{
    long long t1[MAX]={0};

    long long t2[MAX]={0};


    scanf("%d %d",&N,&Q);
    int input;
    for(int i = 0;i<N;i++) {
        scanf("%d",&input);
        add(i+1,input,t1);
    }
    char action;
    long long a,b,c;
    while(getchar()!='\n');
    for(int i = 0;i<Q;i++) {
        scanf("%c",&action);
        switch(action) {
            case 'Q':
                scanf("%lld %lld",&a,&b);
                printf("%lld\n",(sum(b,t1)+b*sum(b,t2)) - (sum(a-1,t1) + (a-1)*sum(a-1,t2)));
                break;
            case 'C':
                scanf("%lld %lld %lld",&a,&b,&c);
                add(a,-c*(a-1),t1);
                add(a,c,t2);
                add(b,c*b,t1);
                add(b,-c,t2);
                break;
            default:
                break;
        }
        while(getchar()!='\n');
    }
    return 0;
}
