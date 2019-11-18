#include "stdio.h"
#include "dlfcn.h"
#include "string.h"

#include "../../lib/dbg.h"

typedef int (*lib_function) (const char* data, int len);

int main (int argc, char *argv[]) {
    int rc = 0;
    check(argc == 4, "USAGE: ex29 libex29.so function data");

    char *lib_file = argv[1];
    char *func_to_run = argv[2];
    char *data = argv[3];

    void *lib = dlopen(lib_file, RTLD_LAZY);

    check(lib != NULL, "Failed to open library file %s: %s", lib_file, dlerror());
    lib_function func = dlsym(lib, func_to_run);
    check(func != NULL, "Did not find %s function in the library %s: %s", func_to_run, lib_file, dlerror());

    rc = func(data, strlen(data));

    check(rc == 0, "Successfully ran function, %s. returned %d for data %s", func_to_run, rc, data)

    rc = dlclose(lib);
    check(rc == 0, "Failed to close file %s", lib_file);

    printf("-----------Entering test mode------------\n");
    printf("testing sizeof vs strlen\n\n");
    printf("strlen function applied to data: \ndata: %s\nlen: %zu\n\n", data, strlen(data));
    // sizeof returns the amount of space the data pointer takes up. I'd have to go through the
    //      string and add up the sizeof operations on each
    printf("sizeof function applied to data: \ndata: %s\nlen: %zu\n\n", data, sizeof(data));
    return 0;
error:
    return 1;
}