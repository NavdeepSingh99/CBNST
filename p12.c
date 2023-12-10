#include<stdio.h>
#include<stdlib.h>
#include<math.h>


/*
5 
Enter x_interpolation : 6
Enter the value of x: 2 5 7 10 12

Enter the value of y: 18 180 448 1210 2028

interpolation value at 6.000000  = 294.000031

*/

float solve(int index, int n ,float x_interpolation, float x[10]){
    float result = 1;
    for(int i=0; i<n; i++){
        if(i != index){
            result *= (x_interpolation - x[i])/(x[index] - x[i]);
        }
    }

    return result;
}

void lagrange_interpolation(float x[], float y[], int n, float x_interpolation){

    float result = 0;

    for(int i=0; i<n; i++){
        result += solve(i, n ,x_interpolation, x)*y[i];
    }

    printf("interpolation value at %f  = %f",x_interpolation, result);

}



int main(){
    float x[10];
    float y[10];
    float x_interpolation;
    int n;

    scanf("%d", &n);

    printf("Enter x_interpolation : ");
    scanf("%f", &x_interpolation);

    printf("Enter the value of x: ");
    for(int i=0; i<n; i++) scanf("%f", &x[i]);
    printf("\n");

    printf("Enter the value of y: ");
    for(int i=0; i<n; i++) scanf("%f", &y[i]);
    printf("\n");


    lagrange_interpolation(x, y, n, x_interpolation);
    return 0;
}