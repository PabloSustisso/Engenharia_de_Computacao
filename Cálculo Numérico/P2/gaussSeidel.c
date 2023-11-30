#include <stdio.h>
#include <math.h>

#define N 3  // Tamanho da matriz

void gaussSeidel(double A[N][N], double B[N], double X[N], int maxIterations, double tolerance) {
    int i, j, k;
    double sum;

    for (k = 0; k < maxIterations; ++k) {
        for (i = 0; i < N; ++i) {
            sum = B[i];
            for (j = 0; j < N; ++j) {
                if (i != j) {
                    sum -= A[i][j] * X[j];
                }
            }
            X[i] = sum / A[i][i];
        }

        // Verificar a convergência
        double error = 0.0;
        for (i = 0; i < N; ++i) {
            sum = B[i];
            for (j = 0; j < N; ++j) {
                sum -= A[i][j] * X[j];
            }
            error += fabs(sum);
        }

        // Critério de parada
        if (error < tolerance) {
            printf("Convergiu após %d iterações\n", k + 1);
            return;
        }
    }

    printf("Número máximo de iterações atingido\n");
}

int main() {
    double A[N][N] = {{8, 5, 2},
                      {1, 5, 1},
                      {1, 2, 4}};

    double B[N] = {72, 31, 37};
    double X[N] = {9, 6.2, 9.25};

    int maxIterations = 2;
    double tolerance = 0.5;

    gaussSeidel(A, B, X, maxIterations, tolerance);

    // Exibir a solução
    printf("Solução:\n");
    for (int i = 0; i < N; ++i) {
        printf("X[%d] = %.6f\n", i + 1, X[i]);
    }

    return 0;
}