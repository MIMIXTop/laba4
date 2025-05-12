#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <format>
#include <exception>
#include <concepts>
#include "MyException.hpp"

template <typename T>
concept my_type = requires (T item) {
    item == item, item < item,item > item;
};

template<typename T>
class templatVector
{
private:
    T* data;
    size_t capacity = 0;
    size_t size_ = 0;
public:
    templatVector(size_t size);
    templatVector(std::initializer_list<T> list, size_t size = 15);
    ~templatVector() ;
    T at(int index) ;
    void push_back(T obj) ;
    int findIndex(T obj) ;
    T min() ;
    T max() ;
    void sort();
    size_t lenght() const;
};
