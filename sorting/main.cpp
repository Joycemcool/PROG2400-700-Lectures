#include <iostream>
#include <iomanip>
#include <span>
#include <chrono>
#include <random>

using clk = std::chrono::high_resolution_clock;

void track_time(auto desc, void(*f)(std::span<int>), std::span<int> nums) {
    auto t = clk::now();
    f(nums);
    const std::chrono::duration<double> span = clk::now() - t;
    std::cout << std::setw(15) << desc << ": ";
    std::cout << "time " << span.count() << "s" << std::endl;
}

void dump_array(std::span<int> array) {
    for (int i: array) {
        std::cout << std::setw(3) << i;
    }
    std::cout << std::endl;
}

void fill_array(std::span<int> array) {
    std::random_device rnd;
    std::default_random_engine eng(rnd());
    std::uniform_int_distribution<size_t> dist(1, array.size());
    std::generate(array.begin(), array.end(), [&]() {
        return dist(eng);
    });
}

struct Node {
    int _data{0};
    Node *_left{nullptr};
    Node *_right{nullptr};
};

class BST {
    Node *_root{nullptr};
public:
    // recursive insert function
    void insert(int data) {
        insert(data, _root);
    }

    // non-recursive remove function
    void remove(int data) {
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

    void save_array(std::span<int> array) {
        save_array(array, _root);
    }

private:

    void save_array(std::span<int> array, Node *&node) {
        static int i = 0;

        if (node != nullptr) {
            save_array(array, node->_right);
            array[i++] = node->_data;
            save_array(array, node->_left);
        }
    }

    void insert(int data, Node *&node) {
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

    void print_tree(std::ostream &output, Node *&node, int indent) {
        if (node != nullptr) {
            print_tree(output, node->_right, indent + 8);
            output << std::setw(indent) << node->_data << std::endl;
            print_tree(output, node->_left, indent + 8);
        }
    }

    friend std::ostream &operator<<(std::ostream &output, BST &bst);
};

std::ostream &operator<<(std::ostream &output, BST &bst) {
    bst.print_tree(output, bst._root, 0);
    return output;
}

void bubble_sort(std::span<int> array) {
    for (int i = 0; i < array.size() - 2; ++i) {
        for (int j = 0; j < array.size() - 1 - i; ++j) {
            if (array[j] > array[j + 1]) {
                // swap the numbers
                std::swap(array[j], array[j + 1]);
            }
        }
    }
}

void selection_sort(std::span<int> array) {
    for (int i = 0; i < array.size() - 1; ++i) {
        // find the smallest number
        int lowest = i;
        for (int j = i; j < array.size(); ++j) {
            if (array[j] < array[lowest]) {
                lowest = j;
            }
        }
        // swap it with the current index
        if (array[lowest] < array[i]) {
            std::swap(array[lowest], array[i]);
        }
    }
}

void insertion_sort(std::span<int> array) {
    for (int i = 1; i < array.size(); ++i) {
        // take the current value
        auto temp = array[i];

        // shuffle elements to the right to make room
        auto j = i;
        for (; j > 0 && temp < array[j - 1]; j--) {
            array[j] = array[j - 1];
        }

        // insert the value in correct spot
        array[j] = temp;
    }
}

void shell_sort(std::span<int> array) {

    // determine the gap sizes (e.g. 5 2 1)
    for (auto gap = array.size() / 2; gap > 0; gap /= 2) {

        // choose the elements that make up the "smaller" array
        for (auto start = 0; start < gap; start++) {

            // use the insertion sort on the smaller array
            for (auto i = start + gap; i < array.size(); i += gap) {
                // take the current value
                auto temp = array[i];

                // shuffle elements to the right to make room
                auto j = i;
                for (; j >= gap && temp < array[j - gap]; j -= gap) {
                    array[j] = array[j - gap];
                }

                // insert the value in correct spot
                array[j] = temp;
            }
        }
    }
}

auto split(std::span<int> array) {
    // choose the pivot point
    auto pivot = array[0];

    // start searching for numbers less than and greater than the pivot
    auto left = 0;
    auto right = array.size() - 1;

    while (left < right) {
        // search for element less than the pivot
        while (right > 0 && pivot < array[right]) right--;

        // search for element greater than the pivot
        while (left < right && pivot >= array[left]) left++;

        // if two were found out of place, swap them
        if (left < right && array[left] != array[right]) {
            std::swap(array[left], array[right]);
        }
    }

    // now the pivot point is moved to its location
    array[0] = array[right];
    array[right] = pivot;

    return right;
}

void quick_sort(std::span<int> array) {
    // the array is sorted when it only has one element
    if (array.size() <= 1) return;

    // split the array into two sublists
    // returns the index of the pivot point
    auto pivot = split(array);

    // sort the left side
    quick_sort(array.subspan(0, pivot));

    // sort the right side
    quick_sort(array.subspan(pivot + 1, array.size() - pivot - 1));
}

void bst_sort(std::span<int> array) {
    BST bst;

    for (int num: array) {
        bst.insert(num);
    }

    bst.save_array(array);
}

int main() {

    for (size_t len = 10; len <= 10000; len *= 10) {
        std::cout << "len = " << len << std::endl;

        auto nums = new int[len];

//        // bubble sort
//        fill_array({nums, len});
//        track_time("bubble sort", bubble_sort, {nums, len});
//
//        // selection sort
//        fill_array({nums, len});
//        track_time("selection sort", selection_sort, {nums, len});

//        // insertion sort
//        fill_array({nums, len});
//        track_time("insertion sort", insertion_sort, {nums, len});

        // shell sort
        fill_array({nums, len});
        track_time("shell sort", shell_sort, {nums, len});

        // quick sort
        fill_array({nums, len});
        track_time("quick sort", quick_sort, {nums, len});

        // bst sort
        fill_array({nums, len});
        track_time("bst sort", bst_sort, {nums, len});

        delete[] nums;
    }

    return 0;
}