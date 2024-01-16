#include <iostream>
#include "echo_application.h"

using namespace std::string_literals;

EchoApplication::EchoApplication(std::istream& in, std::ostream& out)
    : _cin(in), _cout(out) {
}

void EchoApplication::run() {
    const auto END_CONDITION = "end"s;
    std::string user_input;

    do {
        _cout << "Type something: ";
        std::getline(_cin, user_input);
        _cout << user_input << std::endl;
    } while (user_input != END_CONDITION);
}
