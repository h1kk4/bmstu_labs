//
// Created by Алексей Долматов on 28.02.17.
//

#ifndef LABA5_TPERSON_H
#define LABA5_TPERSON_H

#include <istream>

class TPerson {
protected:
    std::string Name;
    int Age;
public:
    TPerson(): Name(""), Age(0){}
    TPerson(const std::string &name,int age):Name(name),Age(age){}
    void SetName(const std::string &name){
        Name=name;
    };
    void SetAge(int age){
        Age=age;
    };
    virtual void Print(){
        std::cout<<"Name-"<<Name<<" Age-"<<Age<<'\n';
    }
};


#endif //LABA5_TPERSON_H
