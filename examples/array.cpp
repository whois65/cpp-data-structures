#include <iostream>
#include "../include/array.hpp"

int main() {
    Array<int> arr = {1, 2}; // assignment with initializer_list
    arr.push_back(3); // add new element
    arr.pop_back();   // remove last element
}