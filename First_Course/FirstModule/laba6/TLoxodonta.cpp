//
// Created by Алексей Долматов on 21.03.17.
//

#include "TLoxodonta.h"


TLoxodonta::TLoxodonta()
        : TProboscidea() {
    BornAge = 10;
    DieAge = 50;
    AnType = Loxodonta;
}

TLoxodonta::TLoxodonta(std::string const &name, size_t age)
        : TProboscidea(name, age) {
    BornAge = 10;
    DieAge = 50;
    AnType = Loxodonta;
}

void TLoxodonta::Live(float time) {
    //с 6 до 10 и с 17 до 21 ест
    if (time >= 8.f && time <= 21)
        std::cout << "Loxodonta " << this->GetName() << " is eating." << std::endl;
        //остальное время спит
    else
        std::cout << "Loxodonta " << this->GetName() << " is sleeping." << std::endl;
}