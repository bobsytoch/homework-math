#include <stdio.h>
#include <math.h>

double function_exp(double x) {
    return exp(2*x + 6) / (pow(x, 5) - 7);
}

double function_lagrange(double x[], double y[], int n, double X) {
    double result = 0.0;
    for (int i = 0; i < n; i++) {
        double term = y[i];
        for (int j = 0; j < n; j++) {
            if (j != i) {
                term *= (X - x[j]) / (x[i] - x[j]);
            }
        }
        result += term;
    }
    return result;
}

int main() {
    int choice;
    double a = -1.0;
    double b = 3.0;
    double h = 0.7;
    int n = (int)((b - a) / h) + 1;
    double x[n], y[n];
    double L;
    do{
        printf("\n\n--Меню--:\n1.Прямий путь\n2.Через функцію Лагранжа\n3.Вихід\nВаш вибір: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("\n--Лабораторна робота №1--\nЗавдання №15\ny=(e^2x+6)/((x^5)-7)\nВідрізок інтерполяції [a,b] = [-1,3]\nКрок інтерполяції h = [0.7]\n\n");
                for(double x = a; x <= b; x += h) {
                    function_exp(x);
                    printf("При х = %.2lf, y = %.2lf\n", x, function_exp(x));
                }
                break;
            case 2:
                for (int i = 0; i < n; i++) {
                    x[i] = a + i * h;
                    y[i] = function_exp(x[i]);
                }
                printf("Введіть х = ");
                scanf("%lf", &L);
                printf("При х = %.2lf, y = %.2lf\n", L, function_lagrange(x, y, n, L));
                break;
            case 3:
                printf("Вихід з програми...\n");
                break;
            default:
                printf("Неправильний вибір. Спробуйте ще раз.\n");
                break;
        }
    }while (choice != 3);
    return 0;
}