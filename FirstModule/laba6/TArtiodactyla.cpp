//
// Created by Алексей Долматов on 21.03.17.
//

#include "TArtiodactyla.h"


TArtiodactyla::TArtiodactyla(): TAnimal()
{
    AnOrder = Artiodactyla;
}


TArtiodactyla::TArtiodactyla(std::string const & name, size_t age): TAnimal(name, age)
{
    AnOrder = Artiodactyla;
}


