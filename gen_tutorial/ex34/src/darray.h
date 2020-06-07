#ifndef _DARRAY_H
#define _DARRAY_H

#include <stdlib.h>
#include <assert.h>
#include "../../lib/dbg.h"

typedef struct {
    int end;
    int max;
    size_t element_size;
    size_t expand_rate;
    void **contents;
} DArray;

DArray *darray_create(DArray *self, size_t element_size, size_t initial_max);

DArray *darray_create_new(size_t element_size, size_t initial_max);

void darray_destroy(DArray *array);

void darray_clear(DArray *array);

int darray_expand(DArray *array);

int darray_contract(DArray *array);

int darray_push(DArray array, void *elem);

void *darray_pop(DArray *array);

void darray_clear_destroy(DArray *array);

#define DARRAY_LAST(A) ((A)->contents[(A)->end - 1])
#define DARRAY_FIRST(A) ((A)->contents[0])
#define DARRAY_END(A) ((A)->end)
#define DARRAY_COUNT(A) DARRAY_END(A)
#define DARRAY_MAX(A) ((A)->max)
#define DARRAY_FREE(E) (free(E))

#define DEFAULT_EXPAND_RATE 300

static inline void darray_set(DArray *array, int i, void *el) {
    check(i < array->max, "attempt to set an element past the array's max");
    if (i > array->end){
        array->end = i;
    }
    array->contents[i] = el;
error:
    return;
}

static inline void *darray_get(DArray *array, int i) {
    check(i < array->max, "attempt to get past the array's max");
    return array->contents[i];
error:
    return NULL;
}

static inline void *darray_remove(DArray *array, int i) {
    void *el = array->contents[i];
    array->contents[i] = NULL;
    return el;
}

static inline void *darray_new(DArray *array) {
    check(array->element_size > 0, "Can't use darray_new on > 0 size darrays");

    return calloc(1, array->element_size);
error:
    return NULL;
}
#endif