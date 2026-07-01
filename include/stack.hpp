#pragma once
#include "../include/array.hpp"

template<typename T>
class Stack {
private:
    Array<T> data;

public:
    ~Stack() {
        while (data.size() > 0) pop();
    }
    void push(const T& val) {
        data.push_back(val);
    }

    void pop() {
        data.pop_back();
    }

    T& top() {
        if (data.size() == 0) throw std::out_of_range("Stack is empty");
        return data[data.size()-1];
    }

    bool empty() const {
        return data.size() == 0;
    }
};