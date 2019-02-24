#include "dbg.h"
#include <stdio.h>

int main(int argc, char *argv[]){
    printf("Testings logs\n");
    log_err("Testing error %s", "Wow it works!");

    return 0;
}