//
// Created by Алексей Долматов on 20.03.17.
//

#ifndef MODULE2LABA5_TNOTCOPYABLE_H
#define MODULE2LABA5_TNOTCOPYABLE_H
#pragma warning(disable:4996)

#include <exception>
#include <cstdio>
#include <string>
#include <iostream>

struct FileAlreadyOpened
        : public std::exception {
    FileAlreadyOpened() = default;

    FileAlreadyOpened(const char *const message)
            : std::exception() {}
};

class TNotCopyable {
    FILE *Descriptor;

public:
    TNotCopyable()
            : Descriptor(nullptr) {}

    TNotCopyable(const TNotCopyable &) = delete;

    TNotCopyable &operator=(const TNotCopyable &) = delete;

    void OpenToWrite(std::string const &fileName) {
        if (Descriptor != nullptr)
            throw FileAlreadyOpened();
        Descriptor = fopen(fileName.c_str(), "w");
    }

    void OpenToRead(std::string const &fileName) {
        if (Descriptor != nullptr)
            throw FileAlreadyOpened();
        Descriptor = fopen(fileName.c_str(), "r");
    }

    void Close() throw() {
        if (Descriptor != nullptr) {
            fclose(Descriptor);
            Descriptor = nullptr;
        }
    }

    FILE *Get() {
        return Descriptor;
    }


};

class RAII {
private:
    TNotCopyable *Ptr;
public:
    RAII() {}

    RAII(TNotCopyable *ptr) : Ptr(ptr) {

    }

    ~RAII() {
        if (Ptr != nullptr)
            Ptr->Close();
    }
};

#endif //MODULE2LABA5_TNOTCOPYABLE_H
