#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct stack  {
    int capacity;
    int size;
    char** items;
} stack;

struct stack* stack_init(int cap){    
    struct stack *temp_s = malloc(sizeof (struct stack));
    temp_s->size = -1;
    temp_s->capacity = cap;
    temp_s->items =  (char**) malloc(sizeof(char**) * cap);
    
    return temp_s;
}

struct stack* stack_init_empty(){    
    struct stack *temp_s = malloc(sizeof (struct stack));
    temp_s->size = -1;
    temp_s->capacity = 2;
    temp_s->items =  (char**) malloc(sizeof(char**) * 2);
    return temp_s;
}

_Bool stack_is_empty(struct stack *s){ return s->size == -1; }

_Bool stack_is_full(struct stack *s) { return s->size == s->capacity; }

char* stack_pop(struct stack *s){
    if(stack_is_empty(s))
        return "";
    
    char *temp = s->items[s->size];
    s->items[s->size--] = "";
    return temp;
    
}

void stack_push(struct stack *s, char* new_item){
    s->size++; // since size is actually the index of the stack increment before checking if full
    if(stack_is_full(s)){
        s->capacity *= 2;
        char ** temp_items = (char**) malloc(sizeof(char**) * s->capacity);
        for(int i = 0;i < s->size; ++i){
            temp_items[i] = s->items[i];
        }
        s->items = temp_items;
    }
    
    s->items[s->size] = new_item;    
}

char* stack_peek(struct stack *s){
    if(!stack_is_empty(s))
        return s->items[s->size];
    return "";
}

void stack_destroy(struct stack *s){
    for(int i = 0; i < s->capacity; ++i){
        free(s->items[i]);
    }
    free(s);
}

int main(int argc, char const *argv[])
{
    struct stack *name_stack = stack_init(50);
    char *names[] = {
        "AsBelow",
        "SoAbove"
    };

    const int MAX_SIZE = 100000;

    for(int i = 0; i < MAX_SIZE; ++i){
        stack_push(name_stack, names[i % 2]);
    }

    for(int i = 0 ; i < MAX_SIZE; ++i ){
        printf("Item number: %d => %s\n",i, stack_peek(name_stack));
        stack_pop(name_stack);
    }
    stack_destroy(name_stack);
    return 0;
}
