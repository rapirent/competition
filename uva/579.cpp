#include <cstdio>
using namespace std;
int main(void){
    int a=0,b=0;
    float a_float, b_float;
    while(scanf("%d:%d",&a,&b)!=EOF&&(a||b)){
        if(a>12){
            a=a-12;
        }
        a_float=a*30+b/60.0*30.0;
        b=b*6;
        b_float = a_float - b;
        if (b_float <0) {
            b_float = -b_float;
        }
        printf("%.3f\n",b_float>180.0?360.0 - b_float:b_float);
    }
}
