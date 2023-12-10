#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// 0 6 6
// Value of integration is = 1.366173

double f(double x) {
    return 1/(1+x*x);
}

void simpson_1_3(int lower, int upper, int n){
    double h = (upper - lower)/n;
    
    if(n%2 != 0){
        printf("Simpson 1/3 cannot applied");
        exit(0);
    }

    double result = f(lower) + f(upper);

    for(int i=1; i<=n-1; i++){
        double k = lower + i*h;

        if(i%2 == 0) result += 2*f(k);
        else result += 4*f(k);

    }

    result = result*h/3;
    printf("Value of integration is = %lf", result);
}




int main(){
    int lower , upper, intervals;
    scanf("%d", &lower);
    scanf("%d", &upper);
    scanf("%d", &intervals);

    simpson_1_3(lower, upper, intervals);

    return 0;
}