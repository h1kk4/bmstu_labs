//
// Created by Алексей Долматов on 01.03.17.
//

#ifndef LABA5_STUDENT_H
#define LABA5_STUDENT_H

#include <iostream>
#include "TPerson.h"

class Student: public TPerson
{
private:
    int Year;
public:
    Student():TPerson(),Year(0){}
    Student(const std::string &name, int age, int year):TPerson(name,age), Year(year){}
    void Set_Year(int year){
        Year=year;
    }
    void AddYear(){
        Year++;
    }
   void Print(){
        std::cout<<"Name-"<<Name<<" Age-"<<Age<<" Year-"<<Year<<'\n';
    }
};
#endif //LABA5_STUDENT_H
