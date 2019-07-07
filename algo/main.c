#include "all.h"
#include "../gen_tutorial/lib/dbg.h"

const int TOTAL_ARGS = 3;

void print_option_menu() {
    char *option_arr[] = {"%d) insertion sort\n"};
    printf("Algorithm menu: \n");
    printf("option_len: %d\n", (sizeof(option_arr) / sizeof(option_arr[0])));
    for (size_t i = 0; i < (sizeof(option_arr) / sizeof(option_arr[0])); ++i) {
        printf(option_arr[i], i);
    }
}

int main(int argc, char const *argv[])
{

    //check(argc > 3, "%d args are required", TOTAL_ARGS);
    print_option_menu();
    return 0;

error:
    return -1;
}
