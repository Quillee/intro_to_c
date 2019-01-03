#include "dbg.h"
#include <stdio.h>
#include <stdlib.h>

void test_debug(){
    // don't need a \n
    debug("Testing debug macro");
    
    // can pass args
    debug("Passing in an arg %d. same as printf", 42);
}

void test_log_err(){
    log_err("I believe everythin is broken");
    log_err("There have been %d lines of code until %s", __LINE__, "SOMEthing");
}


void test_log_warn(){
    log_warn("Something bad might happen");
    log_warn("Maybe consider looking at %s", "/etc/passwd");
}

void test_log_info(){
    log_info("Hey something is happening");
    log_info("%d%% done!", 100);
}

void test_check(char *filename){
    FILE *file = NULL;
    char *block = NULL;

    block = malloc(100);
    check_mem(block); // no problem
    input = fopen(filename, "r");
    check_mem(input, "Failed to open file %s", filename);

    free(block);
    fclose(input);
error:
    if(block) free(block);
    if(input) fclose(input);
    return -1;

}

int test_sentinel(int code){
    char *temp = malloc(100);
    check_mem(temp);

    switch(code){
	    case 1:
		    log_info("It worked");
		default:
			sentinel("I shouldn't run");
	}

	free(temp);
	return 0;

	error:
		log_err("I def shouldn't run unless there a sentinel before me!");
		if(temp) free(temp);

		return -1;
}

int test_check_debug(){
	int i = 0;
	check_debug(i != 0, "Oops I was 0 :O");
	
	return 0;

error:
	return -1;
}

int main(int argc, char **argv){
	check(argc == 2, "Need an argument");
	test_debug();
	test_log_warn();
	test_log_info();
	test_log_err();

	check(test_check("ex20.c") == 0, "Failed with ex20.c");
	check(test_check(argv[1]) == -1, "Failed with argv");
	check(test_sentinel(1) == 0, "test sentinel failed");
	check(test_sentinel(100) == -1, "test sentinel failed");
	check(test_check_mem() == -1, "test_check_mem failed.");
	check(test_check_debug() == -1, "test_check_debug failed.");

	return 0;
error:
	return -1;
}
