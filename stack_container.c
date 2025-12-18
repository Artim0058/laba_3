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