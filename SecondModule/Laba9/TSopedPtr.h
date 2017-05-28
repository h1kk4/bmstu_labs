//
// Created by Алексей Долматов on 26.03.17.
//
#include <iostream>

#ifndef MODULE2LABA9_TSOPEDPTR_H
#define MODULE2LABA9_TSOPEDPTR_H

template<class T>
class TScopedPtr {
    T *Ptr;
public:
    TScopedPtr(TScopedPtr const &) = delete;

    TScopedPtr &operator=(TScopedPtr const &) = delete;

    explicit TScopedPtr(T *p = nullptr)
            : Ptr(p) {}

    ~TScopedPtr() {
        delete Ptr;
    }

    void reset(T *p = nullptr) {
        if (Ptr) delete Ptr;
        Ptr = p;
    }

    T &operator*() const {
        return *Ptr;
    }

    T *operator->() const {
        return Ptr;
    }

    T *get() const throw() {
        return Ptr;
    }

    void swap(TScopedPtr &b) throw() {
        std::swap(Ptr, b.Ptr);
    }

    bool operator!() const throw() {
        return Ptr == nullptr;
    }

    explicit operator bool() const throw() {
        return Ptr != nullptr;
    }
};

template<class T>
inline bool operator==(TScopedPtr<T> const &p, std::nullptr_t) throw() {
    return !p;
}

template<class T>
inline bool operator==(std::nullptr_t, TScopedPtr<T> const &p) throw() {
    return !p;
}

template<class T>
inline bool operator!=(TScopedPtr<T> const &p, std::nullptr_t) throw() {
    return (bool) p;
}

template<class T>
inline bool operator!=(std::nullptr_t, TScopedPtr<T> const &p) throw() {
    return (bool) p;
}

template<class T>
inline void swap(TScopedPtr<T> &a, TScopedPtr<T> &b) throw() {
    a.swap(b);
}

// get_pointer(p) is a generic way to say p.get()
template<class T>
inline T *get_pointer(TScopedPtr<T> const &p) throw() {
    return p.get();
}

#endif //MODULE2LABA9_TSOPEDPTR_H
