#include <stdio.h>
#include <math.h>

typedef double (*function)(double);

double f1(double x) {
    return 0.6 * x + 3;
}

double f2(double x) {
    return pow(x - 2, 3) - 1;
}

double f3(double x) {
    return 3 / x;
}

double findIntersectionChord(function f1, function f2, double x0, double x1, double eps) {
    double y0 = f1(x0) - f2(x0);
    double y1 = f1(x1) - f2(x1);

    if (fabs(y1 - y0) < eps) {
        printf("Не удалось найти точку пересечения с заданной точностью.\n");
        return NAN;
    }

    double x, y;
    while (fabs(x1 - x0) > eps) {
        x = x0 - (x1 - x0) * y0 / (y1 - y0);
        y = f1(x) - f2(x);

        if (fabs(y) < eps) {
            printf("Найдена точка пересечения: x = %lf, y = %lf\n", x, f1(x));
            return x;
        }

        if (y0 * y < 0) {
            x1 = x;
            y1 = y;
        } else {
            x0 = x;
            y0 = y;
        }
    }

    printf("Не удалось найти точку пересечения с заданной точностью.\n");
    return NAN;
}

int main() {
    double x0 = -10.0;
    double x1 = -1.0;
    double eps = 0.000001;

    printf("Поиск точек пересечения функций f1(x) = 0.6*x + 3 и f2(x) = (x-2)^3 - 1 методом хорд в диапазоне от -10 до -1:\n");
    double intersection1 = findIntersectionChord(f1, f2, x0, x1, eps);

    printf("Поиск точек пересечения функций f2(x) = (x-2)^3 - 1 и f3(x) = 3/x методом хорд в диапазоне от -10 до -1:\n");
    intersection1 = findIntersectionChord(f2, f3, x0, x1, eps);

    printf("Поиск точек пересечения функций f1(x) = 0.6*x + 3 - 1 и f3(x) = 3/x методом хорд в диапазоне от -10 до -1:\n");
    intersection1 = findIntersectionChord(f1, f3, x0, x1, eps);

    x0 = -1.0;
    x1 = 1.0;
    printf("Поиск точек пересечения функций f1(x) = 0.6*x + 3 и f2(x) = (x-2)^3 - 1 методом хорд в диапазоне от -1 до 1:\n");
    double intersection2 = findIntersectionChord(f1, f2, x0, x1, eps);

    printf("Поиск точек пересечения функций f2(x) = (x-2)^3 - 1 и f3(x) = 3/x методом хорд в диапазоне от -1 до 1:\n");
    intersection2 = findIntersectionChord(f2, f3, x0, x1, eps);

    printf("Поиск точек пересечения функций f1(x) = 0.6*x + 3 - 1 и f3(x) = 3/x методом хорд в диапазоне от -1 до 1:\n");
    intersection2 = findIntersectionChord(f1, f3, x0, x1, eps);

    x0 = 1.0;
    x1 = 10.0;
    printf("Поиск точек пересечения функций f1(x) = 0.6*x + 3 и f2(x) = (x-2)^3 - 1 методом хорд в диапазоне от 1 до 10:\n");
    double intersection3 = findIntersectionChord(f1, f2, x0, x1, eps);

    printf("Поиск точек пересечения функций f2(x) = (x-2)^3 - 1 и f3(x) = 3/x методом хорд в диапазоне от 1 до 10:\n");
    intersection3 = findIntersectionChord(f2, f3, x0, x1, eps);

    printf("Поиск точек пересечения функций f1(x) = 0.6*x + 3 - 1 и f3(x) = 3/x методом хорд в диапазоне от 1 до 10:\n");
    intersection3 = findIntersectionChord(f1, f3, x0, x1, eps);

    return 0;
}