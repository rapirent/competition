#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int t[1100][1100] = {0};



void addy(int x, int y, int d)
{
    while(y<1100) {
        t[x][y] +=d;
        y+=y&(-y);
    }
}

void add(int x,int y,int d)
{
    while(x<1100) {
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
    //一定是0 = =
    int dump;
    scanf("%d",&dump);
    scanf("%d",&dump);
    int instruction;
    int a,b,c,d;
    while(scanf("%d",&instruction)!=EOF&&instruction!=3) {
        switch(instruction) {
            case 1:
                scanf("%d %d %d",&a,&b,&c);
                add(a+1,b+1,c);
                break;
            case 2:
                scanf("%d %d %d %d",&a,&b,&c,&d);
                printf("%d\n",sum_all(a+1,b+1,c+1,d+1));
                break;
            default:
                break;
        }
    }
    return 0;
}
