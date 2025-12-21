#include "stack_container.h"
#include <stdlib.h>
Stack* stack_create() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (stack) stack->top = NULL, stack->size = 0;
    return stack;
}
void stack_push(Stack* stack, const Publication* data) {
    if (!stack) return;
    StackNode* node = (StackNode*)malloc(sizeof(StackNode));
    if (node) {
        node->data = *data;
        node->next = stack->top;
        stack->top = node;
        stack->size++;
    }
}
void stack_destroy(Stack* stack) {
    if (!stack) return;
    while (stack->top) {
        StackNode* temp = stack->top;
        stack->top = stack->top->next;
        free(temp);
    }
    free(stack);
}
Publication* stack_pop(Stack* stack) {
    if (!stack || !stack->top) return NULL;
    StackNode* temp = stack->top;
    static Publication result;
    result = temp->data;
    stack->top = temp->next;
    free(temp);
    stack->size--;
    return &result;
}
int stack_size(const Stack* stack) {
    return stack ? stack->size : 0;
}
Publication* stack_get_at(const Stack* stack, int index) {
    if (!stack || index < 0 || index >= stack->size) return NULL;
    StackNode* current = stack->top;
    for (int i = 0; i < index && current; i++) current = current->next;
    return current ? &current->data : NULL;
}
void stack_insert_at(Stack* stack, int index, const Publication* data) {
    if (!stack || index < 0 || index > stack->size) return;
    if (index == 0) { stack_push(stack, data); return; }
    StackNode* current = stack->top;
    for (int i = 0; i < index - 1 && current; i++) current = current->next;
    if (!current) return;
    StackNode* node = (StackNode*)malloc(sizeof(StackNode));
    if (node) {
        node->data = *data;
        node->next = current->next;
        current->next = node;
        stack->size++;
    }
}
void stack_remove_at(Stack* stack, int index) {
    if (!stack || index < 0 || index >= stack->size) return;
    if (index == 0) { stack_pop(stack); return; }
    StackNode* current = stack->top;
    for (int i = 0; i < index - 1 && current; i++) current = current->next;
    if (!current || !current->next) return;
    StackNode* temp = current->next;
    current->next = temp->next;
    free(temp);
    stack->size--;
}
void stack_swap(Stack* stack, int i, int j) {
    if (!stack || i < 0 || j < 0 || 
        i >= stack->size || j >= stack->size || i == j) return;
    if (i > j) { int t = i; i = j; j = t; }
    Publication* a = stack_get_at(stack, i);
    Publication* b = stack_get_at(stack, j);
    if (a && b) {
        Publication temp = *a;
        *a = *b;
        *b = temp;
    }
}
void stack_clear(Stack* stack) {
    if (!stack) return;
    while (stack->top) {
        StackNode* temp = stack->top;
        stack->top = stack->top->next;
        free(temp);
    }
    stack->size = 0;
}
Publication* stack_begin(Stack* stack) {
    return stack && stack->top ? &stack->top->data : NULL;
}
Publication* stack_end(Stack* stack) { return NULL; }
Publication* stack_next(Stack* stack, Publication* current) {
    if (!stack || !current) return NULL;
    StackNode* node = stack->top;
    while (node && &node->data != current) node = node->next;
    return node && node->next ? &node->next->data : NULL;
}
Publication* stack_prev(Stack* stack, Publication* current) {
    if (!stack || !current || !stack->top) return NULL;
    if (&stack->top->data == current) return NULL;
    StackNode* prev = NULL;
    StackNode* node = stack->top;
    while (node && &node->data != current) {
        prev = node;
        node = node->next;
    }
    return prev ? &prev->data : NULL;
}
Publication* stack_to_array(const Stack* stack) {
    if (!stack || !stack->size) return NULL;
    Publication* arr = malloc(sizeof(Publication) * stack->size);
    if (!arr) return NULL;
    StackNode* current = stack->top;
    for (int i = stack->size - 1; i >= 0 && current; i--) {
        arr[i] = current->data;
        current = current->next;
    }
    return arr;
}
Stack* array_to_stack(const Publication* arr, int n) {
    Stack* stack = stack_create();
    if (!stack) return NULL;
    for (int i = n - 1; i >= 0; i--) stack_push(stack, &arr[i]);
    return stack;
}