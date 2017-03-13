//
// Created by Алексей Долматов on 11.03.17.
//

#ifndef MODULE2LABA1_CASTEXCEPTION_H
#define MODULE2LABA1_CASTEXCEPTION_H


#include <exception>

class CastException: public std::exception {

};

class OverFlow : public  CastException{

};

class WrongChar : public  CastException{

};
#endif //MODULE2LABA1_CASTEXCEPTION_H
