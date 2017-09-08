//
// Created by Алексей Долматов on 18.02.17.
//

#ifndef LABA3_VECTOR_H
#define LABA3_VECTOR_H


class TVector {
private:
    double *Data;
    int Length;
public:
    ~TVector();

    TVector();

    TVector(const double *const data, const int len);

    int GetLen();

    TVector(const TVector &rhs);

    TVector &operator=(const TVector &rhs);

    double &operator[](int index);

    double operator[](int index) const;

    void Print();

};

//double* operator+(const double *const a, const Vector &b);
double *operator+(double *const a, TVector &b);

#endif //LABA3_VECTOR_H
