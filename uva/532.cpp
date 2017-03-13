#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

struct matrix_node{
    int x;
    int y;
    int z;
};


int a,b,c;
int BFS(int x,int y,int z,char matrix[][30][30],int visited[][30][30])
{
    queue<matrix_node> Q;
    matrix_node p = {x,y,z};
    Q.push(p);
    matrix[x][y][z] = '#';
    while(Q.empty()!=true) {
        int now_x = Q.front().x,
            now_y = Q.front().y,
            now_z = Q.front().z;
        if(matrix[now_x][now_y][now_z] == 'E') {
            return visited[now_x][now_y][now_z];
        }
        matrix[now_x][now_y][now_z] = '#';
        if(now_x+1<a&&matrix[now_x+1][now_y][now_z] != '#'&&visited[now_x+1][now_y][now_z] == 0) {
            visited[now_x+1][now_y][now_z] = visited[now_x][now_y][now_z] + 1;
            matrix_node tmp = {now_x +1, now_y,now_z};
            Q.push(tmp);
        }
        if(now_y+1<b&&matrix[now_x][now_y+1][now_z] != '#'&&visited[now_x][now_y+1][now_z] == 0) {
            visited[now_x][now_y+1][now_z] = visited[now_x][now_y][now_z] + 1;
            matrix_node tmp = {now_x,now_y+1,now_z};
            Q.push(tmp);
        }
        if(now_z+1<c&&matrix[now_x][now_y][now_z+1] != '#'&&visited[now_x][now_y][now_z+1] == 0) {
            visited[now_x][now_y][now_z+1] = visited[now_x][now_y][now_z] + 1;
            matrix_node tmp = {now_x,now_y,now_z+1};
            Q.push(tmp);
        }
        if(now_x-1>=0&&matrix[now_x-1][now_y][now_z] != '#'&&visited[now_x-1][now_y][now_z] == 0) {
             visited[now_x-1][now_y][now_z] = visited[now_x][now_y][now_z] + 1;
             matrix_node tmp = {now_x-1,now_y,now_z};
             Q.push(tmp);
        }
        if(now_y-1>=0&&matrix[now_x][now_y-1][now_z] != '#'&&visited[now_x][now_y-1][now_z] == 0) {
            visited[now_x][now_y-1][now_z] = visited[now_x][now_y][now_z] + 1;
            matrix_node tmp = {now_x,now_y-1,now_z};
            Q.push(tmp);
        }
        if(now_z-1>=0&&matrix[now_x][now_y][now_z-1] != '#'&&visited[now_x][now_y][now_z-1] == 0) {
            visited[now_x][now_y][now_z-1] = visited[now_x][now_y][now_z] + 1;
            matrix_node tmp = {now_x,now_y,now_z-1};
            Q.push(tmp);
        }
        Q.pop();
    }
    return 0;
}


int main(void)
{
    int start_x,start_y,start_z;
    char matrix[30][30][30] ={'\0'};
    int visited[30][30][30] = {0};
    while(scanf("%d %d %d",&a,&b,&c)==3&&a!=0&&b!=0&&c!=0) {
        for(int count=0;count<a;count++) {
            for(int count2 = 0; count2<b;count2++) {
                scanf("%s",matrix[count][count2]);
                for(int count3=0;count3<c;count3++) {
                    if(matrix[count][count2][count3]=='S') {
                        start_x = count;
                        start_y = count2;
                        start_z = count3;
                    }
                }
            }
        }
        int print;
        if(print=BFS(start_x,start_y,start_z,matrix,visited)){
            printf("Escaped in %d minute(s).\n",print);
        }
        else {
            printf("Trapped!\n");
        }        
        memset(matrix, 0, sizeof(matrix[0][0][0]) * 30 * 30 * 30);
        memset(visited, 0, sizeof(visited[0][0][0]) * 30 *30 *30);
    }
    return 0;
}
