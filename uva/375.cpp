#include <cstdio>
#include <iostream>

#include <cmath>


#define _USE_MATH_DEFINES

using namespace std;
int main(void)
{
    const double eps = 1e-8;
    double base,altitude;
    int total;
    scanf("%d",&total);
    while(total-->0){
        scanf("%lf %lf",&base,&altitude);
        double radius;
        double bien = hypot(base/2,altitude);
        double count=0;
        radius = base*altitude/(2*bien+base);
        double new_altitude = (altitude - 2*radius);
        while(radius>0.000001) {
            count+=radius;
            radius = radius * (new_altitude/altitude);
            altitude = new_altitude;
            new_altitude = altitude -2*radius;
        }
        printf("%13.6lf\n",count*2*M_PI);
        if(total>0) {
            printf("\n");
        }
    }
    return 0;
}
