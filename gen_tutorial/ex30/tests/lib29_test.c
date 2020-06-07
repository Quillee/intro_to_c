#include "../src/minunit.h"
#include "ctype.h"
#include "dlfcn.h"


char *lib_file = "./build/my_lib.a";
void *lib = NULL;


void before() {
    lib = dlopen(lib_file, RTLD_LAZY);
}

void after() {
    check(0 != dlclose(lib), "[ERROR] while closing library");
    error:
    printf("THROWING FROM AFTER");
}

char *test_dlopen() {
    void *lib = dlopen(lib_file, RTLD_LAZY);
    check(lib == NULL, "Failed to open library");
    check(0 != dlclose(lib), "Failed to close library");
    return NULL;
error:
    return "FAILED";
}

char *test_functions() {
    void *lib = dlopen(lib_file, RTLD_LAZY);
    check(lib == NULL, "Failed to open library");
    check(0 != dlclose(lib), "Failed to close library");
    return NULL;
error:
    return "FAILED";
}

char *test_failures() {
    return NULL;
}

char *test_dlclose() {
    return NULL;
}

char *all_tests() {
    mu_suite_start();

    mu_run_test(test_dlopen);
    mu_run_test(test_functions);
    mu_run_test(test_failures);
    mu_run_test(test_dlclose);

    return NULL;
}

RUN_TESTS(all_tests)