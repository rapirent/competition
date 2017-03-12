#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>

#define MAX 10000000


using namespace std;

bool prime[MAX] = {0};//不能直接為true 雖然不知道為啥= =
int prime_total[MAX] = {0};
vector<int> prime_shu;
int dePrime[MAX] = {0};


void gogo_prime()
{
    memset(prime,1,sizeof(prime));
    prime[1] =false;
    prime[0] = false;
    for(int count=2;count<MAX;count++) {
        if(prime[count]==true){
            prime_total[count] = count;
            prime_shu.push_back(count);
        }
        int length = prime_shu.size();
        for(int i=0;i<length&&count*prime_shu[i]<MAX;i++) {//
            prime[count*prime_shu[i]] = false;
            if(count%prime_shu[i]==0) {//假如可以被目前找到的數拆分, 代表此數的質因數總和和原本找到的數的質因數總和一樣
                prime_total[count*prime_shu[i]] = prime_total[count];
                break;
            }
            else {
                prime_total[count*prime_shu[i]] = prime_total[count] + prime_shu[i];
            }
        }
        if(prime[prime_total[count]]==true) {//一個數的質因數總和是質因數的話
            dePrime[count] = dePrime[count-1]+1;
        }
        else {
            dePrime[count] = dePrime[count-1];
        }
    }
}

int main(void)
{
    int a,b;
    gogo_prime();
    while(scanf("%d",&a)&&a!=0) {
        scanf("%d",&b);
        printf("%d\n",dePrime[b] - dePrime[a-1]);
    }
    return 0;
}
