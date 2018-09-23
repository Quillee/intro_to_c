#include <stdio.h>

// #> excercise 13: for loops and arrays of strings
// #> prints out all the arguments given
int main(int argc, char const *argv[])
{
    for(int i = 0; i < argc; ++i){
        printf("arg %d, %s\n", i, argv[i]);
    }
    // #> init an array of strings
    const int STATE_COUNT = 6;
    char *states[] = {
        "California", "New York", "Illinois",
        "Oregon", "Louisiana", "Texas"
    };

    for(int i = 0; i < STATE_COUNT; ++i){
        printf("This is a state %s in my array at position %d\n", states[i], i);
    }

    return 0;
}

