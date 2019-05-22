// The actual mainthat will include the the other two and demonstrate what they contain, as well as other scope concepts

#include "ex22.h"
#include "dbg.h"

const char *MY_NAME = "Melvin Peralta";

void scope_demo(int count) {
    log_info("count is %d", count);
    if (count > 10) {
        //!@Alert: bugs incoming
        int count = 100; // this version of count only exists in this scope

        log_info("count in this scope is %d", count);
    }

    log_info("Count is at exit %d", count);

    count = 3000;
    log_info("Count after reassign %d", count);
}

int main(int argc, char const *argv[])
{
    // my name is "Melvin Peralta", age: "37"
    log_info("My name is: %s, age: %d", MY_NAME, get_age());
    set_age(100);

    // test out THE_SIZE extern
    // THE_SIZE is "1000"
    log_info("THE_SIZE is: %d", THE_SIZE);
    // 1000
    print_size();

    THE_SIZE = 9;

    // 9
    log_info("THE SIZE is now: %d", THE_SIZE);
    // 1000 -> @Incorrect: actually becomes 9
    print_size();

    // test the static ratio function
    log_info("Ratio at first: %f", update_ratio(2.0));
    log_info("Ratio again: %f", update_ratio(10.0));
    log_info("Ratio once more: %f", update_ratio(310.0));

    // test the scope demo
    int count = 4;
    scope_demo(count);
    scope_demo(count * 20);
    log_info("Count after calling scope_demo: %d", count);

    return 0;
}
