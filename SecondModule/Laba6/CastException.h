//
// Created by Алексей Долматов on 11.03.17.
//

#ifndef MODULE2LABA1_CASTEXCEPTION_H
#define MODULE2LABA1_CASTEXCEPTION_H


#include <exception>
#include <iostream>
class CastException: public std::exception {

};

class OverFlow : public  CastException{
public:
    void what() {
        std::cout << "It's too big string" << '\n';
    }
};

class WrongChar : public  CastException {
public:
    void what() {
        std::cout << "It's wrong string" << '\n';
    }

};
class NoFoo : public CastException
{
public:
	void what() {
        std::cout << "Missing function" << '\n';
    }
};
#endif //MODULE2LABA1_CASTEXCEPTION_H
