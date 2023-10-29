#include <stdio.h>
#include <math.h>

typedef double (*function)(double);

double f0(double x) {
    return 0;
}

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
            printf(" x = %lf, y = %lf\n", x, f1(x));
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

double calculateTrapezoidalAreaBetweenCurves(function f1, function f2, double a, double b, int numIntervals) {
    double area = 0.0;
    double intervalWidth = (b - a) / numIntervals;
    double x;
    for (x = a+intervalWidth; x<b-intervalWidth; x+=intervalWidth) {
        area += fabs(0.5*intervalWidth*((f1(x)+f1(x+intervalWidth))-(f2(x)+f2(x+intervalWidth))));
    }

    return area;
}

int main() {
    double x0 = -10.0;
    double x1 = -2.0;
    double eps = 0.000001;

    double intersections[20]; // Array to store the intersections
    int index = 0; // Index to keep track of the current position in the array

    // Find intersections and store them in the array
    printf ("Найдена точка пересечения f1(x) f2(x):");
    intersections[index++] = findIntersectionChord(f1, f2, x0, x1, eps);
    printf ("Найдена точка пересечения f2(x) f3(x):");
    intersections[index++] = findIntersectionChord(f2, f3, x0, x1, eps);
    printf ("Найдена точка пересечения f1(x) f3(x):");
    intersections[index++] = findIntersectionChord(f1, f3, x0, x1, eps);

    x0 = -2.0;
    x1 = 1.0;

    printf ("Найдена точка пересечения f1(x) f2(x):");
    intersections[index++] = findIntersectionChord(f1, f2, x0, x1, eps);
    printf ("Найдена точка пересечения f2(x) f3(x):");
    intersections[index++] = findIntersectionChord(f2, f3, x0, x1, eps);
    printf ("Найдена точка пересечения f1(x) f3(x):");
    intersections[index++] = findIntersectionChord(f1, f3, x0, x1, eps);

    x0 = 1.0;
    x1 = 10.0;

    printf ("Найдена точка пересечения f1(x) f2(x):");
    intersections[index++] = findIntersectionChord(f1, f2, x0, x1, eps);
    printf ("Найдена точка пересечения f2(x) f3(x):");
    intersections[index++] = findIntersectionChord(f2, f3, x0, x1, eps);
    printf ("Найдена точка пересечения f1(x) f3(x):");
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
int j = 0;
int count = 0;
if (index > 0) {
    for (int i = 0; i < index; i++) {
        if (fabs(intersections[i] - intersections[i - 1]) > eps) {
            intersections[j] = intersections[i];
            printf("Intersection %d: x = %lf\n", j+1, intersections[j]);
            
            j++;
            count++;
        }
    }
}

printf("Number of intersections is %d\n", count);

// Вычисляем площадь фигуры методом трапеции
double total_area = 0;
double small_area[count];
double a = 0;
double b = 0;
int numIntervals = 1000;

for ( j = 0; j < count; j++)
{
    a = intersections[j];
    b = intersections[j+1];
    if ((f1(intersections[j]) - f3(intersections[j]) < eps) && (f2(intersections[j+1]) - f3(intersections[j+1]) < eps) && f3(intersections[j]) < 0)
    {
        printf("f1 and f3\n");
        small_area[j] = calculateTrapezoidalAreaBetweenCurves(f1, f3, a, b, numIntervals);
    }

    if ((f1(intersections[j]) - f3(intersections[j]) < eps) && (f2(intersections[j+1]) - f3(intersections[j+1]) < eps) && f3(intersections[j]) > 0)
    {
        printf("f1 and f3\n");
        small_area[j] = calculateTrapezoidalAreaBetweenCurves(f1, f2, a, b, numIntervals);
    }

    if (f1(intersections[j]) - f2(intersections[j]) < eps)
    {
        printf("f1 and f2\n");
        small_area[j] = calculateTrapezoidalAreaBetweenCurves(f1, f2, a, b, numIntervals);
    }
    if ((f2(intersections[j]) - f3(intersections[j]) < eps) && (f1(intersections[j+1]) - f3(intersections[j+1]) < eps))
    {
        printf("f1 and f2\n");
        small_area[j] = calculateTrapezoidalAreaBetweenCurves(f1, f2, a, b, numIntervals);
    }
    if ((f2(intersections[j]) - f3(intersections[j]) < eps) && (f1(intersections[j+1]) - f2(intersections[j+1]) < eps))
    {
        printf("f1 and f2\n");
        small_area[j] = calculateTrapezoidalAreaBetweenCurves(f1, f2, a, b, numIntervals);
    }
    printf("a = %lf, b = %lf\n", a, b);
    printf("%lf\n", small_area[j]);
    total_area+=small_area[j];
}


printf("Площадь между кривыми f1, f2, f3: %lf\n", total_area);


    return 0;
}