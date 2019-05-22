// Not the main file like normal
// instead, a source file that will be come the object file, ex22.o which will have some functions and varaiables in it defined from ex22.h

#include <stdio.h>
#include "dbg.h"
#include "ex22.h"

int THE_SIZE = 1000;

static int THE_AGE = 37;

// gets and sets an internal static variable in ex22.c
int get_age() {
    return THE_AGE;
}
void set_age(int age) {
    THE_AGE = age;
}

// updates a static var that's inside update_ratio
double update_ratio(double ratio) {
    static double static_ratio = 1.;
    double old_ratio = static_ratio;
    static_ratio = ratio;
    return old_ratio;
}

void print_size() {
    log_info("I think size is: %d", THE_SIZE);
}
