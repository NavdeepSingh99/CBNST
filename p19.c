#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// y = a + bx + cx^2;

/*
5
Enter the value of x: 1 2 3 4 5

Enter the value of y: 5 12 26 60 97

5.714286 x^2 + -11.085714 x + 10.400000
*/

void toUpperTriangularMatrix(double matrix[3][4], double value[]){
    int n = 3;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            
            if(j>i){
                double ratio = matrix[j][i]/matrix[i][i];
                for(int k=0; k<=n; k++){
                    matrix[j][k] = matrix[j][k] - ratio*matrix[i][k];
                }
            }
        }
    }

    value[n-1] = matrix[n-1][n]/ matrix[n-1][n-1];

    for(int i=n-2; i>=0; i--){
        double sum = 0;
        for(int j=i+1; j<n; j++){
            sum += matrix[i][j]*value[j];
        }

        value[i] = (matrix[i][n] - sum)/matrix[i][i];
    }
}

void fitting_parabola(float x[], float y[], int n){

    double sum_x = 0, sum_x2 = 0, sum_x3 = 0, sum_x4 = 0;
    double sum_y = 0, sum_xy = 0, sum_x2y = 0;

    for(int i=0; i<n; i++){
        sum_x += x[i];
        sum_x2 += x[i]*x[i];
        sum_x3 += x[i]*x[i]*x[i];
        sum_x4 += x[i]*x[i]*x[i]*x[i];

        sum_y += y[i];
        sum_xy += x[i]*y[i];
        sum_x2y += x[i]*x[i]*y[i];
    }

    double matrix[3][4];

    matrix[0][0] = sum_x2;
    matrix[0][1] = sum_x;
    matrix[0][2] = n;
    matrix[0][3] = sum_y;
    matrix[1][0] = sum_x3;
    matrix[1][1] = sum_x2;
    matrix[1][2] = sum_x;
    matrix[1][3] = sum_xy;
    matrix[2][0] = sum_x4;
    matrix[2][1] = sum_x3;
    matrix[2][2] = sum_x2;
    matrix[2][3] = sum_x2y;

    double value[3] = {0, 0, 0};
    toUpperTriangularMatrix(matrix, value);


    printf("%lf x^2 + %lf x + %lf", value[0], value[1], value[2]);
    
}


int main(){
    float x[10];
    float y[10];
    int n;

    scanf("%d", &n);

    printf("Enter the value of x: ");
    for(int i=0; i<n; i++) scanf("%f", &x[i]);
    printf("\n");

    printf("Enter the value of y: ");
    for(int i=0; i<n; i++) scanf("%f", &y[i]);
    printf("\n");


    fitting_parabola(x, y, n);
    return 0;
}