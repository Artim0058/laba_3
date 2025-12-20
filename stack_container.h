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