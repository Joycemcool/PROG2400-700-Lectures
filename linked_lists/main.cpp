#include <iostream>
#include <memory>
#include <vector>

class LinkedList {

    struct LinkedListNode {
        int _data{-1};
        std::unique_ptr<LinkedListNode> _next{nullptr};
    };

    std::unique_ptr<LinkedListNode> _start{nullptr};

public:

    class iterator {
    public:
        LinkedListNode *_node{nullptr};

        explicit iterator(LinkedListNode *node = nullptr) : _node(node) {}

        iterator &operator++() {
            _node = _node->_next.get();
            return *this;
        }

        int operator*() const { return _node->_data; }

        bool operator!=(const iterator it) const { return this->_node != it._node; }
    };

    iterator begin() { return iterator(_start.get()); }

    iterator end() { return iterator(nullptr); }

    int operator[](const int index) const {
        auto node = _start.get();
        auto i = 0;
        while (node != nullptr) {
            if (i == index) return node->_data;
            i++;
            node = node->_next.get();
        }
        return -1;
    }

    void add(int num) {
        // create a new node
        auto new_node = std::make_unique<LinkedListNode>();
        new_node->_data = num;

        // is this the first node in the chain?
        if (_start == nullptr) {
            // yes! I am the first node!
            _start = std::move(new_node);
        } else {
            // no. this is another node.

            // find the end of the chain
            auto node = _start.get();
            auto prev = (LinkedListNode *) nullptr;

            while (node != nullptr) {
                prev = node;
                node = node->_next.get();
            }

            // did we find the end?
            if (prev != nullptr) {
                prev->_next = std::move(new_node);
            }
        }
    }

    /// insert a node at a specific index (zero-based)
    /// \param data the value to insert
    /// \param index the location to insert at
    void insert(int data, int index) {
        // create a new node
        auto node = std::make_unique<LinkedListNode>();
        node->_data = data;

        // find the position to insert at
        auto curr = _start.get();
        auto prev = (LinkedListNode *) nullptr;

        for (auto i = 0; curr != nullptr && i < index; ++i) {
            prev = curr;
            curr = curr->_next.get();
        }

        // did I find the right location to insert at?
        if (prev == nullptr) {
            // inserting at the start of the chain
            node->_next = std::move(_start);
            _start = std::move(node);
        } else {
            // inserting elsewhere in the chain
            node->_next = std::move(prev->_next);
            prev->_next = std::move(node);
        }
    }

    /// deletes a node from the chain
    /// \param data the value of the node to delete
    void remove(int data) {

        auto node = _start.get();
        auto prev = (LinkedListNode *) nullptr;

        // find the node to delete
        while (node != nullptr && node->_data != data) {
            prev = node;
            node = node->_next.get();
        }

        // did I find the node to delete?
        if (node != nullptr) {

            // detach node from chain
            if (prev == nullptr) {
                // deleting start node
                _start = std::move(node->_next);
            } else {
                // deleting middle node
                prev->_next = std::move(node->_next);
            }
        }
    }

    friend std::ostream &operator<<(std::ostream &output, LinkedList &list);
};

std::ostream &operator<<(std::ostream &output, LinkedList &list) {
    auto node = list._start.get();

    while (node != nullptr) {
        std::cout << node->_data << ' ';
        node = node->_next.get();
    }
    return output;
}

int main() {

    auto list = LinkedList();

    // test 1 - add one number
    list.add(1);

    std::cout << "Test 1 - add a number" << std::endl;
    std::cout << "---------------------" << std::endl;
    std::cout << list << std::endl;

    // test 2 - add more numbers
    list.add(2);
    list.add(3);
    list.add(4);
    list.add(5);

    std::cout << "Test 2 - add more numbers" << std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout << list << std::endl;

    // test 3 - insert node at the start
    list.insert(0, 0);

    std::cout << "Test 3 - insert node at the start" << std::endl;
    std::cout << "---------------------------------" << std::endl;
    std::cout << list << std::endl;

    // test 4 - insert node in the middle
    list.insert(6, 2);

    std::cout << "Test 4 - insert node in the middle" << std::endl;
    std::cout << "----------------------------------" << std::endl;
    std::cout << list << std::endl;

    // test 5 - delete node at the start
    list.remove(0);

    std::cout << "Test 5 - delete node at the start" << std::endl;
    std::cout << "----------------------------------" << std::endl;
    std::cout << list << std::endl;

    // test 6 - delete node in the middle
    list.remove(2);

    std::cout << "Test 6 - delete node in the middle" << std::endl;
    std::cout << "----------------------------------" << std::endl;
    std::cout << list << std::endl;

    // test 7 - delete node at the end
    list.remove(5);

    std::cout << "Test 7 - delete node at the end" << std::endl;
    std::cout << "-------------------------------" << std::endl;
    std::cout << list << std::endl;

    // test 8 - use the overloaded index operator
    std::cout << "Test 8 - use the overloaded index operator" << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    std::cout << list[0] << std::endl;

    // test 9 - use the ranged for loop
    std::cout << "ranged for loop...." << std::endl;
    for (auto n: list) {
        std::cout << n << ' ';
    }
    std::cout << std::endl;

    std::cout << "standard for loop...." << std::endl;
    for (auto it = list.begin(); it != list.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    return 0;
}