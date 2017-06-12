//
// Created by Алексей Долматов on 21.03.17.
//

#include "TGiraffa.h"


TGiraffa::TGiraffa(): TArtiodactyla()
{
    BornAge = 4;
    DieAge = 25;
    AnType = Giraffa;
}


TGiraffa::TGiraffa(std::string const & name, size_t age)
        : TArtiodactyla(name, age)
{
    BornAge = 4;
    DieAge = 25;
    AnType = Giraffa;
}

void TGiraffa::Live(float time){
    //с 6 до 10 и с 17 до 21 ест
    if (time >= 6.f && time <= 10 || time >= 17 && time <= 21)
        std::cout << "Giraffe " << this->GetName() << " is eating."<< std::endl;
        //с 10 до 17 отдыхает
    else if (time > 10 && time < 17 )
        std::cout << "Giraffe " << this->GetName() << " is resting."<< std::endl;
        //остальное время спит
    else
        std::cout << "Giraffe " << this->GetName() << " is sleeping."<< std::endl;
}
