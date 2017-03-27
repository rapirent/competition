#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

struct node{
    int score;
    int time;
    char description[1000];
};
vector<node> DP; 
int total_time;

bool compare(node a, node b)
{
    return a.time < b.time;
} 

void travDP(int print[][1500], int time[], int score[], char description[][1000], int i, int j)
{
    if(i==0||j==0) {
        return;
    }
    if(print[i][j] == print[i-1][j]) {
        travDP(print,time,score,description,i-1,j);
        return;
    }
    travDP(print, time, score, description, i-1, j - time[i-1]);
    node tmp;
    tmp.score = score[i-1];
    tmp.time = time[i-1];
    for(int count=0;count<strlen(description[i-1]);count++) {
        tmp.description[count] = description[i-1][count];
    }
    DP.push_back(tmp);
    //    printf("%3d     %2d   %s\n",score[i-1],time[i-1],description[i-1]);
    total_time+=time[i-1];
}


int main(void)
{
    int repeat,allow_time;
    scanf("%d",&repeat);
    while(repeat-->0) {
        scanf("%d",&allow_time);
	    char c;
        while((c = getchar()) != '\n' && c != EOF);
        char input[1000];
        int score[500] = {0}, time[500] = {0};
        int print[500][1500] = {0};
        char description[500][1000] = {'\0'};
        int input_count=0;
        while(fgets(input,sizeof(input),stdin)!=0) {
            if(input[0] == '\n') {
                break;
            }
            sscanf(input,"%d %d %[^\t\n]",&score[input_count],&time[input_count],description[input_count]);
            memset(input,0,sizeof(input));
            input_count++;
        }
        for(int i=0;i<input_count;i++) {
            for(int j = 0;j<=allow_time;j++) {
                if(j - time[i] < 0) {
                    print[i+1][j] = print[i][j];
                }
                else {
                    print[i+1][j] = max( print[i][j], (print[i][ j - time[i]] + score[i]) );
                }
            }
        }
        total_time = 0;
        int i;
        for(i = 0; i<input_count&&time[i]>allow_time;i++);
        if(i>=input_count) {
            printf("There is not enough time to present any evidence. Drop the charges.\n");
            continue;
        }
        printf("Score  Time  Description\n");
        printf("-----  ----  -----------\n");
        travDP(print, time, score, description, input_count, allow_time);
        sort(DP.begin(),DP.end(), compare);
        for(int count = 0;count<DP.size();count++) {
            printf("%3d%7d   %s\n",DP[count].score,DP[count].time,DP[count].description);
        }
        DP.resize(0);
        printf("\nTotal score: %d points\n",print[input_count][allow_time]);
        printf(" Total time: %d hours\n",total_time);
    }
    return 0;
}
