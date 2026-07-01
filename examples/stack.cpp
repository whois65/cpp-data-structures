#include <iostream>
#include "../include/stack.hpp"

template <typename T>
std::ostream& operator<<(std::ostream& os, const Stack<T>& s) {
    os << '[';
    Node<T>* curr = s.head;
    int i = 0;
    for (;curr != nullptr;i++) {
        if (i == s.size) os << curr->data;
        else os << curr->data << " ";
        curr = curr->next;
    }
    os << ']';
    return os;
}

int main() {
    Stack<int> stc;
    stc.push(1); 
    std::cout << "push 1 into the stack: " << std::endl;
    stc.push(2);
    std::cout << "push 2 into the stack: " << std::endl;
    std::cout << "We can just take 2" << stc.top() << std::endl;
    stc.pop();
    return 0;
}