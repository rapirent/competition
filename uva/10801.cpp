#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;



int main(void)
{
    int n,k;
    char input_line[1000];
    while(scanf("%d%d",&n,&k)!=EOF) {
        int w[110][110];
        for(int i = 0; i <110;i++) {
            for(int j = 0;j<110;j++) {
                w[i][j] = 1e9;
            }
            w[i][i] = 0;
        }
        int elevator_spead[10] = {0};
        for(int i = 0;i<n;i++) {
            scanf("%d",&elevator_spead[i]);
        }
        while(getchar()!='\n');
        int tmp_int,floor_count;
        int single_floor[150];
        for(int i = 0;i<n;i++) {
            floor_count = 0;
            memset(input_line,0,sizeof(input_line));
            fgets(input_line,sizeof(input_line),stdin);
            vector<int> now_elevator;
            char* tmp = strtok(input_line," \n");
            while(tmp != NULL) {
                floor_count++;
                sscanf(tmp,"%d",&tmp_int);
                now_elevator.push_back(tmp_int);
                tmp = strtok(NULL," \n");
            }
            for(int j = 0;j<floor_count;j++) {
                for(int x = 0;x<now_elevator.size();x++) {
                    for(int y = 0;y<now_elevator.size();y++) {
                        if(x<y) {
                            if((y-x)*elevator_spead[i]<w[x][y]) {
                                w[y][x] = w[x][y] = (y-x)*elevator_spead[i];
                            }
                        }
                        else {
                            if((x-y)*elevator_spead[i]<w[y][x]) {
                                w[x][y] = w[y][x] = (x-y)*elevator_spead[i];
                            }
                        }
                    }
                }
            }
        }
        bool inqueue[110] = {0};
        int  dis[110];
        for(int i = 1;i<110;i++) {
            dis[i] = 1e9;
        }
//        memset(dis,-1,sizeof(dis));
        dis[0] = 0;
        inqueue[0] = true;
        queue<int>q;
        q.push(0);
        while(!q.empty()) {
            int now = q.front();
            inqueue[now] = false;
            q.pop();
            for(int i = 1;i<=100;i++) {
                if(dis[now] + w[now][i] + 60<dis[i]) {
                    dis[i] = dis[now] + w[now][i] + 60;
                    if(!inqueue[i]) {
                        q.push(i);
                        inqueue[i] = true;
                    }
                }
            }
        }
        if(dis[k]!=1e9) {
            printf("%d\n",dis[k]);
        }
        else {
            printf("IMPOSSIBLE\n");
        }
        
    }
    return 0;
}
