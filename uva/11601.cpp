#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
int t[300][300];
//都加上一百


void addy(int x, int y, int d)
{
    while(y<300) {
        t[x][y] +=d;
        y+=y&(-y);
    }
}

void add(int x,int y,int d)
{
    while(x<300) {
        addy(x,y,d);
        x+=x&(-x);
    }
}
int sumy(int x, int y)
{
    int s = 0;
    while (y>0) {
        s+=t[x][y];
        y-=y&(-y);
    }
    return s;
}


int sum(int x,int y)
{
    int s = 0;
    while(x>0) {
        s+=sumy(x,y);
        x-=x&(-x);
    }
    return s;
}

int sum_all(int x1, int y1, int x2, int y2)
{
    if(x1 > x2) {
        swap(x1,x2);
    }
    if(y1 >y2) {
        swap(y1,y2);
    }
    return sum(x2,y2) - sum(x1-1,y2) - sum(x2,y1-1) + sum(x1-1,y1-1);
}


int main(void)
{
    int case_num;
    scanf("%d",&case_num);
    int n;
    int x1,y1,x2,y2;
    for(int case_count=1;case_count<=case_num;case_count++) {
        memset(t,0,sizeof(t));
        scanf("%d",&n);
        int result = 0;
        for(int i = 0;i<n;i++) {
            scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
            x1+=100;
            x2+=100;
            y1+=100;
            y2+=100;
            if(sum_all(x1,y1,x2-1,y2-1)==0) {
                for(int x = x1;x<x2;x++) {
                    for(int y = y1;y<y2;y++) {
                        result++;
                        add(x,y,1);
                    }
                }
            }
        }
        printf("Case %d: %d\n",case_count,result);
    } 
    return 0;
}
