#undef NDEBUG
#ifndef _MINUNIT_H
#define _MINUNIT_H

#include "stdio.h"
#include "stdlib.h"
#include "../../lib/dbg.h"

#define mu_suite_start() char *message = NULL

#define mu_assert(test, message)  \
    if (!test) { \
        log_error(message); \
        return message; \
    }

#define mu_run_test(test) \
    debug("\n--- %s", test); \
    message = test(); \
    tests_run++; \
    if (message) return message;

#define RUN_TESTS(name) \
    int main(int argc, char *argv[]) { \
        argc = 1; \
        debug("---- RUNNING TESTS ---- \nTesting: %s", argv[0]); \
        char *result = name(); \
        if (result != 0) {\
            log_error("TEST FAILED: %d", result); \
        }else {\
            log_info("ALL TESTS PASSED: %d", result); \
        }\
        printf("TESTS RUN: %d\n", tests_run); \
        exit(result != 0); \ 
    }

int tests_run;

#endif