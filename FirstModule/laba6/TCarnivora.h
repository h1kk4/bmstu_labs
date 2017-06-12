//
// Created by Алексей Долматов on 21.03.17.
//
#include "TAnimal.h"
#ifndef MYZOO_TCARNIVORA_H
#define MYZOO_TCARNIVORA_H

class TCarnivora :
        public TAnimal
{
public:
    TCarnivora();

    TCarnivora(std::string const & name, size_t age);

    virtual void Live(float time) override = 0;
};


#endif //MYZOO_TCARNIVORA_H
