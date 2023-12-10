#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/*
Enter x0 && y0 && xn && h : 0 1 1 0.1
x0=0.000000   y0=1.000000   yn=1.100000
x0=0.100000   y0=1.100000   yn=1.220000
x0=0.200000   y0=1.220000   yn=1.362000
x0=0.300000   y0=1.362000   yn=1.528200
x0=0.400000   y0=1.528200   yn=1.721020
x0=0.500000   y0=1.721020   yn=1.943122
x0=0.600000   y0=1.943122   yn=2.197434
x0=0.700000   y0=2.197434   yn=2.487178
x0=0.800000   y0=2.487178   yn=2.815895
x0=0.900000   y0=2.815895   yn=3.187485
Value of y at 1.000000 is = 3.187485
*/

double f(double x, double y) {
    return x+y;
}

void Euler_method(double x0, double y0, double xn, double h){
    int n = (xn - x0)/h;
    double yn = 0;
    printf("%d\n", n);

    for(int i=0; i<=n; i++){
        yn = y0 + h*f(x0, y0);

        printf("x0=%lf   y0=%lf   yn=%lf\n", x0, y0, yn);
        x0 = x0 + h;
        y0 = yn;
    }
    
    printf("Value of y at %lf is = %lf", xn, yn);
}


int main(){
    double x0, y0, h, xn;
    printf("Enter x0 && y0 && xn && h : ");
    scanf("%lf", &x0);
    scanf("%lf", &y0);
    scanf("%lf", &xn);
    scanf("%lf", &h);
    

    Euler_method(x0, y0, xn, h);

    return 0;
}