#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int N,Q;

bool t[1100][1100];


int add(int x,int y)
{
    int s = 0;
    while(x<1100) {
        for(int i = y;i<1100;i+=i&(-i)) {
            s^=t[x][i];
        }
        x+=x&(-x);
    }
    return s;
}
void sumy(int x, int y)
{
    while (y>0) {
        t[x][y]^=1;
        y-=y&(-y);
    }
}


void modify(int x,int y)
{
    while(x>0) {
        sumy(x,y);
        x-=x&(-x);
    }
}

void update(int x1, int y1, int x2, int y2)
{
    if(x1 > x2) {
        swap(x1,x2);
    }
    if(y1 >y2) {
        swap(y1,y2);
    }
    modify(x2,y2);
    modify(x1-1,y2);
    modify(x2,y1-1);
    modify(x1-1,y1-1);
}
int main(void)
{

    int N,T;
    int case_num;
    scanf("%d",&case_num);
    while(case_num--) {
        memset(t,0,sizeof(t));
        scanf("%d %d",&N,&T);
        int input;
        char action;
        int a,b,c,d;
        while(getchar()!='\n');
        for(int i = 0;i<T;i++) {
            scanf("%c",&action);
            switch(action) {
                case 'Q':
                    scanf("%d %d",&a,&b);
                    printf("%d\n",add(a,b));
                    break;
                case 'C':
                    scanf("%d %d %d %d",&a,&b,&c,&d);
                    update(a,b,c,d);
                    break;
                default:
                    break;
            }
            while(getchar()!='\n');
        }
        puts("");
    }
    return 0;
}
