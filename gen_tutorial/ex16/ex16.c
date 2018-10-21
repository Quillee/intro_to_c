#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

struct Person{
    char *name;
    int age;
    int height;
    int weight;
};

struct Person *person_create(char *name, int age, int height, int weight){
    struct Person *who = malloc(sizeof(struct Person));
    assert(who != NULL);
    who->name = strdup(name);
    who->age = age;
    who->height = height;
    who->weight = weight;
    return who;
};

void person_destroy(struct Person *person){
    assert(person != NULL);
    //free(person->name);
    free(person);
}

void person_print(struct Person *person){
    printf("%s is a person with %d years alive %d cm tall and %d lbs on their body\n and lives at %p\n",
        person->name, person->age, person->height, person->weight, person);
}

void person_print_from_stack(struct Person person){
     printf("%s is a person with %d years alive %d cm tall and %d lbs on their body\n and lives at %p\n",
        person.name, person.age, person.height, person.weight, &person);  
}

int main(int argc, char *argv[]){
    struct Person *boo = person_create("Boo", 2800, 20, 5);
    struct Person *mario = person_create("Mario", 42, 150, 150);
    
    printf("boo is located at %p\n", boo);
    printf("mario is located at %p\n", mario);

    boo->name = "King Boo";
    boo->age += 1000;
    person_print(boo);

    mario->age += 10;
    mario-> weight += 40;
    person_print(mario);

    person_destroy(boo);
    person_destroy(mario);

    struct Person peach = { .name = "Peach", .age=32, .weight=120, .height= 160};
    struct Person luigi = { .name = "Luigi", .age= 34, .weight= 130, .height= 185};

    person_print_from_stack(peach);
    person_print_from_stack(luigi);
    


    if(1)
        printf("\n\n1 is true!\n");
    else if(0)
        printf("\n\n0 is true!!\n");

    if(!NULL)
        printf("\nNOT NULL is true\n");
    // free(luigi.name);
    // free(peach.name);

    return 0; 
}
