#include<stdio.h>
#include<math.h>


// double f(double x){
//     return 3*x - cos(x*57.3) - 1;
// }

// double g(double x){
//     return 3 + sin(x*57.3);
// }

// double f(double x){
//     return x*x*x - 3*x - 5;
// }

// double g(double x){
//     return 3*x*x - 3;
// }



// double f(double x){
//     return x*x*x - 3;
// }

// double g(double x){
//     return 3*x*x;
// }


double f(double x){
    return -4*x + cos(x) + 2;
}

double g(double x){
    return -4 - sin(x);
}



float newton_raphson(double x0, double x1, int iteration){
    double x;
    for(int i=0; i<iteration; i++){

        x1 = x0 - f(x0)/g(x0);

        printf("iteration %d result = %lf\n",i, x1);
        
        x = x0;
        x0 = x1;

        if(fabs(x0-x) <= 0.0001) break;

        
    }

    return x1;
}

int main(){

    // printf("root of the equation is : %lf", newton_raphson(0, 1, 20));
    // printf("root of the equation is : %lf", newton_raphson(2, 3, 20));
    // printf("root of the equation is : %lf", newton_raphson(2, 3, 20));
    printf("root of the equation is : %lf", newton_raphson(0.5, 1, 20));
    
    return 0;
}