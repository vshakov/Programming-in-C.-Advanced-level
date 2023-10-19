#include <stdio.h>
#include <math.h>

double f1(double x) {
    return 0.6 * x + 3;
}

double f2(double x) {
    return pow(x - 2, 3) - 1;
}

double f3(double x) {
    return 3 / x;
}

void find_intersections() {
    double epsilon = 0.00001;  // Погрешность для определения пересечений
    
    // Перебор значений x в заданном диапазоне и проверка пересечений между функциями
    for (double x = -10; x <= 10; x += epsilon) {
        // Исключаем точку x = 0 при проверке с функцией f3(x)
        if (x != 0) {
            double y1 = f1(x);
            double y2 = f2(x);
            double y3 = f3(x);

            // Проверка пересечения между функциями
            if (fabs(y1 - y2) <= epsilon) {
                printf("Точка пересечения f1(x) и f2(x): x = %lf\n", x);
            }

            if (fabs(y1 - y3) <= epsilon) {
                printf("Точка пересечения f1(x) и f3(x): x = %lf\n", x);
            }

            if (fabs(y2 - y3) <= epsilon) {
                printf("Точка пересечения f2(x) и f3(x): x = %lf\n", x);
            }
            

        }
    }
}

int main() {
    find_intersections();

    return 0;
}