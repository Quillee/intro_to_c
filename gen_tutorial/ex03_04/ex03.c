#include <stdio.h>
#include <uchar.h>
#include <stdbool.h>

// #> Exercise 3 : formatted print statements
// #> Exercise 4: GDB
// #> Excercise 5 & 6 : remember operators and keywords


typedef struct Projectile {
    int damage;
    bool is_on_fire;
}Projectile;


int main(int argc, char *argv[]){
    // #> default
    volatile int age = 23;
    age = 24;
    int height = 172;

    printf("I am %d years old\n", age);
    printf("I am %d centimeters tall\n", height);

    // #> extras
    // #> all format codes
    //#> alert, beep
    
    // #> control code that simulates ringing a bell telling something that a message is incoming
    printf("This is an alert \a\n");

    // #> testing hex code flags, doesn't work
    printf("double new line?%x\n", 0x0A);
    
    // #>  backspace
    printf("This is a backspacee\b\n");

    // #> formfeed, page break. mark of an end of a page so that  a printer will continue on a new page for the rest of the contents
    printf("This is a freeform \f\n ");
    
    // #> \t, 
    // #> \v vertical tab, newline and tab together
    // #> \? question mark? is this neccessary, doesn't seem to be in the case of the terminal just adds another ?    
    printf("\thorizontal tab \n\n but this \v is a vertical tab? does the questions mark not work?\?");

    // #> numerical representations
    printf("\101 \n \uAB12 ");

    // #> escape character
    printf("\n\e\n");
    
    //#> conversions
    char32_t unicode_chars[] = U"z\u00df\u6c34\U0001F34C";
    size_t uc_size = sizeof unicode_chars / sizeof *unicode_chars;
    // #> %u int unsigned
    printf(" There are %zu unicode characters?  :O\v", uc_size);
    for(int i = 0; i < uc_size; ++i)   
        // #> %x, %X int unsigned hex value,  %c char -> in this case it gets casted and you get to see the unicode version
        printf("%#x, %#c\t",unicode_chars[i],  unicode_chars[i]);

    int unsigned unsigned_i = 1234125423;
    int signed_i = -1324;
    float f = 1.23f;
    double d = 56.12341202;
    long double large_d= 2134123412.123412341234L;
    unsigned int octal = 016;
    unsigned int hex = 0xFFFFFF;

    printf("char->\t%c\n int->\t%d\n int?->\t%i\n float->%e\n", unicode_chars[0], unsigned_i, signed_i, f);
    printf("octal->\t%o, \nhex->\t%x\npointer address-> \t%p\nsequence-> %s\n", octal, hex, unicode_chars, unicode_chars);

    printf("\n\n\n\n");
    goto fail;
 
    printf("success");

    fail:
        printf("fail");    
    return 0;
}
