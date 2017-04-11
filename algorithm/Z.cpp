#include <cstdio>
#include <iostream>
#include <cstring>


using namespace std;

int main(void)
{
    int L,R;
    L = R = 0;
    char A[30];
    int Z[30] = {0};
    int len = strlen(A);
    Z[0] = 0;//i = 0的時候Z[i]等於零
    //有些網路上也寫直接寫strlen(A)
    for(int i = 1;i<len;i++) {
        if(i>R) {
            Z[i] = 0;
        }
        else {
            int ip = i - L;
            if(ip + Z[ip] < Z[L]) {
                Z[i] = Z[ip];
            }
            else {
                Z[i] = R - i +1;
            }
            while(i + Z[i] < len && A[i+Z[i]]==A[Z[i]]) {
                Z[i]++;
            }
            if(i+Z[i] - 1 > R) {
                L = i;
                R = i + Z[i] - 1;
            }
        }
    }
    return 0;
}
