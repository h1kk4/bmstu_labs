//
// Created by Алексей Долматов on 27.02.17.
//
#include <iostream>
#include "TCircle.h"
#ifndef LABA4_ELLIPSE_H
#define LABA4_ELLIPSE_H


class Ellipse:public TCircle{
protected:
    double axle_2;
public:
    Ellipse():TCircle(),axle_2(0){}
    Ellipse(double a1, double a2):TCircle(a1),axle_2(a2){}
    virtual void Print(){
        TCircle::Print();
        std::cout<<"Second Radius = "<<axle_2<<'\n';
    }
};


#endif //LABA4_ELLIPSE_H
