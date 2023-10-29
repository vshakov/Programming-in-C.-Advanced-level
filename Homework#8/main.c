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
    double x1 = -2.0;
    double eps = 0.000001;

    double intersections[9]; // Array to store the intersections
    int index = 0; // Index to keep track of the current position in the array

    // Find intersections and store them in the array
    intersections[index++] = findIntersectionChord(f1, f2, x0, x1, eps);
    intersections[index++] = findIntersectionChord(f2, f3, x0, x1, eps);
    intersections[index++] = findIntersectionChord(f1, f3, x0, x1, eps);

    x0 = -2.0;
    x1 = 1.0;

    intersections[index++] = findIntersectionChord(f1, f2, x0, x1, eps);
    intersections[index++] = findIntersectionChord(f2, f3, x0, x1, eps);
    intersections[index++] = findIntersectionChord(f1, f3, x0, x1, eps);

    x0 = 1.0;
    x1 = 10.0;

    intersections[index++] = findIntersectionChord(f1, f2, x0, x1, eps);
    intersections[index++] = findIntersectionChord(f2, f3, x0, x1, eps);
    intersections[index++] = findIntersectionChord(f1, f3, x0, x1, eps);

    // Sort the intersections in ascending order
    for (int i = 0; i < index - 1; i++) {
        for (int j = i + 1; j < index; j++) {
            if (intersections[i] > intersections[j]) {
                double temp = intersections[i];
                intersections[i] = intersections[j];
                intersections[j] = temp;
            }
        }
    }

    // Print the sorted intersections without duplicates
    printf("Sorted intersections without duplicates:\n");
    if (index > 0) {
        printf("%lf\n", intersections[0]);
        for (int i = 1; i < index; i++) {
            if (fabs(intersections[i] - intersections[i - 1]) > eps) {
                printf("%lf\n", intersections[i]);
            }
        }
    }

    return 0;
}