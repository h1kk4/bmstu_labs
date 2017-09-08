#include <iostream>
#include "InfInt.h"
#include <thread>
#include <future>

InfInt factorial(InfInt n) {
    InfInt res = 1;
    for(InfInt i=1;i<=n;++i)
        res*=i;
    return res;
}


InfInt C(InfInt n, InfInt k) {
    if (k > n) return 0;
    std::future<InfInt> a = std::async(factorial, n);
    InfInt a_int = a.get();
    std::future<InfInt> b = std::async(factorial, k);
    InfInt b_int = b.get();
    std::future<InfInt> d = std::async(factorial, n - k);
    InfInt d_int = d.get();
    return InfInt(a_int / (b_int * d_int));
}

int main() {

    std::cout << C(90, 45);

}

