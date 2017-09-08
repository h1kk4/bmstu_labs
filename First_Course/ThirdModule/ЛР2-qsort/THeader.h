//
// Created by Алексей Долматов on 01.05.17.
//
#include <iostream>

#ifndef QSORT_THEADER_H
#define QSORT_THEADER_H

template<class It, class Cmp>
void qsort(It begin, It end, Cmp cmp) {
    if (begin != end) {
        It left = begin;
        It right = end;
        It piv = begin;
        ++left;
        while (left != right) {
            if (cmp(*left, *piv)) {
                ++left;
            } else {
                --right;
                while ((left != right) && cmp(*piv, *right)) {
                    --right;
                }
                if (left != right) {
                    std::iter_swap(left, right);
                }
            }
        }
        --left;
        std::iter_swap(piv, left);
        qsort(begin, left, cmp);
        qsort(right, end, cmp);
    }
}

#endif //QSORT_THEADER_H
