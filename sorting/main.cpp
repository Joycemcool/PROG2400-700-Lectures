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
  for (int i : array) {
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

int main() {

  for (size_t len = 10; len <= 10000; len *= 10) {
    std::cout << "len = " << len << std::endl;

    auto nums = new int[len];

    // bubble sort
    fill_array({nums, len});
    track_time("bubble sort", bubble_sort, {nums, len});

    // selection sort
    fill_array({nums, len});
    track_time("selection sort", selection_sort, {nums, len});

    // insertion sort
    fill_array({nums, len});
    track_time("insertion sort", insertion_sort, {nums, len});

    delete[] nums;
  }

  return 0;
}