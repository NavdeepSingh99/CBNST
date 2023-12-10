#include<stdio.h>
#include<stdlib.h>
#include<math.h>


/*
7
Enter the value of x: 1 3 5 7 9 4 6

Enter the value of y: 2 4 3 7 5 6 1

0.464286 0.309524
Regression equation of x on y : x = 0.464286y + 3.142857
Regression equation of y on x : y = 0.309524x + 2.452381
*/

/*
9
Enter the value of x: 1 2 3 4 5 6 7 8 9

Enter the value of y: 9 8 10 12 11 13 14 16 15

0.950000 0.950000
Regression equation of x on y : x = 0.950000y + -6.400000
Regression equation of y on x : y = 0.950000x + 7.250000
*/

void fitting_regression_line(float x[], float y[], int n){

    double sum_x = 0, sum_y = 0, sum_xx = 0, sum_yy = 0, sum_xy = 0;

    double mean_x = 0;
    double mean_y = 0;

    for(int i=0; i<n; i++){
        mean_x += x[i];
        mean_y += y[i];
    }

    mean_x = mean_x/n;
    mean_y = mean_y/n;


    for(int i=0; i<n; i++){
        sum_x += x[i] - mean_x;
        sum_y += y[i] - mean_y;


        sum_xx += (x[i] - mean_x)*(x[i] - mean_x);
        sum_yy += (y[i] - mean_y)*(y[i] - mean_y);

        sum_xy += (x[i] - mean_x)*(y[i] - mean_y);
    }

    

    double Bxy = sum_xy / sum_yy;            // x on y slope
    double Byx = sum_xy / sum_xx;            // y on x slope

    printf("%lf %lf\n", Bxy, Byx);

    printf("Regression equation of x on y : x = %lfy + %lf\n", Bxy, -Bxy*mean_y + mean_x);
    printf("Regression equation of y on x : y = %lfx + %lf", Byx, -Byx*mean_x + mean_y);
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


    fitting_regression_line(x, y, n);
    return 0;
}