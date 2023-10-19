#include <stdio.h>
#include <math.h>

double f1(double x) {
    return 0.6 * x + 3;
}

double f2(double x) {
    return 3 * (x - 2) - 1;
}

double f3(double x) {
if (x != 0) {
return 3 / x;
} else {
return 0; // Здесь можно вернуть любое другое значение, которое соответствует вашей логике
}
}

double calculate_area(double lower_limit, double upper_limit) {
    double area = 0;
    double dx = 0.0001;  // Шаг интегрирования

    for (double x = lower_limit; x < upper_limit; x += dx) {
        double height = fmin(fmin(f1(x), f2(x)), f3(x));
        area += height * dx;
    }

    return area;
}

int main() {
    // Пересечения с осью x
    double x_intersection_f1 = -3 / 0.6;
    double x_intersection_f2 = 2;
    double x_intersection_f3 = 0;

    // Пересечения с осью y
    double y_intersection_f1 = f1(0);
    double y_intersection_f2 = f2(0);
    double y_intersection_f3 = f3(0);

    printf("Пересечения с осью x:\n");
    printf("f1: x = %lf\n", x_intersection_f1);
    printf("f2: x = %lf\n", x_intersection_f2);
    printf("f3: x = %lf\n", x_intersection_f3);

    printf("\nПересечения с осью y:\n");
    printf("f1: y = %lf\n", y_intersection_f1);
    printf("f2: y = %lf\n", y_intersection_f2);
    printf("f3: y = %lf\n", y_intersection_f3);

     // Определение пределов интегрирования
    double lower_limit = fmax(fmax(x_intersection_f1, x_intersection_f2), x_intersection_f3);
    double upper_limit = fmin(fmin(x_intersection_f1, x_intersection_f2), x_intersection_f3);

    // Вычисление площади фигуры
    double area = calculate_area(lower_limit, upper_limit);

    printf("Площадь фигуры: %lf\n", area);

    return 0;
}