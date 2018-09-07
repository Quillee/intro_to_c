// read readme.md for more info
#include "stdio.h"
    // #> comments have special identifiers, with better comments in vscode you can actually see a difference
    // *> asdf :  DOCSTRING
    // #> dsaf : INFORMATION
    // ?> sdaf : QUESTION
    // !> sadf : ALERT/ATTENTION
    // $> asdf : VARAIBLE
    // @RMVME: asdf : META-DIRECTIVE
    // @TODO: asdf : TODO
    // #> moving on... to actually coding
int main(int argc, char const *argv[])
{   
    printf("Hello world!");
    char smallest_signed; // #> 8 bits, signed
    unsigned char smallest_unsigned; // #> 8 bits unsigned

    smallest_unsigned = 255;
    printf(smallest_unsigned);
    smallest_signed += 1;
    printf(smallest_unsigned);

    short unsigned short_u; // #> 16 bits unsigned, also you can place the unsigned on either side of declaration
    short const SHORT_S = 25;
    
    unsigned int large = 50000000; // #> 32 bits -> 4billion or somewhere around that when signed

    unsigned const long long super_large = 12345678901234567; // #> super large woooow
    printf(super_large);

    return 0;
}
