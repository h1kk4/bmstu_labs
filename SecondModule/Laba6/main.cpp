#include <iostream>
#include <cmath>
#include "CastException.h"

template<typename T>
T fromString(const char *data){
    throw NoFoo();
}

template<>

int fromString(const char *data) {
    int x(0), size = 0;
    int k(0);
    bool flag = true;
    for (int i = 0; data[i] != '\0'; i++) {
        if (isalpha(data[i])) {
            throw WrongChar();
        }
        if (data[i] == '.' || data[i] == ',') break;
        k++;

        if (data[0] == '-') continue;
        if (flag && (data[i] == '0')) {

        } else {
            flag = false;
        }
        if (!flag) {
            size++;
        }


    }

    if (size > 11) {
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
        if ((x >= 0 && data[0] != '-') || (x <= 0 && data[0] == '-'))
            return x;
        else {
            throw OverFlow();
        }

    }

}

template<>
bool fromString(const char *data) {

    std::string str(data);
    int i(0);

    while (i != str.size()) {
        str[i] = char(tolower(data[i]));
        i++;

    }

    if (!str.compare("true") || !str.compare("1")) {
        return true;
    } else if (!str.compare("false") || !str.compare("0")) {
        return false;
    } else throw WrongChar();
}

template<>
float fromString(const char *data) {
    int k(0), dot(0), count(0);
    float x(0);
    for (int i = 0; data[i] != '\0'; i++) {
        k++;
        //std::cout<<"k-"<<'('<<k<<')'<<'\n';
        if (isalpha(data[i])) {
            throw WrongChar();
        }
        if (data[i] == '.' || data[i] == ',') {
            dot = i;
            count++;
        }

    }
    if (count > 1) throw WrongChar();

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
            //std::cout << "Before" << i << " " << x << '\n';
        }
        for (int i = 1; i < k - dot; i++) {
            x = -((float) ((int(data[dot + i]) - 48) * pow(10, -i))) + x;
            //std::cout << i << " " << x << '\n';
        }
    }

    return x;
}

int main() {
    //std::cout << std::numeric_limits<int>::min() <<'\n'<< std::numeric_limits<int>::max()<<'\n';
    std::cout << 1 << '=' << fromString<int>("-00214748364") << '\n';
    std::cout << 2 << '=' << fromString<int>("-002147483648") << '\n';
    std::cout << 3 << '=' << fromString<int>("002147483647") << '\n';
    std::cout << 4 << '=' << fromString<int>("0021474.83647") << '\n'; // Должно получится 21474
    std::cout << 5 << '=' << fromString<float>("0") << '\n';
    try {
        fromString<int>("-002147483649");
    }
    catch (OverFlow &exc) {
        exc.what();
    }
    try {
        fromString<int>("-0021f48364");
    }
    catch (WrongChar &exc) {
        exc.what();
    }

    std::cout << fromString<float>("00003333") << '\n';
    std::cout << fromString<float>("000001.2343") << '\n';
    try {
        std::cout << "--->" << fromString<float>("000001.2343.4") << '\n';
    }
    catch (WrongChar &exc) {
        exc.what();
    }
    try {
        std::cout << fromString<float>("000001.2343d4") << '\n';
    }
    catch (WrongChar &exc) {
        exc.what();
    }
    try {
        std::cout << fromString<float>("00d0001.23434") << '\n';
    }
    catch (WrongChar &exc) {
        exc.what();
    }

    fromString<bool>("FalSe");
    try {
        fromString<bool>("FalSse");
    }
    catch (WrongChar &exc) {
        exc.what();
    }


    return 0;
}