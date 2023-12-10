#include<stdio.h>
#include<math.h>


// double f(double x){
//     return x - pow(2.71828183,-x);
// }

double f(double x){
    return x*x*x - 5*x + 1;
}

float secant(double x0, double x1, int iteration){
    double x2;
    for(int i=0; i<iteration; i++){

        x2 = (x0*f(x1) - x1*f(x0))/(f(x1) - f(x0));
        printf("iteration %d result = %lf\n",i, x2);

        x0 = x1;
        x1 = x2;

        if(fabs(x0-x1) <= 0.0001) break;
    }

    return x2;
}

int main(){
    // printf("root of the equation is : %lf", secant(0, 1, 20));
    printf("root of the equation is : %lf", secant(0, 1, 20));
    
    return 0;
}