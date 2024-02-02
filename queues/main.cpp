#include <iostream>

struct Node {
    int _data {-1};
    Node* _next {nullptr};
};

class Queue {
    Node* _front {nullptr};
    Node* _back {nullptr};
    size_t _size {0};
public:
    void push_back(int num) {
        auto const node = new Node({num});

        // is this the first node?
        if (_front == nullptr) {
            // yes, this is the first node
            _front = node;
        } else {
            // no, this is another node
            _back->_next = node;
        }
        _back = node;
        _size++;
    }

    [[nodiscard]] int peek() const {
        return _front != nullptr ? _front->_data : -1;
    }

    [[nodiscard]] size_t size() const {
        return _size;
    }

    void pop_front() {
        auto node = _front;

        // disconnect front node from chain
        _front = _front->_next;

        // if we remove the only node, update the back pointer as well
        if (_front == nullptr) {
            _back = nullptr;
        }

        delete node;

        _size--;
    }

    friend std::ostream& operator<<(std::ostream& output, const Queue& queue);
};

std::ostream& operator<<(std::ostream& output, const Queue& queue) {
    auto node = queue._front;

    while (node != nullptr) {
        output << node->_data << " ";
        node = node->_next;
    }
    return output;
}

int main() {

    Queue queue;

    // test 1 - add some nodes to a queue
    std::cout << "Test 1: add nodes to the end of a queue" << std::endl;
    std::cout << "---------------------------------------" << std::endl;

    queue.push_back(1);
    queue.push_back(2);
    queue.push_back(3);
    queue.push_back(4);
    queue.push_back(5);

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