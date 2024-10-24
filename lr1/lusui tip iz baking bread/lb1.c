#include <stdio.h>
#include <math.h>

double function_exp(double a, double b, double h) {
    double y;
    double x;
    for(x = a; x <= b; x += h) {
        y = exp(2*x + 6) / (pow(x, 5) - 7);
        printf("При x = %.1lf, y = %lf\n", x, y);
    }
}

int main() {
    int choice;
    double a, b, h;
    double a1 = -1.0;
    double b1 = 3.0;
    double h1 = 0.7;
    do{
        printf("--Меню--:\n1.Виконати функцію\n2.Вибрати свій відрізок інтерполяції та її крок\n3.Вихід\nВаш вибір: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("\n--Лабораторна робота №1--\nЗавдання №15\ny=(e^2x+6)/((x^5)-7)\nВідрізок інтерполяції [a,b] = [-1,3]\nКрок інтерполяції h = [0.7]\n\n");
                function_exp(a1, b1, h1);
                printf("\n");
                break;
            case 2:
                printf("Введіть відрізок інтерполяції(a(початок) пробіл b(кінець)): ");
                scanf("%lf %lf", &a, &b);
                printf("Введіть крок інтерполяції: ");
                scanf("%lf", &h);
                function_exp(a, b, h);
                break;
            case 3:
                printf("Вихід з програми...\n");
                break;
            default:
                printf("Неправильний вибір. Спробуйте ще раз.\n");
        }
    }while (choice != 3);
    return 0;
}