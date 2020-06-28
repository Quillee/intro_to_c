#include "main.h"
// #include "examples/hello-window/hello_window.h"

estatus* (function_ptr)();

std::map<estatus(*)(), std::string> create_example_map();
std::vector<estatus(*)()> create_example_vector(std::map<estatus(*)(), std::string>);
std::string menu(std::map<estatus(*)(), std::string> m);

int main(int argc, char const *argv[])
{
    estatus status = STARTING;

    auto example_map = create_example_map();
    auto examples = create_example_vector(example_map);

    std::string message = menu(example_map);
    short op = 1;

    while(status != QUIT) { 
        printf("%s\n", message.c_str());
        std::cin >> op;

        // @Theory: this runs the associated method
        if (op == 0) {
            printf("\nOkay peace\n\n");
            status = QUIT;
        } else if (op > examples.size()) {
            printf("Error processing input, please select from the list of provided examples!\n"
                "input: %d\n"
                "max index: %d\n\n", op, 
                                     examples.size());
            status = ERROR;
        }  else {
            printf("INDEX GIVEN: %d , INDEX MAX: %d\n", op, examples.size());
            status = examples[op - 1]();
            if (status == SUCCESSFUL) {
                printf("Execution of %s completed! Press any key to continue\n", 
                    example_map.find(examples[op - 1])->second.c_str());
                getchar();
            }
        }

        if (status == ERROR) {
            fprintf(stderr, "Error during execution!\nExiting...\n");
            break;
        } else {
            status = RUNNING;
        }

    }

    return status == ERROR ? -1 : 0;
}


std::string menu(std::map<estatus(*)(), std::string> m) {
    int n = 0;
    std::string message = "Welcome to my OpenGL suite of example applications!\n"
         "You can see more info in the readme.md, " 
         "but the website I'm using to learn this stuff is https://learnopengl.com/Getting-started/OpenGL\n\n" 
         "Please select an option from below\n"
         "0. Quit the application!";
    
    for (auto it = m.begin(); it != m.end(); ++it) {
        message += "\n";
        message += std::to_string(++n) + ". " + it->second;
    }

    return message;
}

std::map<estatus(*)(), std::string> create_example_map() {
    std::map<estatus(*)(), std::string> map;
    // shows up in opposite order in menu
    map.insert(std::make_pair(hello_window, "hello_window"));
    map.insert(std::make_pair(hello_triangle_main, "Hello Triangle"));
    map.insert(std::make_pair(example_main, "Example: Hello Triangle"));

    return map;
}

std::vector<estatus(*)()> create_example_vector(std::map<estatus(*)(), std::string> m) {
    std::vector<estatus(*)()> vec;

    for (auto it = m.begin(); it != m.end(); ++it) {
        vec.push_back(it->first);
    }

    return vec;
}
