#pragma once
#include <vector>
#include <iostream>
#include <iterator>

template<typename T, int a>
class Array {
public:
    std::vector<T> field;

    Array(const size_t x) {
        for (int i = 0; i < a; i++) {
            field.push_back(x);
        }
    }
    T& operator[](T index) {
        return field[index];
    }

    typename std::vector<T>::iterator begin() {
        return field.begin();
    }
    typename std::vector<T>::iterator end() {
        return field.end();
    }

};

