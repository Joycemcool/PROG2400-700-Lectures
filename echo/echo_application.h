#ifndef ECHO_APPLICATION_H
#define ECHO_APPLICATION_H

#include <iostream>

class EchoApplication {

    std::istream& _cin;
    std::ostream& _cout;

public:
    explicit EchoApplication(std::istream& in, std::ostream& out);
    void run();
};

#endif