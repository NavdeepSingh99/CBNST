#include<stdio.h>
#include<stdlib.h>
#include<math.h>


/*
6
Enter x_interpolation : 1978
Enter the value of x: 1931 1941 1951 1961 1971 1981

Enter the value of y: 12 15 20 27 39 52

Interpolation Table:
1931.000000 12.000000 3.000000 2.000000 0.000000 3.000000 -10.000000
1941.000000 15.000000 5.000000 2.000000 3.000000 -7.000000
1951.000000 20.000000 7.000000 5.000000 -4.000000
1961.000000 27.000000 12.000000 1.000000
1971.000000 39.000000 13.000000
1981.000000 52.000000
interpolation value at 1978.000000  = 48.811340

*/

void newton_backward(float x[], float y[10][10], int n, float x_interpolation){

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

    float p = (x_interpolation - x[n-1]) / (x[1] - x[0]);
    float result = y[n-1][0];
    float prod = 1, factorial = 1;

    for(int i=1; i<n; i++){
        prod *= p + i - 1;
        factorial *= i;
        result += (prod/factorial)*y[(n-i-1)][i] ;
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


    newton_backward(x, y, n, x_interpolation);
    return 0;
}