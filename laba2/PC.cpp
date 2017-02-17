//
// Created by Алексей Долматов on 16.02.17.
//

#include "PC.h"
#include <string>
#include <iostream>
PC::PC() {
    Title="";
    Frequency=0;
}

void PC::Print() {
    std::cout<< Title<<" ";
    std::cout<<Frequency<<'\n';
}

void PC::SetDate(std::string &title, int &frequency) {
    Title=title;
    Frequency=frequency;
}

PC::PC(std::string &title, int &frequency) {
    SetDate(title,frequency);
}

int PC::GetDate() {
    return Frequency;
}

