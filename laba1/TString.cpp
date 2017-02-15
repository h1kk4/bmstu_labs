//
// Created by Алексей Долматов on 11.02.17.
//

#include <iostream>
#include "TString.h"

TString::~TString() {
    delete[] Data;
}

TString::TString() {
    Data = nullptr;
}

TString::TString(const char *data) {
    int len = 0;
    while (data[len] != '\0') {
        len++;
    }
    Data = new char[len + 1];
    for (int i = 0; i <= len; i++) {
        Data[i] = data[i];
    }
}

TString::TString(const TString &rhs) {
    int len = 0;
    while (rhs.Data[len] != '\0') {
        len++;
    }
    Data = new char[len + 1];
    for (int i = 0; i <= len; i++) {
        Data[i] = rhs.Data[i];
    }

}

TString &TString::operator=(const TString &rhs) {
    if (Data == rhs.Data) {
        return *this;
    } else {
        delete [] Data;
        int len = 0;
        while (rhs.Data[len] != '\0') {
            len++;
        }
        Data = new char[len + 1];
        for (int i = 0; i <= len; i++) {
            Data[i] = rhs.Data[i];
        }
        return *this;
    }
}

TString &TString::operator+=(const TString &rhs) {
    int len = 0, len1 = 0, len2 = 0, j(0);
    while (Data[len1] != '\0') {
        len1++;
    }
    while (rhs.Data[len2] != '\0') {
        len2++;
    }
    char *str = new char[len1];
    for (int i = 0; i < len1; i++) {
        str[i] = Data[i];
    }
    len = len1 + len2;
    delete[] Data;
    Data = new char[len + 1];
    for (int i = 0; i < len; i++) {
        if (i < len1) {
            Data[i] = str[i];
        } else {
            Data[i] = rhs.Data[j];
            j++;
        }
    }
    Data[len + 1] = '\0';
    delete [] str;
    return *this;
}


bool TString::operator==(const TString &rhs) const {
    if (Data == nullptr) {
        if (rhs.Data[0] == '\0') {
            return true;
        } else {
            return false;
        }
    }
    int len1 = 0, len2 = 0;
    while (Data[len1] != '\0') {
        len1++;
    }
    while (Data[len2] != '\0') {
        len2++;
    }
    if (len1 != len2) {
        return false;
    } else {
        bool flag = true;
        for (int i = 0; i <= len1; i++) {
            if (Data[i] != rhs.Data[i]) {
                flag = false;
                break;
            }
        }
        return flag;
    }
}


bool TString::operator<(const TString &rhs) const {
    int len1 = 0, len2 = 0;
    while (Data[len1] != '\0') {
        len1++;
    }
    while (rhs.Data[len2] != '\0') {
        len2++;
    }
    for (int i = 0; i < len1 + 1 && i < len2 + 1; i++) {
        if (Data[i] < rhs.Data[i]) {
            return true;
        }
    }
    return false;
}


size_t TString::Find(const TString &substr) const {
    int len1 = 0, len2 = 0;
    while (Data[len1] != '\0') {
        len1++;
    }
    while (substr.Data[len2] != '\0') {
        len2++;
    }
    if (len2 > len1) {
        return -1;
    } else {
        int k = 0;
        for (int i = 0; i < len1; i++) {
            if (Data[i] == substr.Data[k]) {
                int q = i;
                bool flag = true;
                while (k != len2) {
                    if (Data[q] != substr.Data[k]) {
                        flag = false;
                        break;
                    }
                    q++;
                    k++;
                }
                if (flag)
                    return i;
                k = 0;
            }
        }


        return -1;
    }

}

void TString::Replace(char oldSymbol, char newSymbol) {
    int len = 0;
    while (Data[len] != '\0') {
        len++;
    }
    for (int i = 0; i <= len; i++) {
        if (Data[i] == oldSymbol) {
            Data[i] = newSymbol;
        }
    }
}

size_t TString::Size() const {
    int len = 0;
    while (Data[len] != '\0') {
        len++;
    }
    return len;
}

bool TString::Empty() const {
    if (Data == nullptr || Data[0] == '\0') {
        return true;
    } else {
        return false;
    }
}

char TString::operator[](size_t index) const {
    return Data[index];
}

char &TString::operator[](size_t index) {
    return Data[index];
}

void TString::RTrim(char symbol) {
    int len = 0, i(0);
    while (Data[len] != '\0') {
        len++;
    }
    for (int j = len-1; j > 0; j--) {
        if (Data[j] == symbol) {
            i++;
        } else {
            break;
        }
    }
    int len2 = len - i;
    char *str = new char[len2];
    for (int j = 0; j < len2; j++) {
        str[j] = Data[j];
    }
    delete[] Data;
    Data = new char[len2 + 1];
    for (int j = 0; j < len2; j++) {
        Data[j] = str[j];
    }
    Data[len2] = '\0';
    delete [] str;

}

void TString::LTrim(char symbol) {
    int len = 0, i(0);
    while (Data[len] != '\0') {
        len++;
    }
    for (int j = 0; j < len; j++) {
        if (Data[j] == symbol) {
            i++;
        } else {
            break;
        }
    }
    int len2 = len - i;
    char *str = new char[len2+1];
    for (int j = len2-1; j >= 0; j--) {
        str[j] = Data[j+i];
    }
    delete[] Data;
    Data = new char[len2 + 1];
    for (int j = 0; j <len2; j++) {
        Data[j] = str[j];
    }
    Data[len2] = '\0';
    delete [] str;

}

std::ostream &operator<<(std::ostream &out, const TString &str) {
    out << str.Data;
    return out;
}


TString operator+(const TString &a, const TString &b) {
    TString c(a);
    c += b;
    return c;
}

bool operator!=(const TString &a, const TString &b) {

    if (a == b)
        return false;
    else
        return true;

}

bool operator>(const TString &a, const TString &b) {
    if (a < b || a == b)
        return false;
    else
        return true;
}
