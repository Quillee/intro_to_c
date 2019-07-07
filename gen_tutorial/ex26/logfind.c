#include "../lib/dbg.h"
#include <assert.h>

// I don't care... I would just use python for this so I'm moving on
void parse_searchable_file(char *contents[], char *keyword) {

}

void parse_searchable_dir(char *dir) {

}

/**
 * Dafuq?
 */
char* find_configured_locations() {
    return "";
}

int main(int argc, char const *argv[])
{
    check(argc > 1, "Arguments must include one keyword. The number of args you presented are %d", argc)

    return 0;
error:
    return 1;
}
