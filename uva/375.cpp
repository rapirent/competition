#include <cstdio>
#include <iostream>

#include <cmath>

int main(void)
{
    const double eps = 1e-8;
    double base,altitude;
    int total;
    scanf("%d",&total);
    while(total-->0){
        scanf("%lf %lf",&base,&altitude);
        double bien = hypot(base/2,altitude);
        double radius;
        double count=0;
        while((radius = base*altitude/(2*bien+base)) - 0.000001 >eps){
            count+=radius;
            base = base * (altitude - 2*radius)/altitude;
            altitude = (altitude -2*radius);
            bien = hypot(base/2,altitude);
        }
        printf("%13.6lf",count*2*M_PI);
        if(total>0) {
            printf("\n");
        }
    }
    return 0;
}
