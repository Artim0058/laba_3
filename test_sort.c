#include <stdio.h>
#include <stdlib.h>
#include "stack_container.h"
#include "sort_algorithms.h"

void* get_at_wrapper(void* container, int index) {
    return stack_get_at((Stack*)container, index);
}

void swap_wrapper(void* container, int i, int j) {
    stack_swap((Stack*)container, i, j);
}

int cmp_wrapper(const Publication* a, const Publication* b) {
    return pub_compare(a, b, true);
}

int main() {
    Stack* stack = stack_create();
    Publication pubs[3] = {
        {"Статья C", "Иванов", "А.А.", "Журнал", 2021, 1, true, 10, 5},
        {"Статья A", "Петров", "Б.Б.", "Журнал", 2023, 1, true, 10, 5},
        {"Статья B", "Сидоров", "В.В.", "Журнал", 2022, 1, true, 10, 5}
    };
    
    for (int i = 0; i < 3; i++) stack_push(stack, &pubs[i]);
    
    printf("До сортировки:\n");
    for (int i = 0; i < 3; i++) {
        Publication* p = stack_get_at(stack, i);
        if (p) printf("%d: %s (%d)\n", i, p->title, p->year);
    }
    
    insertion_sort(stack, get_at_wrapper, swap_wrapper, 
                  stack_size(stack), cmp_wrapper);
    
    printf("\nПосле сортировки:\n");
    for (int i = 0; i < 3; i++) {
        Publication* p = stack_get_at(stack, i);
        if (p) printf("%d: %s (%d)\n", i, p->title, p->year);
    }
    
    stack_destroy(stack);
    return 0;
}