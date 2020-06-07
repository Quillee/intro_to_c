#include <stdlib.h>

typedef struct {
    int *elems;
    int logical_len;
    int allocated_len;
} Stack;

void stack_new(Stack *s);
void stack_dispose(Stack *s);
void stack_push(Stack *s, int value);
int stack_pop(Stack *s);