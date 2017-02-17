//
// Created by Алексей Долматов on 16.02.17.
//

#include "PC.h"
#include <string>
#include <iostream>
PC::PC() {
    Title="";
    Freaquence=0;
}

void PC::Print() {
    std::cout<< Title<<" ";
    std::cout<<Freaquence<<'\n';
}

void PC::SetDate(std::string &title, int &freaquence) {
    Title=title;
    Freaquence=freaquence;
}

PC::PC(std::string &title, int &freaquence) {
    SetDate(title,freaquence);
}

int PC::GetDate() {
    return Freaquence;
}

