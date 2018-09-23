#include <stdio.h>

// #> arrays and strings
int main(int argc, char const *argv[])
{
    int numbers[4] = { 1 };
    char name[4] = { 'a' };
    
    printf("numbers = [ %d, %d, %d, %d ]\n", numbers[0] ,numbers[1], numbers[2], numbers[3]);
    printf("name = [ %c, %c, %c, %c ]\n\n", name[0] ,name[1], name[2], name[3]);
    
    numbers[1] = 'A';
    numbers[2] = 3;
    numbers[3] = 4;

    name[0] = 'a';
    name[1] = 'b';
    name[2] = 'c';
    name[3] = '\0';
    printf("numbers = [ %d, %d, %d, %d ]\n", numbers[0] ,numbers[1], numbers[2], numbers[3]);
    printf("name = [ %c, %c, %c, %c ]\n\n", name[0] ,name[1], name[2], name[3]);
    
    char *another_name = "Mel";
    printf("another %s\n", another_name);
    printf(another_name );
    return 0;
}
