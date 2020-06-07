#include "stack.h"

void stack_new(Stack *s) {
    s->logical_len = 0;
    s->allocated_len = 4;
    s->elems = malloc(4 * sizeof(int));
    assert(s->elems != NULL);
}

void stack_dispose(Stack *s) {
    if (s) {
        free(s);
    }
}

void stack_push(Stack *s, int value) {
    if (s->logical_len == s->allocated_len) {
        s->allocated_len *= 2;
        int *temp_s = s->elems;
        s->elems = malloc(s->allocated_len * sizeof(int));
        // deep copy
        for (int i =0; i < s->logical_len; i++) {
            s->elems[i] = temp_s[i];
        }
        free(temp_s);
    }
    s->elems[s->logical_len++] = value;
}

int stack_pop(Stack *s) {
    return s->elems[s->logical_len--];
}