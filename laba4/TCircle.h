//
// Created by Алексей Долматов on 25.02.17.
//
#include <iostream>
#ifndef LABA4_TCIRCLE_H
#define LABA4_TCIRCLE_H



class TCircle {
protected:
    double radius;
public:
    TCircle():radius(0){}
    TCircle(const double r):radius(r){}
    virtual void  Print(){
        std::cout<< "Radius = "<<radius<<'\n';
    }
};


#endif //LABA4_TCIRCLE_H
