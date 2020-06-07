#include "darray.h"

DArray *darray_create(DArray *self, size_t element_size, size_t initial_max) {

}

DArray *darray_create_new(size_t element_size, size_t initial_max) {

}

void darray_destroy(DArray *array) {

}

void darray_clear(DArray *array);

int darray_expand(DArray *array);

int darray_contract(DArray *array);

int darray_push(DArray array, void *elem);

void *darray_pop(DArray *array);

void darray_clear_destroy(DArray *array);