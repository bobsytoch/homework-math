public class Main {
    public static void main(String[] args) {
        // Значення x від 0 до 7 включно з кроком 0.5
        int size = 15;
        double[] xValues = new double[size];
        double[] yValues = new double[size];

        // Заповнюємо масиви значеннями x та y, де y = 5 * exp(x^3 - 1)
        for (int i = 0; i < size; i++) {
            xValues[i] = i * 0.5;
            yValues[i] = calculateFunction(xValues[i]);
        }

        System.out.println("Функція: y(x) = 5 * exp(x^3 - 1)\n");

        // Обчислення інтерполяції та вивід для кожного значення x
        for (int i = 0; i < size; i++) {
            double x = xValues[i];
            double actualValue = yValues[i];
            double interpolatedValue = lagrangeInterpolation(xValues, yValues, x);

            System.out.printf("При x = %.1f\n", x);
            System.out.printf("f(%.1f) = %.5f\n", x, actualValue);
            System.out.printf("Інтерполяція = %.5f\n\n", interpolatedValue);
        }
    }

    // Функція для обчислення y(x) = 5 * exp(x^3 - 1)
    public static double calculateFunction(double x) {
        return 5 * Math.exp(Math.pow(x, 3) - 1);
    }

    // Метод для обчислення значення полінома Лагранжа
    public static double lagrangeInterpolation(double[] xValues, double[] yValues, double x) {
        double result = 0.0;
        int n = yValues.length;

        for (int k = 0; k < n; k++) {
            double term = yValues[k];
            for (int j = 0; j < n; j++) {
                if (j != k) {
                    term *= (x - xValues[j]) / (xValues[k] - xValues[j]); // Розраховуємо поліном
                }
            }
            result += term; // Додаємо вклад в результат
        }
        return result;
    }
}
