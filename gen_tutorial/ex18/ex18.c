/****************************************************************************************************\
 *  Excercise 18 - pointers to functions
 *  By: Melvin
 * 
 *  # Functions are just pointers to a location in the program where the code exists
 *  # format of function pointer 
 *  #  return_type (*POINTER_NAME)(int param1, int param2)
 *  #  example: int (*foo)(int a, int b)
 \***************************************************************************************************/ 
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

typedef enum error_codes{
    no_err,
    memory
} error_codes;

void die(const char* message){
    if(errno){
        perror(message);
    }else{
        printf("Error: %s\n", message);
    }
    exit(1);
}

// typedef creates a "fake type" int this case for a function pointer
typedef int (*compare_cb)(int a , int b);

// classical bubble sort algo that will use our function pointer for sorting
int *bubble_sort(int *numbers, int count, compare_cb cmp){
    error_codes error;
    int temp = 0;
    int i = 0;
    int j = 0;
    int *target = malloc(count * sizeof(int));

    if(!target){        
        die("Memory error!");
    }

    memcpy(target, numbers, count * sizeof(int));
    for (i = 0; i < count; ++i){
        for(j = 0; j < count ; ++j){
            if(cmp(target[j], target[j + 1])){
                temp = target[j];
                target[j] = target[j + 1];
                target[j + 1] = temp;
            }
        }
    }
    return target;
}

int sorted_order(int a, int b){
    return (a > b) - (a < b);
}

int reverse_order(int a, int b){
    return (a < b) - (a > b);
}

int strange_order(int a, int b){
    if(a == 0 || b == 0){
        return 0;
    }
    return a % b;
}
1222q

void test_sorting(int *numbers, int count, compare_cb cmp){
    int i = 0;
    int *sorted = bubble_sort(numbers, count, cmp);

    if(!sorted)
        die("Memory Error");

    for(int i = 0; i < count; ++i){
        printf("%d ", sorted[i]);
    }
    printf("\n");
    free(sorted);
}


int main(int argc, char const *argv[])
{
    if(argc < 2) die("Error: Usage Ex: ex18 1 2 3 4 5 6");
    int x = 0x1F;
    printf("%x", x);
    int count = argc - 1;
    int i = 0;
    char** inputs = argv + 1;

    int numbers = malloc(count * sizeof(int));
    if(!numbers) die("Memory Error");

    for(i = 0; i < count; ++i){
        
    }
    return 0;
}
