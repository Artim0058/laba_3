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