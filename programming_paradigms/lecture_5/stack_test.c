#include <stdio.h>
#include "stack.h"

int main(int argc, char const *argv[])
{
    Stack s;
    stack_new(&s);

    for (int i = 0; i < 5; i++) {
        stack_push(&s, i);
    }

    for (int i = 0; i < 5; i++) {
        printf("Stack pop #%d: %d", i, stack_pop(&s));
    }
    stack_dispose(&s);
    return 0;
}
