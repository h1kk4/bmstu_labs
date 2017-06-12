//
// Created by Алексей Долматов on 21.03.17.
//

#ifndef MYZOO_TZOO_H
#define MYZOO_TZOO_H

#include "TAnimal.h"
#include "All.h"

const float STEP = 0.5;

class TZoo {
    typedef TAnimal *TPtrAnimal;


    TPtrAnimal *Animals;

    size_t Capacity;

    size_t NumAnimals;

    std::string ZooName;

    float Time;

    float SomeTime;
public:
    TZoo(std::string const &name, size_t capacity);

    bool AddNewAnimal(TAnimal **newAnimal);

    void NewBorn(size_t i);

    bool Die(size_t i);

    void Work();

    ~TZoo();

    static TAnimal *create(std::string name);

    friend void Exchange(TZoo &zoo1, TZoo &zoo2, size_t num1);
};

void Exchange(TZoo &zoo1, TZoo &zoo2, size_t num1);

#endif //MYZOO_TZOO_H
