#pragma once
#include "pub.h"
typedef struct StackNode {
    Publication data;
    struct StackNode* next;
} StackNode;
typedef struct {
    StackNode* top;
    int size;
} Stack;
Stack* stack_create();
void stack_push(Stack* stack, const Publication* data);
Publication* stack_pop(Stack* stack);
int stack_size(const Stack* stack);
void stack_destroy(Stack* stack);

Publication* stack_get_at(const Stack* stack, int index);
void stack_insert_at(Stack* stack, int index, const Publication* data);
void stack_remove_at(Stack* stack, int index);
void stack_swap(Stack* stack, int i, int j);
void stack_clear(Stack* stack);
Publication* stack_to_array(const Stack* stack);
Stack* array_to_stack(const Publication* arr, int n);
Publication* stack_begin(Stack* stack);
Publication* stack_end(Stack* stack);
Publication* stack_next(Stack* stack, Publication* current);
Publication* stack_prev(Stack* stack, Publication* current);