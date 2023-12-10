#include<stdio.h>
#include<stdlib.h>
#include<math.h>


/*
5
Enter x_interpolation : 2.5
Enter the value of x: 1 2 3 4 5

Enter the value of y: 1 8 27 64 125

Interpolation Table:
1.000000 1.000000 7.000000 12.000000 6.000000 0.000000
2.000000 8.000000 19.000000 18.000000 6.000000
3.000000 27.000000 37.000000 24.000000
4.000000 64.000000 61.000000
5.000000 125.000000
p = 0.500000
interpolation value at 2.500000  = 15.625000

*/

void gauss_forward(float x[], float y[10][10], int n, float x_interpolation){

    for(int i=1; i<n; i++){
        for(int j=0; j<n-i; j++){
            y[j][i] = y[j+1][i-1] - y[j][i-1]; 
        }
    }


    printf("Interpolation Table:\n");
    for(int i=0; i<n; i++){
        printf("%f ", x[i]);
        for(int j=0; j<n-i; j++){
            printf("%f ", y[i][j]);
        }
        printf("\n");
    }

    int nearest_index = 0;
    while(x[nearest_index] < x_interpolation) nearest_index++;
    nearest_index--;

    float p = (x_interpolation - x[nearest_index]) / (x[1] - x[0]);
    float result = y[nearest_index][0];
    float prod = 1;
    int step = 0;
    printf("p = %f\n", p);

    for(int i=1; i<n; i++){
        if(i%2 == 1){
            prod = prod * ((p + step)/i);

        }else{
            step = step + 1;
            prod = prod * ((p - step)/i);
        }

        result += prod*y[nearest_index - step][i] ;
    }

    printf("interpolation value at %f  = %f",x_interpolation, result);

}



int main(){
    float x[10];
    float y[10][10];
    float x_interpolation;
    int n;

    scanf("%d", &n);

    printf("Enter x_interpolation : ");
    scanf("%f", &x_interpolation);

    printf("Enter the value of x: ");
    for(int i=0; i<n; i++) scanf("%f", &x[i]);
    printf("\n");

    printf("Enter the value of y: ");
    for(int i=0; i<n; i++) scanf("%f", &y[i][0]);
    printf("\n");


    gauss_forward(x, y, n, x_interpolation);
    return 0;
}