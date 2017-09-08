//
// Created by Алексей Долматов on 21.03.17.
//

#include "TArtiodactyla.h"
#ifndef MYZOO_TGIRAFFA_H
#define MYZOO_TGIRAFFA_H

class TGiraffa :
        public TArtiodactyla
{
public:
    TGiraffa();

    TGiraffa(std::string const & name, size_t age);

    void Live(float time);

};




#endif //MYZOO_TGIRAFFA_H
