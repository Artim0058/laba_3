#include <stdio.h>
#include "stack_container.h"
int main() {
    Stack* stack = stack_create();
    Publication p = {"Тест", "Иванов", "А.А.", "Журнал", 2023, 1, true, 10, 5};
    
    printf("Тестирование стека...\n");
    stack_push(stack, &p);
    printf("Размер стека: %d\n", stack_size(stack));
    
    Publication* popped = stack_pop(stack);
    if (popped) printf("Извлечено: %s\n", popped->title);
    
    stack_destroy(stack);
    return 0;
}