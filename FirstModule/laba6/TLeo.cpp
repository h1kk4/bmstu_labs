//
// Created by Алексей Долматов on 21.03.17.
//

#include "TLeo.h"


TLeo::TLeo()
        :TCarnivora()
{
    BornAge = 3;
    DieAge = 15;
    AnType = Leo;
}


TLeo::TLeo(std::string const & name, size_t age)
        :TCarnivora(name, age)
{
    BornAge = 3;
    DieAge = 15;
    AnType = Leo;
}

void TLeo::Live(float time){

    if (time >= 5.f && time <= 6 || time >= 21 && time <= 22)
        std::cout << "Leo " << this->GetName() << " is eating."<< std::endl;

    else if (time > 6 && time <= 7 )
        std::cout << "Leo " << this->GetName() << " is running."<< std::endl;

    else if( time > 7 && time < 14 )
        std::cout << "Leo " << this->GetName() << " is resting."<< std::endl;

    else
        std::cout << "Leo " << this->GetName() << " is sleeping."<< std::endl;
}