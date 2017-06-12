//
// Created by Алексей Долматов on 21.03.17.
//

#include "TElephas.h"


TElephas::TElephas()
        :TProboscidea()
{
    BornAge = 15;
    DieAge = 70;
    AnType = Elephas;
}

TElephas::TElephas(std::string const & name, size_t age)
        :TProboscidea(name, age)
{
    BornAge = 15;
    DieAge = 70;
    AnType = Elephas;
}




void TElephas::Live(float time){
    //с 6 до 10 и с 17 до 21 ест
    if (time >= 8.f && time <= 21 )
        std::cout << "Elephas " << this->GetName() << " is eating."<< std::endl;
        //остальное время спит
    else
        std::cout << "Elephas " << this->GetName() << " is sleeping."<< std::endl;
}