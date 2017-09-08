#include <iostream>

template<size_t N>
void Print()
{
    std::cout << N << std::endl;
    Print<N + 1>();
}

template <>
void Print<101>()
{
    exit(1);
}

int main()
{
    Print<0>();

    return 0;
}