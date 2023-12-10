#include<stdio.h>
#include<math.h>


double f(double x){
    return x*x*x - 2*x - 4;
}
double g(double x){
    return pow((2*x*x + 4), (1.0/3));
}
double gh(double x){
    return 4*x * pow((2*x*x + 4), (-2.0/3))/3;
}


float iteration_method(double x0, double x1){

    

    double  x;
    int i = 1;
    while(fabs(gh(x0)) < 1 && fabs(gh(x1)) < 1){

        x1 = g(x0);

        printf("iteration %d result = %lf\n",i, x1);i++;
        
        x = x0;
        x0 = x1;

        if(fabs(x0-x) <= 0.0001) break;
    }

    return x1;
}

int main(){
    printf("root of the equation is : %lf", iteration_method(2, 3));
    return 0;
}