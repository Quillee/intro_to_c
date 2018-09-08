#include <stdio.h>

/**
 * hex calculator 
 * #> Goals
 * #>   understand input and output a little better
 * #>   learn how to calculate and play with hex numbers
 * 
 * ?>   hope to work with regular numbers too?
 */ 

void opt_parser(char **args);
bool menu();
void continuous_calculate();
int main(int *argc, char **argv){    
    opt_parser(argv)
    
    
}

void opt_parser(char **args){
    if(*args[1] == "-c" || *args[1] == cont){
        while(menu()){
            continuous_calculate();
        }
    }
}

bool menu(){
    printf("Hello would you like to quit? y/n?\n");
    // scanf();

}

void continuous_calculate(){
    printf("Enter what values you would like to calculate and then one of the special operands:\n");
    printf("+, -, /, *, %\n");
    printf("You can do this across multiple values, ex. 0x10 0xA 0xAB + -\n");
    printf("Prompt>   ")
}