#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#define MAX 2000000

using namespace std;

vector<long long int> prime;
bool isPrime(long long int n)
{
    if(n==0) return false;
    for (long long int i =0;i<prime.size()&&prime[i]*prime[i] <= n; ++i) {
        if (n % prime [i] == 0){
            return false;
        }
    }
    return true;
}

void MakePrime()
{
    prime.push_back(2);
    prime.push_back(3);
    for (long long int i=5, gap=2; i < MAX; i+=gap, gap=6-gap){
        if (isPrime(i)&&i>0){
            prime.push_back(i);
        }
    }
}

int main(void)
{
    MakePrime();
    long long int input;
    long long int gogo = prime.size();
    while(scanf("%lld",&input)&&input!=-1) {
        for(int i=0;i<prime.size()&&input!=1;i++){
            while(input%prime[i]==0&&prime[i]!=0) {
                printf("    %lld\n", prime[i]);
                input = input/prime[i];
            }
        }
        if(input!=1) {
            printf("    %lld\n",input);
        }
        printf("\n");
    }    
    return 0;
}
