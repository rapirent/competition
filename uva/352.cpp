#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

void DFS(char gogoMatrix[][50],int x, int y,int dimention)
{
    gogoMatrix[x][y]='0';
    if(x+1<dimention&&gogoMatrix[x+1][y]=='1') {
        DFS(gogoMatrix, x+1, y, dimention);
    }
    if(x+1<dimention&&y+1<dimention&&gogoMatrix[x+1][y+1]=='1') {
        DFS(gogoMatrix, x+1, y+1, dimention);
    }
    if(y+1<dimention&&gogoMatrix[x][y+1]=='1') {
        DFS(gogoMatrix, x, y+1, dimention);
    }
    if(x+1<dimention&&y-1>=0&&gogoMatrix[x+1][y-1]=='1') {
        DFS(gogoMatrix, x+1, y-1, dimention);
    }
    if(x-1>=0&&y-1>=0&&gogoMatrix[x-1][y-1]=='1') {
        DFS(gogoMatrix, x-1, y-1, dimention);
    }
    if(x-1>=0&&y+1<dimention&&gogoMatrix[x-1][y+1]=='1'){
        DFS(gogoMatrix, x-1, y+1, dimention);
    }
    if(x-1>=0&&gogoMatrix[x-1][y]=='1'){
        DFS(gogoMatrix, x-1, y, dimention);
    }
    if(y-1>=0&&gogoMatrix[x][y-1]=='1'){
        DFS(gogoMatrix, x, y-1, dimention);
    }
}


int main(void)
{   
    char gogoMatrix[50][50]={'\0'};
    int dimention = 0,num=0;
    while(scanf("%d",&dimention)!=EOF) {
        num++;
        char a;
        while((a=getchar())!='\n'&&(a!=EOF));
        for(int count=0;count<dimention;count++) {
            memset(gogoMatrix[count],0,49);
            fgets(gogoMatrix[count],49,stdin);
        }
        int eagle_num=0;
        for(int x=0;x<dimention;x++){
            for(int y=0;y<dimention;y++){
                if(gogoMatrix[x][y]=='1'){
                    DFS(gogoMatrix,x,y,dimention);
                    eagle_num++;
                }
            }
        }
        printf("Image number %d contains %d war eagles.\n",num,eagle_num);
    }
    return 0;
}
