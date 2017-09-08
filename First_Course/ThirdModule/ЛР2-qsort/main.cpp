#include <iostream>
#include <vector>
#include "THeader.h"


int main() {

    std::vector<int> vec;
    for (int i = 0; i < 40; ++i) {
        vec.push_back(rand() % 999);
    }
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << '\n';

    qsort(vec.begin(), vec.end(), std::less<int>());
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }

    return 0;
}