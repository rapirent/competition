#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#define MAX 1000000


using namespace std;


bool prime[MAX] = {0};
void gogoPrime() {
    memset(prime, 1, sizeof(prime));
    for(int i = 2;i <= sqrt(MAX);i++) {
        if (prime[i]==1) {
            for(int j = i*i; j<MAX;j=j+i) {
                prime[j] = 0;
            }
        }
    }
}

int main(void)
{
    int input;
    gogoPrime();
    while(scanf("%d",&input)!=EOF) {
        if(input%2) {//奇數
            if(prime[input-2]==1) {
                printf("%d is the sum of %d and %d.\n",input,2,input-2);
            }
            else {
                printf("%d is not the sum of two primes!\n",input);
            }
        }
        else {
            int founded=0;
            for(int count=input/2;count>=0;count--) {
                if(prime[count]==1&&prime[input-count]==1) {
                    printf("%d is the sum of %d and %d.\n",input,count,input-count);
                    founded = 1;
                    break;
                }
            }
            if(founded == 0){
                printf("%d is not the sum of two primes!\n",input);       
            }
        }
    }
    return 0;
}
