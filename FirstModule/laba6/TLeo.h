//
// Created by Алексей Долматов on 21.03.17.
//
#ifndef MYZOO_TLEO_H
#define MYZOO_TLEO_H
#include "TCarnivora.h"
class TLeo :
        public TCarnivora
{
public:
    TLeo();

    TLeo(std::string const & name, size_t age);

    void Live(float time);
};


#endif //MYZOO_TLEO_H
