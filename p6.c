#include<stdio.h>
#include<math.h>


void gauss_elimination(float a[20][20], int n){
    float x[10];

    // lower triangular matrix will be zeros.
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(j>i){
                float ratio = a[j][i]*1.0/a[i][i];
                for(int k=1; k<=n+1; k++){
                    a[j][k] = a[j][k] - ratio *a[i][k];
                }
            }
        }
    }

    x[n] = a[n][n+1]/a[n][n] ;


    for(int i=n-1; i>=1; i--){
        float sum = 0;
        for(int j=i+1; j<=n; j++){
            sum += a[i][j] * x[j];
        }
        x[i] = (a[i][n+1] - sum)/a[i][i];
    }


    // print the equation.
    for(int i=1; i<=n; i++){
        printf("x%d = %f", i, x[i]);
    }
    
}


int main(){
    float a[20][20];
    int n;
    printf("Enter size");scanf("%d", &n);

    // 2 3 -1 5
    // 4 4 -3 3
    // 2 -3 2 2

    // input equation in the form of matrix.
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n+1; j++){
            scanf("%f", &a[i][j]);
        }
    }

    gauss_elimination(a, n);

    return 0;
}