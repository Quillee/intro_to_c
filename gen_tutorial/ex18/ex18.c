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

void die(const char* message){
    if(errno){
        perror(message);
    }else{
        printf("Error: %s\n", message);
    }
    exit(1);
}

// typedef creates a "fake type" int this case for a function pointer
// compare_callback
typedef int (*compare_cb)(int a , int b);

// classical bubble sort algo that will use our function pointer for sorting
int *bubble_sort(int *numbers, int count, compare_cb cmp){
    int temp = 0;
    int i = 0;
    int j = 0;
    int *target = malloc(count * sizeof(int));

    if(!target){        
        die("Memory error!");
    }

    memcpy(target, numbers, count * sizeof(int));
    for (i = 0; i < count; ++i){
        for(j = 0; j < count - 1; ++j){
            if(cmp(target[j], target[j + 1]) > 0){
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


void test_sorting(int *numbers, int count, compare_cb cmp){
    int i = 0;
    int *sorted = bubble_sort(numbers, count, cmp);
    unsigned char *data = (unsigned char *)cmp;
    for(i = 0; i < 25; i++){
        printf("%02x:", data[i]);
    }
    if(!sorted)
        die("Memory Error");

    for(i = 0; i < count; i++){
        printf("%d ", sorted[i]);
    }
    printf("\n");
    free(sorted);
}

// dump location of funciton
void dump(compare_cb cmp){
    unsigned char *func_data = (unsigned char *)cmp;

    for(int i = 0; i < 25; i++){
        printf('%02x:', func_data[i]);
    }
}

void overwrite_function(compare_cb writeable_pointer, compare_cb readable_pointer){
    unsigned char *write = (unsigned char *)writeable_pointer;
    unsigned char *read = (unsigned char *)readable_pointer;

    for(int i = 0; i < 25; i++){
        printf('%02x:', write[i]);
        write[i] = read[i];
    }
}

int main(int argc, char *argv[])
{
    if(argc < 2) die("Error: Usage Ex: ex18 1 2 3 4 5 6");
    int x = 0x1F;
    printf("%x", x);
    int count = argc - 1;
    char** inputs = argv + 1;

    int *numbers = malloc(count * sizeof(int));
    if(!numbers) die("Memory Error");


    for(int i = 0; i < count; i++){
        numbers[i] = atoi(inputs[i]);
    }

    test_sorting(numbers, count, test_sorting);
    test_sorting(numbers, count, sorted_order);
    test_sorting(numbers, count, reverse_order);
    test_sorting(numbers, count, strange_order);

    printf("Done!\n");
    free(numbers);

    printf("Attempting to break teh code\n\n");
    dump(sorted_order);
    printf("^Sorted Order^");
    overwrite_function(sorted_order, reverse_order);
    printf("^Now Overwritten to reverse order^");

    return 0;
}
