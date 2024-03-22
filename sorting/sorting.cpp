#include "sorting.h"
#include "bst.h"

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
