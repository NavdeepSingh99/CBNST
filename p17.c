#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/*
Enter x0 && y0 && xn && h : 0 1 1 0.5
x0=0.000000   y0=1.000000   yn=1.796875
x0=0.500000   y0=1.796875   yn=3.434692
Value of y at 1.000000 is = 3.434692
*/

double f(double x, double y) {
    return x+y;
}

void Runge_kuttas_method(double x0, double y0, double xn, double h){
    int n = (xn - x0)/h;
    double yn = 0;

    for(int i=0; i<n; i++){
        double k1 = h * f(x0, y0);
        double k2 = h * f(x0 + h/2, y0 + k1/2);
        double k3 = h * f(x0 + h/2, y0 + k2/2);
        double k4 = h * f(x0 + h, y0 + k3);

        double k = 1.0/6 * (k1 + 2*k2 + 2*k3 + k4);
        yn = y0 + k;

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
    

    Runge_kuttas_method(x0, y0, xn, h);

    return 0;
}