#include <stdexcept>
#include <iostream>

template<typename T>

class TVector {
public:
    using value_type = T;
    using size_type = size_t;
    using iterator = value_type *;
    using reference = value_type &;
    using const_reference = const value_type &;

private:
    value_type *Ptr;
    size_type Count;
    size_type InternalCapacity;
public:
    TVector()
            : Ptr(nullptr), Count(0), InternalCapacity(0) {}

    TVector(size_type capacity)
            : Count(0), InternalCapacity(capacity) {
        Ptr = new value_type[InternalCapacity];
    }

    ~TVector() {
        delete[] Ptr;
    }

    bool empty() const throw() {
        return size() == 0;
    }

    size_type size() const throw() {
        return Count;
    }

    size_type capacity() const throw() {
        return InternalCapacity;
    }

    iterator begin() const throw() {
        return Ptr;
    }

    iterator end() const throw() {
        return Ptr + Count;
    }

    void reserve(size_type size) {
        if (size < InternalCapacity) return;
        value_type *tmp = new value_type[size];
        memcpy(tmp, Ptr, Count * sizeof(value_type));
        delete[] Ptr;
        Ptr = tmp;
        InternalCapacity = size;
    }

    TVector(const TVector &rhs) {
        this->reserve(rhs.InternalCapacity);
        Count = rhs.Count;
        memcpy(Ptr, rhs.Ptr, Count * sizeof(value_type));
    }

    TVector &operator=(const TVector &rhs) {
        if (this == &rhs)
            return *this;
        this->reserve(rhs.InternalCapacity);
        Count = rhs.Count;
        memcpy(Ptr, rhs.Ptr, Count * sizeof(value_type));
    }

    void push_back(const value_type &value) {

        if (Count == InternalCapacity) {
            this->reserve(InternalCapacity * 2);
        }
        Ptr[Count] = value;
        Count++;
    }

    reference at(size_type index) {
        if (index >= 0 && index < Count)
            return Ptr[index];
        throw std::out_of_range("Out of range");
    }

    value_type at(size_type index) const {
        if (index >= 0 && index < Count)
            return Ptr[index];
        throw std::out_of_range("Out of range");
    }

    reference operator[](size_type index) {
        return Ptr[index];
    }

    const_reference operator[](size_type index) const {
        return Ptr[index];
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
            return Ptr[Count - 1];
        }
    }

    const_reference back() const {
        if (Ptr) {
            return Ptr[Count - 1];
        }
    }

    void clear() {
        delete[] Ptr;
        Count = 0;
        InternalCapacity = 0;
    }

    void pop_back() {
        if (Count) {
            Count--;
        }
    }

    void swap(TVector &other) throw() {
        std::swap(Ptr, other.Ptr);
        std::swap(Count, other.Count);
        std::swap(InternalCapacity, other.InternalCapacity);
    }

    void resize(size_type count, value_type value = value_type()) {
        size_type k = Count;
        Count = count;
        this->reserve(count);
        for (k; k < Count; k++)
            Ptr[k] = value;
    }

    iterator insert(iterator pos, const value_type &value) {
        if (pos > Ptr + Count) {
            throw std::out_of_range("Out of Range");
        }
        if (Count == InternalCapacity)
            this->reserve(InternalCapacity * 2);
        size_type k(0);

        for (size_type i = 0; i < Count; i++) {
            if (&Ptr[i] == pos)
                k = i;

        }

        Count++;
        size_type count = Count - 1;
        for (count; count >= k - 1; count--) {
            Ptr[count] = Ptr[count - 1];

        }

        Ptr[k - 1] = value;
        return pos;
    }

    void insert(iterator pos, size_type count, const value_type &value) {
        if (pos > Ptr + Count) {
            throw std::out_of_range("Out of Range");
        }
        size_type k(0);
        for (size_type i = 0; i < Count; i++) {
            if (&Ptr[i] == pos)
                k = i;
        }
        Count += count;
        if (Count == InternalCapacity)
            this->reserve(InternalCapacity * 2);
        for (Count; Count > k; Count++) {
            Ptr[Count] = Ptr[Count - 1];
        }
        for (size_type i = k; i < k + count; i++)
            Ptr[i] = value;
    }

    iterator erase(iterator pos) {
        if (pos >= Ptr + Count) throw std::out_of_range("Out of range");
        bool flag = false;
        for (int i = 0; i < Count; ++i) {
            if (&Ptr[i] == pos)
                flag = true;
            if (flag)
                Ptr[i] = Ptr[i + 1];
        }
        Count--;
        return pos;
    }

    iterator erase(iterator first, iterator last) {
        if (last >= Ptr + Count) throw std::out_of_range("Out of range");
        size_type start(0), stop(0);

        for (size_t i = 0; i < Count; i++) {
            if (&Ptr[i] == first)
                start = i;

            if (&Ptr[i] == last)
                stop = i;
        }
        size_type k = stop - start;
        //std::cout<<"start"<<start<<"stop"<<stop<<'\n';
        for (size_t i = start; i < Count - stop; i++) {
            Ptr[i] = Ptr[k + i];
        }
        Count = Count - k;
        return first;
    }


};