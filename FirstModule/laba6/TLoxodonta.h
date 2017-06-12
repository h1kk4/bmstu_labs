//
// Created by Алексей Долматов on 21.03.17.
//

#ifndef MYZOO_TLOXODONTA_H
#define MYZOO_TLOXODONTA_H
#include "TProboscidea.h"
class TLoxodonta :
        public TProboscidea
{
public:
    TLoxodonta();

    TLoxodonta(std::string const & name, size_t age);

    void Live(float time);
};


#endif //MYZOO_TLOXODONTA_H
