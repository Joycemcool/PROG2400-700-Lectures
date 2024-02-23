#include <iostream>

void print() {

    static int count = 0;

    std::cout << "Hello ";

    count++;
    if (count < 42500) {
        print();
    }
}

int main() {
    print();
    return 0;
}