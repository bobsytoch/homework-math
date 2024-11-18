#include <stdio.h>
#include <math.h>

#define N 5

void Minor(float matrixA[N][N], float temp[N][N], int p, int q, int n)
{
    int i = 0, j = 0;
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++) 
        {
            if (row != p && col != q) 
            {
                temp[i][j++] = matrixA[row][col];
                if (j == n - 1) 
                {
                    j = 0;
                    i++;
                }
            }
        }
    }

}
 
int Determinant(float matrixA[N][N], int n)
{
    int D = 0; 
    if (n == 1)
        return matrixA[0][0];
    float temp[N][N]; 
    int sign = 1; 
    for (int f = 0; f < n; f++) 
    {
        Minor(matrixA, temp, 0, f, n);
        D += sign * matrixA[0][f]* Determinant(temp, n - 1);
        sign = -sign;
    }
 
    return D;
}

void Cramer(float matrixA[N][N], float matrixB[N], float matrixX[N]) {
    float detMatrix = Determinant(matrixA, N);
    if (detMatrix == 0) {
        printf("Система не має єдиного розв'язку (визначник дорівнює нулю).\n");
        return;
    }
    float temp[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                temp[j][k] = matrixA[j][k];
            }
        }
        for (int j = 0; j < N; j++) {
            temp[j][i] = matrixB[j];
        }
        matrixX[i] = Determinant(temp, N) / detMatrix;
    }
}

void Gauss(float matrixA[N][N], float matrixB[N], float matrixX[N]) {
    for (int i = 0; i < N; i++) {
        int maxRow = i;
        for (int k = i + 1; k < N; k++) {
            if (fabs(matrixA[k][i]) > fabs(matrixA[maxRow][i])) {
                maxRow = k;
            }
        }
        for (int k = 0; k < N; k++) {
            float tmp = matrixA[maxRow][k];
            matrixA[maxRow][k] = matrixA[i][k];
            matrixA[i][k] = tmp;
        }
        float tmp = matrixB[maxRow];
        matrixB[maxRow] = matrixB[i];
        matrixB[i] = tmp;
        for (int k = i + 1; k < N; k++) {
            float factor = matrixA[k][i] / matrixA[i][i];
            for (int j = i; j < N; j++) {
                matrixA[k][j] -= factor * matrixA[i][j];
            }
            matrixB[k] -= factor * matrixB[i];
        }
    }
    for (int i = N - 1; i >= 0; i--) {
        matrixX[i] = matrixB[i];
        for (int j = i + 1; j < N; j++) {
            matrixX[i] -= matrixA[i][j] * matrixX[j];
        }
        matrixX[i] /= matrixA[i][i];
    }
}

void GaussJordan(float matrixA[N][N], float matrixB[N], float matrixX[N]) {
    for (int i = 0; i < N; i++) {
        int maxRow = i;
        for (int k = i + 1; k < N; k++) {
            if (fabs(matrixA[k][i]) > fabs(matrixA[maxRow][i])) {
                maxRow = k;
            }
        }
        for (int k = 0; k < N; k++) {
            float tmp = matrixA[maxRow][k];
            matrixA[maxRow][k] = matrixA[i][k];
            matrixA[i][k] = tmp;
        }
        float tmp = matrixB[maxRow];
        matrixB[maxRow] = matrixB[i];
        matrixB[i] = tmp;
        float diag = matrixA[i][i];
        for (int j = 0; j < N; j++) {
            matrixA[i][j] /= diag;
        }
        matrixB[i] /= diag;
        for (int k = 0; k < N; k++) {
            if (k != i) {
                float factor = matrixA[k][i];
                for (int j = 0; j < N; j++) {
                    matrixA[k][j] -= factor * matrixA[i][j];
                }
                matrixB[k] -= factor * matrixB[i];
            }
        }
    }
    for (int i = 0; i < N; i++) {
        matrixX[i] = matrixB[i];
    }
}

void DisplayMatrix(float matrix[N][N], int row, int col)
{
    for (int i = 0; i < row; i++) 
    {
        for (int j = 0; j < col; j++){printf("\t|%.0f", matrix[i][j]);}
        printf("\n");
    }
}

void DisplayVector(float matrixB[N], int size)
{
    for (int i = 0; i < size; i++) {
        printf("\t|%.1f\n", matrixB[i]);
    }
}

int main()
{
    int choice;
    float matrixA[N][N] = {{1, 3, -7, 4, 5},
                            {3, -1, -2, 6, 12},
                            {-3, -1, 3, 6, 5},
                            {3, -10, -2, 4, 4},
                            {4, -1, -41, 6, -3}};
    float matrixB[N] = {1.1, -2, 3, -4, 52};
    float matrixX[N];

    printf("\nМатриця A:\n");
    DisplayMatrix(matrixA, N, N);
    printf("\nМатриця B:\n");
    DisplayVector(matrixB, N);
    printf("\nДетермінант: %d", Determinant(matrixA, N));

    do{
        printf("\n________________________________________\n--Меню--\n1. Крамера\n2. Гаусс\n3. Гаусс-Джордана\n4. Вихід\nЗробіть вибір: ");
        scanf("%d", &choice);
        printf("________________________________________");
        switch (choice){
            case 1:
                Cramer(matrixA, matrixB, matrixX);
                printf("\nРозв'язок СЛАР за методом Крамера:\n");
                for (int i = 0; i < N; i++) {
                    printf("|%f\t|\n", matrixX[i]);
                }
                break;
            case 2:
                Gauss(matrixA, matrixB, matrixX);
                printf("\nРозв'язок СЛАР за методом Гаусса:\n");
                for (int i = 0; i < N; i++) {
                    printf("|%f\t|\n", matrixX[i]);
                }
                break;
            case 3:
                GaussJordan(matrixA, matrixB, matrixX);
                printf("\nРозв'язок СЛАР за методом Гаусса-Жордана:\n");
                for (int i = 0; i < N; i++) {
                    printf("|%f\t|\n", matrixX[i]);
                }
                break;
            case 4:
                printf("\nВихід...\n");
                break;
            default:
                printf("\nНеправильний вибір.\n");
                break;
            }
    } while (choice != 4);

    return 0;
}