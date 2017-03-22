#include <cstdio>
#include <cmath>
#include <cstring>


using namespace std;

int main(void)
{
    int p,q,r,s,t,u;
    const double eps =  1e-10;
    while(scanf("%d %d %d %d %d %d",&p,&q,&r,&s,&t,&u)==6) {
//        -xe^-x + q*cos(x) - r*sin(x) + s*atan(x) + 2tx =0
        double x0 = 1,x1;
        int count = 50,flag = 0;
        while(count-->0){
            x1 = x0 - ((p*exp((-1)*x0)+q*sin(x0) + r*cos(x0) + s*tan(x0) + t*x0*x0 + u )/((-1)*p*exp((-1)*x0)+q*cos(x0)+(-1)*r*sin(x0) + s*(1/(cos(x0)*cos(x0))) + 2*t*x0));
            if(fabs(x1-x0) - 0.00001<-eps) {
                flag = 1;
                break;
            }
            x0 = x1;
        }
        if((x1 - 1.0)> eps||(x1 - 0.0) < -eps||flag == 0) {
            printf("No solution\n");
        }
        else if(fabs(x1 - 0.0) < eps){
            printf("0.0000\n");
        }
        else {
            printf("%.4lf\n",x1);
        }
    }
    return 0;
}
