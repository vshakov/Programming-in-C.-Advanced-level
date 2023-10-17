#include <stdio.h>
#include <time.h>

typedef void (*FunctionPointer)();

double measure_time(FunctionPointer test_function);
void example_function();

double measure_time(FunctionPointer test_function) 
{
    clock_t start_time, end_time;
    double execution_time;

    start_time = clock();
    test_function();
    end_time = clock();
    execution_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC * 1000.0;

    return execution_time;
}
