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
    who->name = name;
    who->age = age;
    who->height = height;
    who->weight = weight;
    return who;
};

void destroy_person(struct Person *person){
    assert(person != NULL);
    free(person->name);
    free(person);
}

void person_print(struct Person *person){
    printf("%s is a person with %d years alive %d cm tall and %d lbs on their body\n and lives at %p\n",
        person->name, person->age, person->height, person->weight, person);
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
    return 0; 
}
