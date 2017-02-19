//
// Created by Алексей Долматов on 18.02.17.
//

#include "TVector.h"
#include <cstring>
#include <iostream>
TVector::~TVector() {
    delete[] Data;
}

TVector::TVector() {
    Data = nullptr;
    Length = 0;
}

TVector::TVector(const double *const data, const int len) {
    Length = len;
    Data = new double[Length];
    memcpy(Data, data, len * sizeof(double));
}

TVector::TVector(const TVector &rhs) {
    Length = rhs.Length;
    Data = new double[Length];
    memcpy(Data, rhs.Data, Length * sizeof(double));

}

TVector &TVector::operator=(const TVector &rhs) {
    if (this == &rhs) {
        return *this;
    }
    Length = rhs.Length;
    delete[] Data;
    Data = new double[Length];
    memcpy(Data, rhs.Data, Length * sizeof(double));
    return *this;
}

double &TVector::operator[](int index) {
    return Data[index];
}

double TVector::operator[](int index) const {
    return Data[index];
}

int TVector::GetLen() {
    return Length;
}

double *TVector::GetData() {
    return Data;
}

void TVector::Print() {
    if (Length==0){
        std::cout<<"Array is empty";
    }
    std::cout<<"Array ";
    for (int i=0;i<Length;i++){
        std::cout<<Data[i]<<" ";
    }
    std::cout<<'\n';
}

double * operator+(double *const a, TVector &b) {
    int len1(0), len2=b.GetLen(), j(0);
    len1=len2;
    double *mas = new double [len1+len2];
    for (int i = 0; i <len1+len2; i++) {
        if (i < len1) {
            mas[i] = a[i];
        } else {
            mas[i] = b.GetData()[j];
            j++;
        }
    }
    return mas;
}

