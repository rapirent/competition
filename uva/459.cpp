#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int dis[30];
int main(void)
{
    int case_num;
    char max_char;
    char input[4] = {0};
    fgets(input,sizeof(input),stdin);
    sscanf(input,"%d",&case_num);
    while(getchar()!='\n');
    for(int i = 0;i<case_num;i++) {
        fgets(input,sizeof(input),stdin);
        max_char= input[0];
        for(int k = 0;k<=max_char - 'A';k++) {
            dis[k] = k;
        }
        char x,y;
        int input_count = 0;
        while(fgets(input,sizeof(input),stdin)!=0) {
            if(input[0]=='\n') {
                break;
            }
            x = input[0];
            y = input[1];
            int reminder = max(dis[x-'A'],dis[y-'A']);
            dis[x-'A'] = dis[y-'A'] = min(dis[x-'A'],dis[y-'A']);
            for(int k = 0;k<=max_char - 'A';k++) {
                if(dis[k] == reminder) {
                    dis[k] = dis[x-'A'];
                }
            }
        }
        int print_count = 0;
        for(int k = 0;k<=max_char - 'A';k++) {
            if(dis[k] == k) {
                print_count++;
            }
        }
        if(i) {
            printf("\n");
        }
        printf("%d\n",print_count);
    }
    return 0;
}
