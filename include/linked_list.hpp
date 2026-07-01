#pragma once

#include "array.hpp"

template <typename T>
struct ListNode {
    T data;            
    ListNode<T>* next;     

    ListNode(T val) : data(val), next(nullptr) {}
};

template<typename T>
class LinkedList{
    private:
    int sz;
    public:
    ListNode<T>* head;
    ListNode<T>* tail;

    LinkedList() : head(nullptr), tail(nullptr), sz(0) {}

    LinkedList(std::initializer_list<T> lists) : head(nullptr), tail(nullptr), sz(0) {
        for (const T&element:lists) push_back(element);
    }

    ~LinkedList() {clear();}

    int size() const {return sz;}

    int operator[](int index) {
        if (index > sz) return -1;
        ListNode<T>* curr = head;
        for (int i = 0;curr != nullptr; i++) {
            if (index == i) return curr->data;
            curr = curr->next;
        }
        return -1;
    }

    void insertAtHead(int val) {
        ListNode<T>* newNode = new ListNode(val);
        newNode->next = head;
        head = newNode;

        if (tail == nullptr) tail = head;
        
        sz++;
    }

    void push_back(int val) {
        ListNode<T>* newNode = new ListNode(val);
        if (head == nullptr) {
            head = newNode;
            tail = head;
            sz++;
            return;
        }
        tail->next = newNode;
        tail = newNode;
        sz++;
    }

    void insertAt(int index, int val) {
        if (head == nullptr) return;
        if (index >= sz) {
            push_back(val);
        }
        ListNode<T>* curr = head;
        ListNode<T>* NEW = new ListNode(val);

        if (tail == nullptr) tail = head;

        for (int i = 1;i <= index; i++) {
            if (index == sz-1) tail = curr;
            if (index == i) {
                NEW->next = curr->next;
                curr->next = NEW;
            }
            else curr = curr->next;
        }
        sz++;
    }

    void editAt(int index, int val) {
        if (head == nullptr) return;
        if (index >= sz) return;

        ListNode<T>* curr = head;

        for (int i = 1;i <= index; i++) {
            if (index == i) {
                curr->data = val;
            }
            else curr = curr->next;
        }
    }

    void pop_back() {
        if (head == nullptr) return;

        ListNode<T>* curr = head;
        for (int i = 1;i <= sz-1; i++) {
            if (i == sz-1) tail = curr;
            curr = curr->next;
        }
        sz--;
    }

    void removeAt(int index) {
        if (head == nullptr) return;
        if (index >= sz) return;

        ListNode<T>* curr = head;
        for (int i = 1;i <= index; i++) {
            if (index == sz-1) tail = curr;
            if (index == i) {
                ListNode<T>* victim = curr->next;
                curr->next = victim->next;
                delete victim;
            }
            else curr = curr->next;
        }
        sz--;
    }

    void deleteMiddle() {
        if (head == nullptr) return;
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        ListNode<T>* curr = head;

        int mid = sz/2;
        for (int i = 1;i <= mid; i++) {
            if (i == mid) {
                ListNode<T>* victim = curr->next;
                curr->next = victim->next;
                delete victim;
            }
            else curr = curr->next;
        }
        
        sz--;
    }

    void reverse() {
        tail = head;
        ListNode<T>* prev = nullptr;
        ListNode<T>* curr = head;
        ListNode<T>* next = nullptr;
        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    // utils
    bool contains(int val) {
        if (head == nullptr) return 0;
        ListNode<T>* curr = head;
        while (curr != nullptr) {
            if (val == curr->data) return true;
            curr = curr->next;
        }
        return false;
    };

    int search(int val) {
        if (head == nullptr) return -1;
        ListNode<T>* curr = head;
        int index = 0;
        while (curr != nullptr) {
            index++;
            if (val == curr->data) return index;
            curr = curr->next;
        }
        return -1;
    };
    
    void fromArray(Array<int> arr) {
        clear();
        for (const int& i: arr) push_back(i);
    }

    Array<int> toArray() {
        Array<int> r;
        ListNode<T>* curr = head;
        if (curr == nullptr) return r;
        while (curr != nullptr) {
            r.push_back(curr->data);
            curr = curr->next;
        }
        return r;
    }

    int max() {
        if (head == nullptr) return 0;
        int best = head->data;
        ListNode<T>* curr = head;
        while (curr != nullptr) {
            if (best < curr->data) best = curr->data;
            curr = curr->next;
        }
        return best;
    }

    int min() {
        if (head == nullptr) return 0;
        int best = head->data;
        ListNode<T>* curr = head;
        while (curr != nullptr) {
            if (best > curr->data) best = curr->data;
            curr = curr->next;
        }
        return best;
    }

    friend std::ostream& operator<<(std::ostream& os, const LinkedList& arr) {
        std::string text = "[";
        ListNode<T>* curr = arr.head;
        os << '[';
        for (int i = 1; i <= arr.sz;i++) {
            os << curr->data;
            if (i != arr.sz) os << ", ";
            curr = curr->next; 
        }
        os << ']';
        return os;
    }

    void clear() {
        ListNode<T>* curr = head;
        while (curr != nullptr) {
            ListNode<T>* nextNode = curr->next;
            delete curr;
            curr = nextNode;
        }
        head = nullptr;
        tail = nullptr;
        sz = 0;
    }
};