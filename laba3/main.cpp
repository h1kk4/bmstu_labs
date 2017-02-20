#include <iostream>
#include "TVector.h"

using namespace std;

int main() {
    double vec[9] = {0.8, 0.9, 8.4, 9, 12.4, 1, 2, 3, 4};
    TVector vec1(vec, 9);
    TVector vec2;
    vec2 = vec1;
    vec1.Print();
    vec2.Print();
    cout << vec1[2] << '\n';
    double *arr = new double[9];
    cout << "New array ";
    for (int i = 0; i < 9; i++) {
        arr[i] = 0.1 + i;
        cout << arr[i] << " ";
    }
    cout << '\n';
    double *tmp = arr + vec1;
    int k = 0;
    while (tmp[k] != '\0') {
        cout << tmp[k] << " ";
        k++;

    }
    return 0;
}