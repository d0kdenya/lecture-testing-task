#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "stack.h"

#define N 1000000

void benchmark_push(Stack* stack) {
    clock_t start, end;
    double cpu_time_used;

    printf("Running benchmark for push()...\n");
    start = clock();
    for (int i = 0; i < N; i++) {
        push(stack, i);
    }
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("push(): Time taken for %d operations: %f seconds\n", N, cpu_time_used);
}

void benchmark_pop(Stack* stack) {
    clock_t start, end;
    double cpu_time_used;

    printf("Running benchmark for pop()...\n");
    start = clock();
    for (int i = 0; i < N; i++) {
        pop(stack);
    }
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("pop(): Time taken for %d operations: %f seconds\n", N, cpu_time_used);
}

int main() {
    Stack stack;
    initStack(&stack);

    benchmark_push(&stack);
    benchmark_pop(&stack);
    destroyStack(&stack);

    return 0;
}
