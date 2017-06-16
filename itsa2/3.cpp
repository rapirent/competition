#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

char print[11][11];

int main(void)
{
    int num;
    scanf("%d",&num);
    int n,s;
    while(num--) {
        scanf("%d %d",&n,&s);
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<n;j++) {
                print[i][j] = 'x';
            }
        }
        if(s==1) {
            for(int i = 0;i<n;i++) {
                print[i][n - 1 - i] = '*';
            }
        }
        else if(s==2) {
            for(int i = 0;i<n;i++) {
                print[i][i] = '*';
            }
        }
        else if(s==3) {
            for(int i = 0;i<n;i++) {
                print[i][n-1] = '*';
            }
        }
        else {
            for(int i =0;i<n;i++) {
                print[i][0] = '*';
            }
        }
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<n;j++) {
                if(j) {
                    printf(" ");
                }
                printf("%c",print[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
