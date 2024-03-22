#include <iostream>
#include <iomanip>
#include <span>
#include <chrono>
#include <random>
#include "sorting.h"

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