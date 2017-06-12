#pragma once

#include <thread>
#include <iostream>
#include "All.h"


int main() {
    TZoo myZoo("Zoo 1", 10);
    TZoo otherZoo("Zoo 2", 5);

    TAnimal *Elephant = new TElephas("Dambo", 65);
    if (!myZoo.AddNewAnimal(&Elephant))
        delete Elephant;
    TAnimal *Giraffe = new TGiraffa("Melman", 23);
    if (!myZoo.AddNewAnimal(&Giraffe))
        delete Giraffe;
    TAnimal *Hippo = new THippopotamus("Jo", 14);
    if (!myZoo.AddNewAnimal(&Hippo))
        delete Hippo;
    TAnimal *Lion = new TLeo("Simba", 10);
    if (!myZoo.AddNewAnimal(&Lion))
        delete Lion;
    TAnimal *El = new TLoxodonta("Gloria", 16);
    if (!myZoo.AddNewAnimal(&El))
        delete El;
    TAnimal *Tiger = new TTigris("Shar", 24);
    if (!otherZoo.AddNewAnimal(&Tiger))
        delete Tiger;
    TAnimal *Elep = new TElephas("Oleg", 77);
    if (!otherZoo.AddNewAnimal(&Elep))
        delete Elep;
    TAnimal *Gir = new TGiraffa("Pasha", 19);
    if (!otherZoo.AddNewAnimal(&Gir))
        delete Gir;
    TAnimal *Hip = TZoo::create("Tigris");//new THippopotamus("Petya", 29);
    if (!myZoo.AddNewAnimal(&Hip))
        delete Hip;

    int TimeToEx = 0;

    for (size_t i = 0; i < 100; ++i) {
        myZoo.Work();
        std::cout << std::endl;
        otherZoo.Work();
        std::cout << std::endl;
        if (TimeToEx == 5) {
            size_t num = 0;
            std::cout << "Which animal do you want to exchange? Enter number." << std::endl;
            std::cin >> num;
            Exchange(myZoo, otherZoo, (num - 1));
            TimeToEx = 0;
        }
        TimeToEx++;
        // поток ждет 1 секунду
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    system("pause");
}