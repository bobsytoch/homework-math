#include <stdio.h>
#include <math.h>

int main() {
    double y;
    for(float x = -1.0; x <= 3.0; x += 0.7) {
        y = exp(2*x + 6) / (pow(x, 5) - 7);
        printf("При x = %.1lf, y = %lf\n", x, y);
    }
}