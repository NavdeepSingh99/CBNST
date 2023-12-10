#include<stdio.h>
#include<math.h>
#include<stdlib.h>


void gauss_siedal(float a[20][20], int n){
    float prev[10] = {0};
    float curr[10] = {0};

    // check diagonal.
    for(int i=1; i<=n; i++){
        float sum = 0;
        for(int j=1; j<=n; j++){
            sum += fabs(a[i][j]);
        }

        if(fabs(a[i][i]) <= sum) {
            printf("Cannot solve");
            exit(0);
        }
    }

    while(1){
        for(int i=1; i<=n; i++){
            float sum = 0;
            for(int j=1; j<=n; j++){
                if(j != i){
                    sum += a[i][j]*curr[j];
                }   
            }
            curr[i] = (a[i][n+1] - sum)/a[i][i];
        }

        float ae = 0;
        for(int i=1; i<=n; i++){
            ae = fmax(ae, fabs(curr[i]-prev[i]));
            prev[i] = curr[i];
        }

        if(ae <= 0.1) break;
    }


    // print the equation.
    for(int i=1; i<=n; i++){
        printf("x%d = %f", i, prev[i]);
    }
    
}

int main(){
    float a[20][20];
    int n;
    printf("Enter size");scanf("%d", &n);

    // cannot solve.
    // 2 3 -1 5
    // 4 4 -3 3
    // 2 -3 2 2

    // 20 1 -2 17
    // 3 20 -1 -18
    // 2 -3 20 25
    // x1 = 0.999969x2 = -1.000006x3 = 1.000002

    // input equation in the form of matrix.
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n+1; j++){
            scanf("%f", &a[i][j]);
        }
    }

    gauss_siedal(a, n);

    return 0;
}