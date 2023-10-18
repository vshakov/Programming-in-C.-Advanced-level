#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

// Функции для кривых
double f1(double x) 
{
    return 0.6 * x + 3;
}

double f2(double x) 
{
    return pow(x - 2, 3) - 1;
}

double f3(double x) 
{
    if (x != 0) 
    {
        return 3 / x;
    } else 
    {
        // Обработка случая деления на ноль
        // Например, можно вернуть бесконечность (infinity)
        return INFINITY;
    }
}

// Функция для вычисления площади методом прямоугольников
double calculateArea(double a, double b, int numIntervals) {
    double dx = (b - a) / numIntervals;
    double x, y1, y2, y3, area = 0;

    for (x = a; x < b; x += dx) {
        y1 = f1(x);
        y2 = f2(x);
        y3 = f3(x);

        double minY = y1;
        if (y2 < minY) minY = y2;
        if (y3 < minY) minY = y3;

        double maxY = y1;
        if (y2 > maxY) maxY = y2;
        if (y3 > maxY) maxY = y3;

        area += (maxY - minY) * dx;
    }

    return area;
}

int main() {
    double a, b;
    int numIntervals;

    printf("Введите начальное значение x (a): ");
    scanf("%lf", &a);

    printf("Введите конечное значение x (b): ");
    scanf("%lf", &b);

    printf("Введите количество интервалов: ");
    scanf("%d", &numIntervals);

    double area = calculateArea(a, b, numIntervals);

    printf("Площадь фигуры: %lf\n", area);

    return 0;
}

/* Программа запрашивает начальное и конечное значения x, 
а также точность (ε) у пользователя. 
Затем она использует метод прямоугольников для вычисления площади фигуры, 
ограниченной заданными кривыми, с заданной точностью. 
Результат выводится на экран. */