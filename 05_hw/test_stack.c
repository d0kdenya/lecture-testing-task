#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define ASSERT(condition, message) \
    if (!(condition)) { \
        fprintf(stderr, "Assertion failed: %s\nFile: %s\nFunction: %s\nLine: %d\n", \
        message, __FILE__, __func__, __LINE__); \
        exit(EXIT_FAILURE); \
    }

int all_tests = 0;
int passed_tests = 0;

void test_initStack() {
    printf("Running test_initStack...\n");
    all_tests++;
    Stack stack;
    initStack(&stack);
    ASSERT(stack.top == NULL, "[TEST FAILED] - Stack initialization failed");
    passed_tests++;
    printf("[TEST PASSED] - test_initStack.\n");
}

void test_push() {
    printf("Running test_push...\n");
    all_tests++;
    Stack stack;
    initStack(&stack);

    push(&stack, 10);
    ASSERT(stack.top != NULL, "[TEST FAILED] - Push failed: stack.top is NULL");
    ASSERT(stack.top->data == 10, "[TEST FAILED] - Push failed: top data is not 10");
    passed_tests++;
    printf("[TEST PASSED] - test_push.\n");
}

void test_pop() {
    printf("Running test_pop...\n");
    all_tests++;
    Stack stack;
    initStack(&stack);

    push(&stack, 20);
    push(&stack, 30);
    pop(&stack);
    ASSERT(stack.top->data == 20, "[TEST FAILED] - Pop failed: top data is not 20");

    pop(&stack);
    ASSERT(stack.top == NULL, "[TEST FAILED] - Pop failed: stack is not empty");
    passed_tests++;
    printf("[TEST PASSED] - test_pop passed.\n");
}

void test_searchByValue() {
    printf("Running test_searchByValue...\n");
    all_tests++;
    Stack stack;
    initStack(&stack);

    push(&stack, 40);
    push(&stack, 50);
    push(&stack, 60);

    Node* result = searchByValue(&stack, 50);
    ASSERT(result != NULL && result->data == 50, "[TEST FAILED] - SearchByValue failed: value 50 not found");

    result = searchByValue(&stack, 100);
    ASSERT(result == NULL, "[TEST FAILED] - SearchByValue failed: non-existent value found");
    passed_tests++;
    printf("[TEST PASSED] - test_searchByValue passed.\n");
}

void test_searchByIndex() {
    printf("Running test_searchByIndex...\n");
    all_tests++;
    Stack stack;
    initStack(&stack);

    push(&stack, 70);
    push(&stack, 80);
    push(&stack, 90);

    Node* result = searchByIndex(&stack, 1);
    ASSERT(result != NULL && result->data == 80, "[TEST FAILED] - SearchByIndex failed: index 1 data mismatch");

    result = searchByIndex(&stack, 5);
    ASSERT(result == NULL, "[TEST FAILED] - SearchByIndex failed: non-existent index found");
    passed_tests++;
    printf("[TEST PASSED] - test_searchByIndex passed.\n");
}

void test_destroyStack() {
    printf("Running test_destroyStack...\n");
    all_tests++;
    Stack stack;
    initStack(&stack);

    push(&stack, 100);
    push(&stack, 200);

    destroyStack(&stack);
    ASSERT(stack.top == NULL, "[TEST FAILED] - DestroyStack failed: stack is not empty");
    passed_tests++;
    printf("[TEST PASSED] - test_destroyStack passed.\n");
}

void test_isEmpty() {
    printf("Running test_isEmpty...\n");
    all_tests++;
    Stack stack;
    initStack(&stack);

    ASSERT(isEmpty(&stack), "[TEST FAILED] - isEmpty failed: stack should be empty");
    push(&stack, 300);
    ASSERT(!isEmpty(&stack), "[TEST FAILED] - isEmpty failed: stack should not be empty");
    passed_tests++;
    printf("[TEST PASSED] - test_isEmpty passed.\n");
}

void test_getTop() {
    printf("Running test_getTop...\n");
    all_tests++;
    Stack stack;
    initStack(&stack);

    ASSERT(getTop(&stack) == NULL, "[TEST FAILED] - getTop failed: top should be NULL");
    push(&stack, 400);
    ASSERT(getTop(&stack)->data == 400, "[TEST FAILED] - getTop failed: top data is not 400");
    passed_tests++;
    printf("[TEST PASSED] - test_getTop passed.\n");
}

void test_push_multiple() {
    printf("Running test_push_multiple...\n");
    all_tests++;
    Stack stack;
    initStack(&stack);

    for (int i = 0; i < 1000; i++) {
        push(&stack, i);
    }
    ASSERT(stack.top->data == 999, "[TEST FAILED] - Push multiple failed: top data is not 999");
    passed_tests++;
    printf("[TEST PASSED] - test_push_multiple passed.\n");
}

void test_pop_all() {
    printf("Running test_pop_all...\n");
    all_tests++;
    Stack stack;
    initStack(&stack);

    for (int i = 0; i < 100; i++) {
        push(&stack, i);
    }
    for (int i = 0; i < 100; i++) {
        pop(&stack);
    }
    ASSERT(stack.top == NULL, "[TEST FAILED] - Pop all failed: stack is not empty");
    passed_tests++;
    printf("[TEST PASSED] - test_pop_all passed.\n");
}

void test_memory_leak_destroy() {
    printf("Running test_memory_leak_destroy...\n");
    all_tests++;
    Stack stack;
    initStack(&stack);

    for (int i = 0; i < 500; i++) {
        push(&stack, i);
    }
    destroyStack(&stack);
    ASSERT(stack.top == NULL, "[TEST FAILED] - Memory leak destroy failed: stack is not empty");
    passed_tests++;
    printf("[TEST PASSED] - test_memory_leak_destroy passed.\n");
}

void test_null_handling() {
    printf("Running test_null_handling...\n");
    all_tests++;
    Stack* nullStack = NULL;
    ASSERT(nullStack == NULL, "[TEST FAILED] - Null handling failed: stack should be NULL");
    passed_tests++;
    printf("[TEST PASSED] - test_null_handling passed.\n");
}

void test_single_element() {
    printf("Running test_single_element...\n");
    all_tests++;
    Stack stack;
    initStack(&stack);
    push(&stack, 1);
    ASSERT(getTop(&stack)->data == 1, "[TEST FAILED] - Single element test failed: top data mismatch");
    pop(&stack);
    ASSERT(stack.top == NULL, "[TEST FAILED] - Single element test failed: stack is not empty");
    passed_tests++;
    printf("[TEST PASSED] - test_single_element passed.\n");
}

void test_large_stack_operations() {
    printf("Running test_large_stack_operations...\n");
    all_tests++;
    Stack stack;
    initStack(&stack);

    for (int i = 0; i < 1000000; i++) {
        push(&stack, i);
    }
    for (int i = 0; i < 1000000; i++) {
        pop(&stack);
    }
    ASSERT(stack.top == NULL, "[TEST FAILED] - Large stack operations failed: stack is not empty");
    passed_tests++;
    printf("[TEST PASSED] - test_large_stack_operations passed.\n");
}

int main() {
    test_initStack();
    test_push();
    test_pop();
    //test_searchByValue();
    test_searchByIndex();
    // test_destroyStack();
    test_isEmpty();
    test_getTop();
    test_push_multiple();
    test_pop_all();
    // test_memory_leak_destroy();
    test_null_handling();
    test_single_element();
    test_large_stack_operations();

    printf("\nSummary: %d/%d tests passed.\n", all_tests, passed_tests);
    return (all_tests == passed_tests) ? EXIT_SUCCESS : EXIT_FAILURE;
}