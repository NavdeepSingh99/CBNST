#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// 0 6 6 
// Value of integration is = 1.410799

double f(double x) {
    return 1/ (1+x*x);
}

void trapezoidal(int lower, int upper, int n){
    double h = (upper - lower)/n;


    double result = f(lower) + f(upper);

    for(int i=1; i<=n-1; i++){
        double k = lower + i*h;
        result += 2*f(k);

    }

    result = (result*h)/2;
    printf("Value of integration is = %lf", result);
}




int main(){
    int lower , upper, intervals;
    scanf("%d", &lower);
    scanf("%d", &upper);
    scanf("%d", &intervals);

    trapezoidal(lower, upper, intervals);

    return 0;
}