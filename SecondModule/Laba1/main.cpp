#include <iostream>
#include <cmath>
#include "CastException.h"


int intFromString(const char *data) {
    int x(0), size = 0;
    int k(0);
    bool flag = true;
    for (int i = 0; data[i] != '\0'; i++) {
        if (isalpha(data[i])) {
            throw WrongChar();
        }
        k++;
        if (data[0]=='-') continue;
        if (flag && (data[i] == '0')) {

        } else {
            flag = false;
        }
        if (!flag) {
            size++;
        }


    }

    if (size >11 ) {
        throw OverFlow();
    } else {
        if (data[0] != '-') {
            for (int i = 0; i < k; i++) {
                x = (int) ((int(data[k - i - 1]) - 48) * pow(10, i)) + x;
            }
        } else {
            for (int i = 0; i < k - 1; i++) {
                x = -((int) ((int(data[k - i - 1]) - 48) * pow(10, i))) + x;
            }
        }
        if((x>0&&data[0]!='-')||(x<0&&data[0]=='-'))
            return x;
        else{
            throw OverFlow();
        }

    }

}

bool boolFromString(const char *data) {

    std::string str(data);
    int i(0);

    while (i!=str.size()) {
        str[i]=char(tolower(data[i]));
        i++;

    }

    if (!str.compare("true") || !str.compare("1")) {
        return true;
    } else if (!str.compare("false") || !str.compare("0")) {
        return false;
    } else throw WrongChar();
}

float floatFromString(const char *data) {
    int k(0), dot(0);
    float x(0);
    for (int i = 0; data[i] != '\0'; i++) {
        k++;
        if (isalpha(data[i])) {
            throw WrongChar();
        }
        if (data[i] == '.' || data[i] == ',') dot = i;

    }

    if (data[0] != '-') {
        for (int i = 0; i < dot; i++) {
            x = (float) ((int(data[dot - i - 1]) - 48) * pow(10, i)) + x;
            //std::cout<<"Before"<<i<<" "<<x<<'\n';
        }
        for (int i = 1; i < k - dot; i++) {
            x = (float) ((int(data[dot + i]) - 48) * pow(10, -i)) + x;
            //std::cout<<i<<" "<<x<<'\n';
        }
    } else {
        for (int i = 0; i < dot - 1; i++) {
            x = -((float) ((int(data[dot - i - 1]) - 48) * pow(10, i))) + x;
            //std::cout<<"Before"<<i<<" "<<x<<'\n';
        }
        for (int i = 1; i < k - dot; i++) {
            x = -((float) ((int(data[dot + i]) - 48) * pow(10, -i))) + x;
            //std::cout<<i<<" "<<x<<'\n';
        }
    }

    return x;
}

int main() {
    //std::cout << std::numeric_limits<int>::min() <<'\n'<< std::numeric_limits<int>::max()<<'\n';
    try {
        intFromString("-002147483648");
    }

    catch (OverFlow &exc) {
        std::cout << "It's too big string"<<'\n';
    }
    try {
        floatFromString("012Q343.4");
    }
    catch (WrongChar &exc) {
        std::cout << "It's wrong string"<<'\n';
    }
    try
    {
        boolFromString("False");
    }
    catch (WrongChar &exc)
    {
        std::cout<<"It's not bool"<<'\n';
    }



    return 0;
}