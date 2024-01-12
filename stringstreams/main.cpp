#include <iostream>
#include <sstream>

int main() {

    std::string user_input;

    std::cout << "Enter a command: ";
    std::getline(std::cin, user_input);

    std::stringstream ss;
    ss << user_input;

    std::string command;
    ss >> command;

    // if the command is more than 1 letter, it must text
    auto start = -1;
    auto end = -1;
    if (command.length() > 1) {
        std::cout << "You entered some text." << std::endl;
    } else {
        // assume it is a command until proven otherwise
        std::cout << "I think you entered a command." << std::endl;

        // try to extract a number
        ss >> start;
        if (ss.fail()) {
            std::cout << "Didn't have a starting number." << std::endl;

            // check whether or not the entire input was a single letter
            if (user_input.length() == 1) {
                std::cout << "I think you entered a command." << std::endl;
            } else {
                std::cout << "You entered a sentence." << std::endl;
            }
        } else {
            std::cout << "There was a first number." << std::endl;

            // success! try to extract a second number
            ss >> end;
            if (ss.fail()) {
                std::cout << "There was no ending number." << std::endl;
            } else {
                std::cout << "There was a second number." << std::endl;
            }
        }
    }

    std::cout << "The command is: " << command << std::endl;
    std::cout << "The first number is: " << start << std::endl;
    std::cout << "The second number is: " << end << std::endl;

    return 0;
}