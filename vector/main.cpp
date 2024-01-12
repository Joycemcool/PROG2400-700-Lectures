#include <iostream>
#include <vector>

std::ostream& operator<<(std::ostream& output, const std::vector<int>& v) {
    for (auto& n:v) {
        output << n << ' ';
    }
    return output;
}

int main() {

    auto v = std::vector({1, 2, 3, 4, 5});

    std::cout << "Initial: ";
    std::cout << v << std::endl;
    std::cout << "capacity: " << v.capacity() << std::endl;
    std::cout << "size: " << v.size() << std::endl;

    v.push_back(6);

    std::cout << "After add: ";
    std::cout << v << std::endl;
    std::cout << "capacity: " << v.capacity() << std::endl;
    std::cout << "size: " << v.size() << std::endl;

    v.erase(v.begin());

    std::cout << "After remove: ";
    std::cout << v << std::endl;
    std::cout << "capacity: " << v.capacity() << std::endl;
    std::cout << "size: " << v.size() << std::endl;

//    v.insert(v.begin(), {7, 8, 9, 10, 11, 12});
    for (auto& n: {7, 8, 9, 10, 11, 12}) {
        v.push_back(n);
    }

    std::cout << "After add: ";
    std::cout << v << std::endl;
    std::cout << "capacity: " << v.capacity() << std::endl;
    std::cout << "size: " << v.size() << std::endl;

    v.reserve(100);
    std::cout << "After reserve: ";
    std::cout << v << std::endl;
    std::cout << "capacity: " << v.capacity() << std::endl;
    std::cout << "size: " << v.size() << std::endl;

    v.shrink_to_fit();
    std::cout << "After shrink: ";
    std::cout << v << std::endl;
    std::cout << "capacity: " << v.capacity() << std::endl;
    std::cout << "size: " << v.size() << std::endl;

    return 0;
}