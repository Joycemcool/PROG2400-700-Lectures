#include <iostream>
#include <vector>
#include <memory>

struct Data {
  unsigned long long _uid;
  std::string _description;
  std::vector<int> _nums;
};
std::ostream& operator<<(std::ostream& output, const Data& data) {
  output << "UID: " << data._uid << ", ";
  output << "Desc: " << data._description << ", ";

  for (auto n: data._nums) {
    output << n << " ";
  }
  output << std::endl;

  return output;
}

struct Node {
  Data _data;
  std::unique_ptr<Node> _next {nullptr};
};

class Stack {
  std::unique_ptr<Node> _top {nullptr};
  size_t _size {0};
 public:
  void push(Data data) {
    auto node = std::make_unique<Node>(std::move(data));
    node->_next = std::move(_top);
    _top = std::move(node);
    _size++;
  }

  void pop() {
    if (_size == 0) return;
    _top = std::move(_top->_next);
    _size--;
  }

  [[nodiscard]] Data peek() {
    if (_size == 0) return {};
    return _top->_data;
  }

  [[nodiscard]] size_t size() const {
    return _size;
  }

  friend std::ostream& operator<<(std::ostream& output, const Stack& stack);
};

std::ostream& operator<<(std::ostream& output, const Stack& stack) {
  auto node = stack._top.get();
  while (node != nullptr) {
    output << node->_data << std::endl;
    node = node->_next.get();
  }

  return output;
}

int main() {

  Stack stack;

  // test 1 - add first node to the stack
  std::cout << "Test 1 - add nodes to stack" << std::endl;
  stack.push({1ULL, "first", {1, 2, 3}});
  stack.push({2ULL, "second", {4, 5, 6}});
  stack.push({3ULL, "third", {7, 8, 9}});
  std::cout << stack << std::endl;

  // test 2 - remove a node from the stack
  std::cout << "Test 2 - remove node from stack" << std::endl;
  stack.pop();
  std::cout << stack << std::endl;

  // test 3 - peek at the top node
  std::cout << "Test 3 - peek at the top of the stack" << std::endl;
  std::cout << stack.peek() << std::endl;

  // test 4 - remove all nodes from stack
  std::cout << "Test 4 - remove all nodes from stack" << std::endl;
  while (stack.size() > 0) {
    std::cout << stack << std::endl;
    stack.pop();
  }

  return 0;
}