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
    if (x != 0) {
        return 3 / x;
    } else 
    {
        // Обработка случая деления на ноль
        // Например, можно вернуть бесконечность (infinity)
        return INFINITY;
    }
}

// Функция для вычисления площади методом прямоугольников
double calculateArea(double a, double b, double epsilon) 
{
    double dx = epsilon; // Шаг интегрирования
    double x, y1, y2, y3, area = 0;

    for (x = a; x <= b; x += dx) 
    {
        y1 = f1(x);
        y2 = f2(x);
        y3 = f3(x);

        // Находим минимальное значение y
        double minY = y1;
        if (y2 < minY) minY = y2;
        if (y3 < minY) minY = y3;

        // Находим максимальное значение y
        double maxY = y1;
        if (y2 > maxY) maxY = y2;
        if (y3 > maxY) maxY = y3;

        area += (maxY - minY) * dx; // Площадь прямоугольника
    }

    return area;
}

int main() {
    double a, b, epsilon;

    printf("Введите начальное значение x (a): ");
    scanf("%lf", &a);

    printf("Введите конечное значение x (b): ");
    scanf("%lf", &b);

    printf("Введите точность (epsilon): ");
    scanf("%lf", &epsilon);

    double area = calculateArea(a, b, epsilon);

    printf("Площадь фигуры: %lf\n", area);

    return 0;
}

/* Программа запрашивает начальное и конечное значения x, 
а также точность (ε) у пользователя. 
Затем она использует метод прямоугольников для вычисления площади фигуры, 
ограниченной заданными кривыми, с заданной точностью. 
Результат выводится на экран. */