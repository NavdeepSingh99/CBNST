#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// 0 6 6
// Value of integration is = 1.357081

double f(double x) {
    return 1/(1+x*x);
}

void simpson_3_8(int lower, int upper, int n){
    double h = (upper - lower)/n;
    
    if(n%3 != 0){
        printf("Simpson 3/8 cannot applied");
        exit(0);
    }

    double result = f(lower) + f(upper);

    for(int i=1; i<=n-1; i++){
        double k = lower + i*h;

        if(i%3 == 0) result += 2*f(k);
        else result += 3*f(k);

    }

    result = result*(3*h/8);
    printf("Value of integration is = %lf", result);
}




int main(){
    int lower , upper, intervals;
    scanf("%d", &lower);
    scanf("%d", &upper);
    scanf("%d", &intervals);

    simpson_3_8(lower, upper, intervals);

    return 0;
}