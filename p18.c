#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// y = mx + c


/*
6
Enter the value of x: 1 2 3 4 6 8

Enter the value of y: 2.4 3 3.6 4 5 6

Equation is y = 0.505882x + 1.976471
*/
void fitting_line(float x[], float y[], int n){

    double sum_x = 0, sum_y = 0, sum_xx = 0, sum_xy = 0;

    for(int i=0; i<n; i++){
        sum_x += x[i];
        sum_y += y[i];

        sum_xx += x[i]*x[i];
        sum_xy += x[i]*y[i]; 
    }

    double m = (n*sum_xy - sum_x*sum_y) / (n*sum_xx - sum_x*sum_x);
    double c = (sum_y - m*sum_x)/n;

    printf("Equation is y = %lfx + %lf", m, c);
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


    fitting_line(x, y, n);
    return 0;
}