//
// Created by Алексей Долматов on 21.03.17.
//
#include "THippopotamus.h"


THippopotamus::THippopotamus(): TArtiodactyla()
{
    BornAge = 9;
    DieAge = 40;
    AnType = Hippopotamus;
}



THippopotamus::THippopotamus(std::string const & name, size_t age)
        : TArtiodactyla(name, age)
{
    BornAge = 9;
    DieAge = 40;
    AnType = Hippopotamus;
}

void THippopotamus::Live(float time){
    //с 1 и с 5 ест
    if (time >= 1.f && time <= 5)
        std::cout << "Hippopotamus " << this->GetName() << " is eating."<< std::endl;
        //с 5 до 12 и с 18 до 1 спит
    else if (time > 5 && time <= 12 || time >= 18.f && time <= 24 || time < 1 )
        std::cout << "Hippopotamus " << this->GetName() << " is sleeping."<< std::endl;
        //остальное время плавает
    else
        std::cout << "Hippopotamus " << this->GetName() << " is swimming."<< std::endl;
}

