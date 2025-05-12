#include "templateVector.hpp"
#include <format>

template<typename T>
templatVector<T>::templatVector(size_t size) : capacity(size) {
    data = new T[size];
}

template<typename T>
templatVector<T>::templatVector(std::initializer_list<T> list, size_t size) {
    if (size == 0) {
        size = 15;
        capacity = size * 2;
    } else {
        capacity = size * 2;
        size_ = list.size();
    }

    data = new T[capacity];
    std::copy(list.begin(), list.end(), data);
}

template<typename T>
templatVector<T>::~templatVector() {
    delete[] data;
}

template<typename T>
T templatVector<T>::at(int index) {
    if (index < size_) {
        return *(data + index);
    }

    throw std::out_of_range(std::format("This vector can only store {}", capacity));
}

template<typename T>
void templatVector<T>::push_back(T obj) {
    if (size_ < capacity) {
        *(data + size_) = obj;
        ++size_;
    } else {
        std::cout << "Vector is full\n";
    }
}

template<typename T>
int templatVector<T>::findIndex(T obj) {
    for (size_t i = 0; i < size_; ++i) {
        if (this->at(i) == obj) {
            return i;
        }
    }
    return -1;
}

template<typename T>
T templatVector<T>::min() {
    if (size_ == 0) { throw std::emptyVector("Vector is empty"); } //* в будущем добавить exeption
    T minObj = data[0];
    for (size_t i = 1; i < size_; ++i) {
        if (minObj > data[i]) {
            minObj = data[i];
        }
    }
    return minObj;
}

template<typename T>
T templatVector<T>::max() {
    if (size_ == 0) { throw std::emptyVector("Vector is empty"); } //* в будущем добавить exeption
    T maxObj = data[0];
    for (size_t i = 1; i < size_; ++i) {
        if (maxObj < data[i]) {
            maxObj = data[i];
        }
    }
    return maxObj;
}

template<typename T>
void templatVector<T>::sort() {
    std::sort(data, data + size_);
}

template<typename T>
size_t templatVector<T>::lenght() const {
    return size_;
}
