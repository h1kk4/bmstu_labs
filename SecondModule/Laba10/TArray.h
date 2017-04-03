//
// Created by Алексей Долматов on 28.03.17.
//
#include <iostream>

#ifndef MODULE2LABA10_TARRAY_H
#define MODULE2LABA10_TARRAY_H

template<class T, std::size_t N>
struct TArray {
    using value_type = T;
    using size_type = size_t;
    using reference = value_type &;
    using const_reference = const value_type &;
    using pointer = T *;
    using const_pointer = const T *;
    using iterator = value_type *;
    using const_iterator = const value_type *;
    value_type *Ptr;

    TArray() {
        Ptr = new T[N];
    }

    ~TArray() {
        delete[] Ptr;
    }

    TArray(std::initializer_list<T> init) : TArray() {
        size_type i = 0;
        for (auto &v:init) {
            Ptr[i] = v;
            ++i;
        }
    }

    reference at(size_type index) {
        if (index >= 0 && index < N)
            return Ptr[index];
        throw std::out_of_range("Out of range");
    }

    const_reference at(size_type index) const {
        if (index >= 0 && index < N)
            return Ptr[index];
        throw std::out_of_range("Out of range");
    }

    reference operator[](size_type index) {
        return Ptr[index];
    }

    const_reference operator[](size_type index) const {
        return Ptr[index];
    }

    iterator begin() const throw() {
        return Ptr;
    }

    iterator end() const throw() {
        return Ptr + N;
    }
    
    reference front() {
        if (Ptr) {
            return Ptr[0];
        }
    }

    const_reference front() const {
        if (Ptr) {
            return Ptr[0];
        }
    }

    reference back() {
        if (Ptr) {
            return Ptr[N - 1];
        }
    }

    const_reference back() const {
        if (Ptr) {
            return Ptr[N - 1];
        }
    }

    iterator data() throw() {
        return Ptr;
    }

    const_iterator data() const throw() {
        return Ptr;
    }

    bool empty() const throw()
    {
        return (N==0);
    }

    size_type size() const throw()
    {
        return N;
    }

    size_type max_size() const throw()
    {
        return N;
    }

    void fill(const value_type &val) {
        for (size_type j=0; j < N; ++j)
            Ptr[j] = val;
    }

    void swap(TArray<T, N> &other) throw() {
        std::swap(Ptr, other.Ptr);
    }



};

#endif //MODULE2LABA10_TARRAY_H
