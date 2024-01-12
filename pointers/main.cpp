#include <iostream>

void pointer_read(long long *ptr) {
    std::cout << std::hex << ptr << std::endl;
    std::cout << *ptr << std::endl;
}

void value_pointer_read(int num) {
    std::cout << std::hex << &num << std::endl;
}

void reference_read(int& num) {
    std::cout << std::hex << &num << std::endl;
}

void double_pointer_read(char** ptr) {
    std::cout << std::hex << ptr << std::endl;
}

void return_data(char** ptr) {
    std::cout << std::hex << "*ptr = " << (int*)*ptr << std::endl;
    (*ptr)++;
    std::cout << std::hex << "*ptr = " << (int*)*ptr << std::endl;
}

int main() {

    int num = 0x1234;
    int num2 = 0x5678;

    auto ptr = (char *)&num;

    std::cout << num << num2 << std::endl;
    std::cout << std::hex << "ptr = " << ptr << std::endl;

    pointer_read((long long *)&num);
    value_pointer_read(num);
    reference_read(num);
    double_pointer_read(&ptr);
    return_data(&ptr);

    std::cout << std::hex << "ptr = " << ptr << std::endl;

    return 0;
}