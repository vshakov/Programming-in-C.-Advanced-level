#include <stdio.h>
#include "timer.h"

void test_function();

int main() {
    double execution_time = measure_time(test_function);
    printf("Время выполнения: %.2f миллисекунд\n", execution_time);
    return 0;
}