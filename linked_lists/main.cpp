#include <iostream>

class LinkedList {

    struct LinkedListNode {
        int _data {-1};
        LinkedListNode* _next {nullptr};
    };

    LinkedListNode* _start {nullptr};

public:
    void add(int num) {
        // create a new node
        auto new_node = new LinkedListNode();
        new_node->_data = num;

        // is this the first node in the chain?
        if (_start == nullptr) {
            // yes! I am the first node!
            _start = new_node;
        } else {
            // no. this is another node.

            // find the end of the chain
            auto node = _start;
            auto prev = (LinkedListNode *) nullptr;

            while (node != nullptr) {
                prev = node;
                node = node->_next;
            }

            // did we find the end?
            if (prev != nullptr) {
                prev->_next = new_node;
            }
        }
    }

    /// insert a node at a specific index (zero-based)
    /// \param data the value to insert
    /// \param index the location to insert at
    void insert(int data, int index) {
        // create a new node
        auto node = new LinkedListNode();
        node->_data = data;

        // find the position to insert at
        auto curr = _start;
        auto prev = (LinkedListNode *) nullptr;

        for (auto i = 0; curr != nullptr && i < index; ++i) {
            prev = curr;
            curr = curr->_next;
        }

        // did I find the right location to insert at?
        if (prev == nullptr) {
            // inserting at the start of the chain
            node->_next = _start;
            _start = node;
        } else {
            // inserting elsewhere in the chain
            node->_next = prev->_next;
            prev->_next = node;
        }
    }

    /// deletes a node from the chain
    /// \param data the value of the node to delete
    void remove(int data) {

        auto node = _start;
        auto prev = (LinkedListNode *) nullptr;

        // find the node to delete
        while (node != nullptr && node->_data != data) {
            prev = node;
            node = node->_next;
        }

        // did I find the node to delete?
        if (node != nullptr) {

            // detach node from chain
            if (prev == nullptr) {
                // deleting start node
                _start = node->_next;
            } else {
                // deleting middle node
                prev->_next = node->_next;
            }

            delete node;
        }

    }

    friend std::ostream& operator<<(std::ostream& output, LinkedList& list);
};

std::ostream& operator<<(std::ostream& output, LinkedList& list) {
    auto node = list._start;

    while (node != nullptr) {
        std::cout << node->_data << ' ';
        node = node->_next;
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

    return 0;
}