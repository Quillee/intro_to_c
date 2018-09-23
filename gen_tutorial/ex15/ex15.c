#include <stdio.h>

// #> finally up to pointers
int main(int argc, char const *argv[])
{
    int ages[] = { 23, 43, 12, 89, 2 };
    char *names[] = {
        "Alan", "Frank", "Mary", "John", "Lisa"
    };

    int count = sizeof ages / sizeof(int);
    
    for(int i = 0; i < count; ++i){
        printf("%s has %d years alive.\n", names[i], ages[i]);
    }

    printf("-----\n");
    int *cur_age = ages;
    char **cur_name = names;

    for(int i = 0; i < count;++i){
        printf("%s is %d years old.\n", 
            *(cur_name + i),
            *(cur_age + i));
    }

    printf("-----\n");

    for(int i = 0; i < count;++i){
        printf("%s is %d years old.\n", 
            cur_name[i],
            cur_age[i]);
    }

    return 0;
}
