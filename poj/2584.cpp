#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int capacity[35][35];
int flow[35][35];
int residual[35][35];
int pre[35];
bool visited[35];
int bottleneck[35];


int bfs(int s,int t)
{
    memset(visited,0,sizeof(visited));
    visited[s] = true;
    pre[s] = s;
    bottleneck[s] = 1e9;
    queue<int> Q;
    Q.push(s);
    while(!Q.empty()) {
        int i = Q.front();
        Q.pop();
        for(int j = 0;j<=t;j++) {
            if(!visited[j]&&residual[i][j]>0) {
                pre[j] = i;
                visited[j] = true;
                bottleneck[j] = min(bottleneck[i],residual[i][j]);
                Q.push(j);
                if(j==t) {
                    return bottleneck[j];
                }
            }
        }
    }
    return 0;

}

int max_flow(int s, int t)
{
    memset(flow,0,sizeof(flow));
    memcpy(residual,capacity,sizeof(residual));

    int total_flow;
    int aug_flow;
    for(total_flow=0;aug_flow=bfs(s,t);total_flow+=aug_flow) {
        for(int i = pre[t], j = t;i!=j;i=pre[j=i]) {
            flow[i][j] = flow[i][j] + aug_flow;
            flow[j][i] = -flow[i][j];
            residual[i][j] = capacity[i][j] - flow[i][j];
            residual[j][i] = capacity[j][i] - flow[j][i];
        } 
    }
    return total_flow;
}

void set_size(int start, int end, int num, int person)
{
    for(int i = start;i<=end;i++) {
        capacity[num][person + i + 1] = 1;
    }
}


int parse_size(char a)
{
    switch(a) {
        case 'S':
            return 0;
        case 'M':
            return 1;
        case 'L':
            return 2;
        case 'X':
            return 3;
        case 'T':
            return 4;
        default:
            printf("error!");
    }
}



int main(void)
{
    char input[100]={0};
    int person;
    int size;
    while(fgets(input,sizeof(input),stdin)!=NULL) {
        if(strcmp(input,"ENDOFINPUT\n") == 0 ) {
            break;
        }
        memset(capacity,0,sizeof(capacity));
        strtok(input," \n");
        char* tmp = strtok(NULL, " \n");
        sscanf(tmp,"%d",&person);
        
        for(int i = 1;i<=person;i++) {
            capacity[0][i] = 1;
        }

        memset(input,0,sizeof(input));

        for(int person_count = 1;person_count<=person;person_count++) {
            scanf("%s",input); 
            set_size(parse_size(input[0]),parse_size(input[1]),person_count,person);
            memset(input,0,sizeof(input));
        }
        for(int i = 0; i<5;i++) {
            scanf("%d",&size);
            capacity[person+i+1][person+6]=size;
        }
        if(max_flow(0,person+6)==person) {
            printf("T-shirts rock!\n");
        }
        else {
            printf("I'd rather not wear a shirt anyway...\n");
        }
        while(getchar()!='\n');
        fgets(input,sizeof(input),stdin);
        memset(input,0,sizeof(input));
    }
    return 0;
}
