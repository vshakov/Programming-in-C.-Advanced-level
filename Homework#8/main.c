#include <stdio.h>
#include <math.h>

double f1(double x) {
    return 0.6 * x + 3;
}

double f2(double x) {
    return pow(x - 2, 3) - 1;
}

double f3(double x) {
    if (x != 0) {
        return 3 / x;
    } else {
        // Обработка случая деления на ноль
        return INFINITY;  // Или любое другое значение, указывающее на отсутствие результата
    }
}

void find_intersections() {
    double epsilon = 0.00001;  // Погрешность для определения пересечений
    
    // Перебор значений x в заданном диапазоне и проверка пересечений между функциями
    for (double x = -10; x <= 10; x += epsilon) {
        // Исключаем точку x = 0 при проверке с функцией f3(x)

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
       

        
    }
}

double find_intersection_f2_f3() {
    double epsilon = 0.00001;  // Погрешность для определения пересечения
    double x0 = -10.0;         // Начальное приближение
    double x1 = 10.0;          // Вторая точка для метода хорд
    double x = 0.0;            // Инициализация переменной для точки пересечения

    // Итерационный метод хорд
    while (fabs(x1 - x0) > epsilon) {
        double y0 = f2(x0) - f3(x0);
        double y1 = f2(x1) - f3(x1);

        x = x1 - (y1 * (x1 - x0)) / (y1 - y0);

        double y = f2(x) - f3(x);

        if (fabs(y) <= epsilon) {
            // Найдена точка пересечения с заданной погрешностью
            return x;
        } else {
            // Обновление точек x0 и x1
            x0 = x1;
            x1 = x;
        }
    }

    // Точка пересечения не найдена с заданной точностью
    printf("Не удалось найти точку пересечения между f2(x) и f3(x) с заданной точностью.\n");
    return NAN;  // Возвращаем NaN в случае неудачи
}

int main() {
    find_intersections();

    double intersection = find_intersection_f2_f3();

    if (!isnan(intersection)) {
        printf("Точка пересечения f2(x) и f3(x): x = %lf\n", intersection);
    }

    return 0;
}