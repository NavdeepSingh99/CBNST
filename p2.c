#include<stdio.h>
#include<math.h>


// double f(double x){
//     return cos(x) - x*pow(2.71828183,x);
// }

double f(double x){
    return x*x*x - 4*x - 9;
}

float bisection(double x0, double x1, int iteration){
    double x2;
    for(int i=0; i<iteration; i++){

        x2 = (x0+x1)/2;
        printf("iteration %d avg = %lf\n",i, x2);

        if(f(x2) * f(x0) < 0) x1 = x2;
        else if(f(x2) * f(x1) < 0) x0 = x2;

        if(fabs(x0-x1) <= 0.0001) break;
    }

    return x2;
}

int main(){
    printf("root of the equation is : %lf", bisection(2, 3, 20));
    
    return 0;
}