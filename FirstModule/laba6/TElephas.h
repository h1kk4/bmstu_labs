//
// Created by Алексей Долматов on 21.03.17.
//
#include "TProboscidea.h"
#ifndef MYZOO_TELEPHAS_H
#define MYZOO_TELEPHAS_H


class TElephas :
        public TProboscidea
{
public:
    TElephas();

    TElephas(std::string const & name, size_t age);

    void Live(float time);
};


#endif //MYZOO_TELEPHAS_H
