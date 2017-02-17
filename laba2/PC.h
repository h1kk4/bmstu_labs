//
// Created by Алексей Долматов on 16.02.17.
//

#ifndef LABA2_PC_H
#define LABA2_PC_H


#include <string>

class PC {
private:
    std::string Title;
    int Frequency;
public:
    PC();
    PC(std::string &title, int &frequency);
    void SetDate(std::string &title, int &frequency);
    int GetDate();
    void Print();

};


#endif //LABA2_PC_H
