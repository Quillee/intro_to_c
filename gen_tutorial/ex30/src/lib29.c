#include "stdio.h"
#include "stdlib.h"
#include "../../lib/dbg.h"
#include "ctype.h"

int print_a_message(const char* message){
    printf("A STRING: %s\n", message);
    return 0;
}

int uppercase(const char* chars, int len) {
    int i = 0;

    for(i = 0; i < len; i++) {
        printf("%c", toupper(chars[i]));
    } 

    printf("\n");
    return 0;
}

int lowercase(const char* chars, int len) {
    int i = 0;

    for(i = 0; i < len; i++){
        printf("%c", tolower(chars[i]));
    }

    printf("\n");
    return 0;
}

int fail_on_purpose() { return 1; }
