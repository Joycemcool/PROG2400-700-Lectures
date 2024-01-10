#include <iostream>

int main(int argc, char **argv, char **envp) {

    for (int i = 0; i < argc; ++i) {
        std::cout << argv[i] << std::endl;
    }

    return 0;
}