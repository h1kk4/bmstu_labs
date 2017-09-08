//
// Created by Алексей Долматов on 21.03.17.
//
#include "TZoo.h"


TZoo::TZoo(std::string const &name, size_t capacity)
        : Capacity(capacity), NumAnimals(0), ZooName(name), Time(0), SomeTime(0) {
    Animals = new TPtrAnimal[Capacity];
    memset(Animals, 0, sizeof(TPtrAnimal) * Capacity);
}

bool TZoo::AddNewAnimal(TAnimal **newAnimal) {
    // Проверяем корректность входного параметра
    if (newAnimal == nullptr)
        return false;

    // Зоопарк полон, нельзя добавить нового зверя
    if (NumAnimals == Capacity)
        return false;

    // Добавляем зверя в массив
    Animals[NumAnimals] = *newAnimal;

    // Забираем зверя у старого владельца, чтобы не удалить зверя дважды
    *newAnimal = nullptr;

    // Увеличиваем счетчик
    ++NumAnimals;

    return true;
}

bool GetRand(size_t age, size_t someAge) {
    if ((rand() % 10) * (age / someAge) > 4) return true;
    else return false;
}


bool TZoo::Die(size_t i) {
    if (Animals[i]->GetAge() >= Animals[i]->GetDieAge()
        && GetRand(Animals[i]->GetAge(), Animals[i]->GetDieAge())
        && NumAnimals > 0) {
        NumAnimals--;
        std::cout << Animals[i]->GetName() << " died." << std::endl;
        TAnimal *ptr = Animals[i];
        Animals[i] = Animals[NumAnimals];
        delete ptr;
        return true;
    } else return false;
}

void TZoo::NewBorn(size_t i) {
    if (Animals[i]->GetAge() >= Animals[i]->GetBornAge()
        && !Animals[i]->GetHaveChild()
        && GetRand(Animals[i]->GetAge(), Animals[i]->GetBornAge())) {
        for (size_t k = i + 1; k < NumAnimals; k++) {
            if (Animals[k]->GetAge() >= Animals[k]->GetBornAge()
                && !Animals[k]->GetHaveChild()
                && Animals[i]->GetType() == Animals[k]->GetType()) {
                if (NumAnimals == Capacity) return;
                std::string name;
                std::cout << Animals[i]->GetName() << " and " << Animals[k]->GetName() << " have child." << std::endl;
                std::cin >> name;
                TAnimal *child;
                switch (Animals[i]->GetType()) {
                    case (Elephas):
                        child = new TElephas(name, 0);
                        break;
                    case (Giraffa):
                        child = new TGiraffa(name, 0);
                        break;
                    case (Hippopotamus):
                        child = new THippopotamus(name, 0);
                        break;
                    case (Leo):
                        child = new TLeo(name, 0);
                        break;
                    case (Loxodonta):
                        child = new TLoxodonta(name, 0);
                        break;
                    case (Tigris):
                        child = new TTigris(name, 0);
                        break;
                }
                AddNewAnimal(&child);
                Animals[i]->Born();
                Animals[k]->Born();
            }
        }
    }
}
// Factory here
TAnimal *TZoo::create(std::string name) {
    if (name == "Giraffa") return new TGiraffa("Melan", 21);
    else if (name == "Elephas") return new TElephas("Dambo", 46);
    else if (name == "Leo") return new TLeo("Simba", 6);
    else if (name == "Tigris") return new TTigris("Shar", 19);
    else if (name == "Hippopotamus") return new THippopotamus("Jo", 15);
    else if (name == "Loxodonta") return new TLoxodonta("Gloaria", 24);
}
// Factory here
void TZoo::Work() {
    std::cout << ZooName << std::endl;
    if (Animals == nullptr) {
        std::cout << "No animals." << std::endl;
        return;
    }
    for (size_t i = 0; i < NumAnimals; ++i) {
        if (Animals[i] != nullptr) {
            if (!Die(i)) {
                // Демонстрация работы динамического полиморфизма
                Animals[i]->Live(Time);
                NewBorn(i);
                if (Time == 24)
                    Animals[i]->Ageplus();
            } else i--;
        }
    }
    Time += STEP;
    if (Time > 24.f)
        Time -= 24.f;
}


TZoo::~TZoo() {
    for (size_t i = 0; i < NumAnimals; ++i) {
        delete Animals[i];
    }
    delete[] Animals;
}

void Exchange(TZoo &zoo1, TZoo &zoo2, size_t num1) {
    if (zoo1.Animals[num1] == nullptr) {
        std::cout << "Exchanged failed." << std::endl;
        return;
    }
    size_t i = 0;
    while (zoo2.Animals[i]->GetOrder() != zoo1.Animals[num1]->GetOrder()) {
        i++;
        if (i == zoo2.NumAnimals) {
            std::cout << "Exchanged failed." << std::endl;
            return;
        }
    }
    TAnimal *ptr = zoo2.Animals[i];
    zoo2.Animals[i] = zoo1.Animals[num1];
    zoo1.Animals[num1] = ptr;
    ptr = nullptr;
    std::cout << "Exchange succeed. " << zoo2.Animals[i]->GetName() << " was exchanged to "
              << zoo1.Animals[num1]->GetName() << "." << std::endl;
    return;
}