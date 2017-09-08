//
// Created by Алексей Долматов on 21.03.17.
//
#include "TAnimal.h"
#ifndef MYZOO_TARTIODACTYLA_H
#define MYZOO_TARTIODACTYLA_H

class TArtiodactyla :
        public TAnimal
{
public:
    TArtiodactyla();

    TArtiodactyla(std::string const & name, size_t age);

    virtual void Live(float time) override = 0;

};


#endif //MYZOO_TARTIODACTYLA_H
