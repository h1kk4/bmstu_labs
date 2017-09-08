//
// Created by Алексей Долматов on 21.03.17.
//

#ifndef MYZOO_TPROBOSCIDEA_H
#define MYZOO_TPROBOSCIDEA_H
#include "TAnimal.h"
class TProboscidea :
        public TAnimal
{
public:
    TProboscidea();

    TProboscidea(std::string const & name, size_t age);

    virtual void Live(float time) override = 0;
};


#endif //MYZOO_TPROBOSCIDEA_H
