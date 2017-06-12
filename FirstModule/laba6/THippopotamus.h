//
// Created by Алексей Долматов on 21.03.17.
//
#include "TArtiodactyla.h"
#ifndef MYZOO_THIPPOPOTAMUS_H
#define MYZOO_THIPPOPOTAMUS_H

class THippopotamus :
        public TArtiodactyla
{
public:
    THippopotamus();

    THippopotamus(std::string const & name, size_t age);

    void Live(float time);

};


#endif //MYZOO_THIPPOPOTAMUS_H
