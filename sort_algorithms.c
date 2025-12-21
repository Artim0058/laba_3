#include "sort_algorithms.h"
void insertion_sort(void* container,
                   void* (*get_at)(void*, int),
                   void (*swap)(void*, int, int),
                   int size,
                   Comparator cmp) {
    for (int i = 1; i < size; i++) {
        int j = i;
        while (j > 0) {
            Publication* a = get_at(container, j - 1);
            Publication* b = get_at(container, j);
            if (cmp(a, b) > 0) {
                swap(container, j - 1, j);
                j--;
            } else break;
        }
    }
}