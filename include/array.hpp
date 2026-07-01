#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array {
    private:
    T* data;
    int capacity;
    int length;

    void extendCapacity() {
        capacity *= 2;
        T* newData = new T[capacity];
        for (int i = 0;i<length;i++) newData[i] = data[i];
        delete[] data;
        data = newData;
    }
    public:
    Array() : capacity(2), length(0), data(new T[2]) {}

    Array(int c) : capacity(c), length(0), data(new T[c]) {}

    Array(const Array&arr) : capacity(arr.capacity), length(arr.size()), data(static_cast<T*>(::operator new(arr.capacity*sizeof(T)))) {
        for (int i = 0;i < length;i++) new (&data[i]) T(arr.data[i]);
    }

    Array(std::initializer_list<T> lists) : length(0) {
        capacity = lists.size() > 0 ? lists.size()*2 : 2;
        data = new T[capacity];
        for (const T&element:lists) push_back(element);
    }

    ~Array() {
        clear();
        ::operator delete(data);
    }

    Array& operator=(const Array&arr) {
        if (&arr == this) return *this;
        clear();
        ::operator delete(data);

        length = arr.size();
        capacity = arr.capacity;
        data = static_cast<T*>(::operator new(capacity*sizeof(T)));
        for (int i = 0;i < length;i++) new (&data[i]) T(arr.data[i]);
        return *this;
    }

    T* begin() {return data;}
    T* end() {return data + length;}
    T* begin() const {return data;}
    T* end() const {return data + length;}

    int size() const { return length; }
    T min() {
        T best = 0;
        for (const T&i:data) if (best > i) best = i;
        return best;
    }
    T max() {
        T best = data[0];
        for (const T&i:data) if (best < i) best = i;
        return best;
    }

    T& operator[](int index) {
        if (index < 0 || index >= length) throw std::out_of_range("Index out of bonds!");
        return data[index];
    }
    const T& operator[](int index) const {
        if (index < 0 || index >= length) throw std::out_of_range("Index out of bonds!");
        return data[index];
    }

    void push_back(const T&val) {
        if (capacity == length) extendCapacity();
        new (&data[length]) T(val);
        length++;
    }
    void pop_back() {
        if (length > 0) {
            length--;
            data[length].~T();
        }
    }
    void clear() {
        while (length > 0) pop_back();
    }
    bool empty() const {return length == 0;}

    friend std::ostream& operator<<(std::ostream& os, const Array<T>& arr) {
        os << '[';
        for (int i = 0; i <arr.size();i++) {
            if (i != arr.size()-1) os << arr[i] << ", ";
            else os << arr[arr.size()-1];
        }
        os << ']';
        return os;
    }
};

#endif
