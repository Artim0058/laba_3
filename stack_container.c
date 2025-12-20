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