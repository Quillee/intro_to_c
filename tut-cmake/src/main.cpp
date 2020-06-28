#include <iostream>

#include "hello/hello.h"

int main(int argc, char const *argv[])
{
    /* code */
    std::cout << say_hello() << " world!" << 1.0 << std::endl << "Version: " << SAY_HELLO_VERSION << std::endl;
    getchar();
    std::cout << say_goodbye() << std::endl;
    return 0;
}
