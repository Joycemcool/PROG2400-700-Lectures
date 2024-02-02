#include <iostream>
#include <memory>

struct Student {
    std::string _name {"uninitialized"};
    std::string _id {"W999999"};
};
std::ostream& operator<<(std::ostream& output, const Student& student) {
    output << "Name: " << student._name << ", ID: " << student._id;
    return output;
}

struct Node {
    Student _data;
    std::unique_ptr<Node> _next {nullptr};
};

class Queue {
    std::unique_ptr<Node> _front {nullptr};
    Node* _back {nullptr};
    size_t _size {0};
public:
    void push_back(const Student& student) {
        auto node = std::make_unique<Node>(student);

        // is this the first node?
        if (_front == nullptr) {
            // yes, this is the first node
            _front = std::move(node);
            _back = _front.get();
        } else {
            // no, this is another node
            _back->_next = std::move(node);
            _back = _back->_next.get();
        }

        _size++;
    }

    [[nodiscard]] Student peek() const {
        return _front != nullptr ? _front->_data : Student();
    }

    [[nodiscard]] size_t size() const {
        return _size;
    }

    void pop_front() {
        auto node = std::move(_front);

        // disconnect front node from chain
        _front = std::move(node->_next);

        // if we remove the only node, update the back pointer as well
        if (_front == nullptr) {
            _back = nullptr;
        }

        _size--;
    }

    friend std::ostream& operator<<(std::ostream& output, const Queue& queue);
};

std::ostream& operator<<(std::ostream& output, const Queue& queue) {
    auto node = queue._front.get();

    while (node != nullptr) {
        output << node->_data << std::endl;
        node = node->_next.get();
    }
    return output;
}

int main() {

    Queue queue;

    // test 1 - add some nodes to a queue
    std::cout << "Test 1: add nodes to the end of a queue" << std::endl;
    std::cout << "---------------------------------------" << std::endl;

    queue.push_back({"John Smith", "W111111"});
    queue.push_back({"Jane Doe", "W222222"});
    queue.push_back({"Jill Hill", "W333333"});
    queue.push_back({"Jack Sprat", "W444444"});
    queue.push_back({"Bill Hill", "W555555"});

    std::cout << queue << std::endl;

    // test 2 - view data at the front of the queue
    std::cout << "Test 2: view data at front of queue" << std::endl;
    std::cout << "-----------------------------------" << std::endl;

    std::cout << queue.peek() << std::endl;

    // test 3 - remove node from queue
    std::cout << "Test 3: remove node from the front of the queue" << std::endl;
    std::cout << "-----------------------------------------------" << std::endl;

    queue.pop_front();
    std::cout << queue << std::endl;

    // test 4 - remove all nodes from queue
    std::cout << "Test 4: remove all nodes from queue" << std::endl;
    std::cout << "-----------------------------------" << std::endl;

    while (queue.size() > 0) {
        std::cout << queue << std::endl;
        queue.pop_front();
    }

    return 0;
}