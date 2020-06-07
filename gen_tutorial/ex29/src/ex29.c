#include <stdio.h>
#include <ctype.h>
#include <dlfcn.h>
#include "../../lib/dbg.h"

typedef int (*lib_function)(const char* data, int size);

int main(int argc, char const *argv[]) {
    int rc = 0;
    check(argc == 4, "Usage: ex29 libex29.so [function_data]");

    char *lib_file = argv[1];
    char *func_to_run = argv[2];
    char *data = argv[3];

    void *lib = dlopen(lib_file, RTLD_NOW);
    check(lib != NULL, "Failed to opent the library %s: %s", lib_file, dlerror());
    lib_function func = dlsym(lib, func_to_run);
    check(func != NULL, "Did not find %s function in the lib %s : %s", func_to_run, lib_file, dlerror);

    rc = func(data, sizeof(data) / sizeof(char));
    check(rc == 0, "Function %s return %d for data: %s", func_to_run, rc, data);
    rc = dlclose(lib);
    check(rc == 0, "Failed to close %s", lib_file);

    return 0;
error:
    return -1;
}
