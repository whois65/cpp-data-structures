#include <iostream>
#include "../include/linked_list.hpp"

int main() {
    LinkedList<int> list = {1, 2}; // assignment with initializer_list
    list.push_back(3); // add new element
    list.pop_back();   // remove last element
}