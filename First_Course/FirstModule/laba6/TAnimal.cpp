//
// Created by Алексей Долматов on 21.03.17.
//
#include "TAnimal.h"


TAnimal::TAnimal()
        : Name(), Age(0), BornAge(0), DieAge(0), HaveChild(false), AnType(None), AnOrder(No) {}

TAnimal::TAnimal(const std::string &name, size_t age)
        : Name(name), Age(age), HaveChild(false) {}

std::string TAnimal::GetName() const {
    return Name;
}

size_t TAnimal::GetAge() const {
    return Age;
}

size_t TAnimal::GetBornAge() const {
    return BornAge;
}

size_t TAnimal::GetDieAge() const {
    return DieAge;
}

void TAnimal::Born() {
    HaveChild = true;
}

void TAnimal::Ageplus() {
    Age++;
}

bool TAnimal::GetHaveChild() const {
    return HaveChild;
}

AnimalType TAnimal::GetType() const {
    return AnType;
}

AnimalOrder TAnimal::GetOrder() const {
    return AnOrder;
}