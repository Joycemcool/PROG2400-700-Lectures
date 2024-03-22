#include <iomanip>
#include "bst.h"

// recursive insert function
void BST::insert(int data) {
    insert(data, _root);
}

// non-recursive remove function
void BST::remove(int data) {
    auto node = _root;
    auto parent = (Node *) nullptr;

    // find node to delete
    while (node != nullptr) {
        if (data < node->_data) {
            parent = node;
            node = node->_left;
        } else if (data > node->_data) {
            parent = node;
            node = node->_right;
        } else {
            // found the node we want to delete!
            break;
        }
    }

    // if we didn't find the node, no reason to stay!
    if (node == nullptr) return;

    // if the node has two children
    // use right-most node of the left tree as the successor
    if (node->_left != nullptr && node->_right != nullptr) {

        // take the left path
        auto successor = node->_left;

        // then go as far right as possible
        parent = node;
        while (successor->_right != nullptr) {
            parent = successor;
            successor = successor->_right;
        }

        // swap values with the successor
        node->_data = successor->_data;

        // the successor will now be the node to delete
        node = successor;
    }

    // assume node has a left child
    auto subtree = node->_left;

    // was that assumption correct?
    if (subtree == nullptr) {
        subtree = node->_right;
    }

    // which child of my parent am I?
    if (parent == nullptr) {
        // we are deleting the root node
        _root = subtree;
    } else if (parent->_left == node) {
        // we are on the left side of the parent
        parent->_left = subtree;
    } else if (parent->_right == node) {
        // we are on the right side of the parent
        parent->_right = subtree;
    }

    delete node;
}

void BST::save_array(std::span<int> array) {
    save_array(array, _root);
}

void BST::save_array(std::span<int> array, Node *&node) {
    static int i = 0;

    if (node != nullptr) {
        save_array(array, node->_right);
        array[i++] = node->_data;
        save_array(array, node->_left);
    }
}

void BST::insert(int data, Node *&node) {
    if (node == nullptr) {
        node = new Node({data});
    } else if (data < node->_data) {
        insert(data, node->_left);
    } else if (data > node->_data) {
        insert(data, node->_right);
    } else {
        //std::cout << "Node value " << node->_data << " already exists." << std::endl;
    }
}

void BST::print_tree(std::ostream &output, Node *&node, int indent) {
    if (node != nullptr) {
        print_tree(output, node->_right, indent + 8);
        output << std::setw(indent) << node->_data << std::endl;
        print_tree(output, node->_left, indent + 8);
    }
}

std::ostream &operator<<(std::ostream &output, BST &bst) {
    bst.print_tree(output, bst._root, 0);
    return output;
}