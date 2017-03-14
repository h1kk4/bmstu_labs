#include <iostream>
#include "TInt.h"
int main() {
    TInt x(9),y(2);
    try {
        x*=2147483648;
    }
    catch (OverFlow &e)
    {
        std::cout<<e.what();
    }
    try {
        x=2147483648+y;
    }
    catch(OverFlow &e)
    {
        std::cout<<e.what();

    }
    try {
        x=2147483645+2;
    }
    catch(OverFlow &e)
    {
        std::cout<<e.what();

    }
    std::cout<<x<<'\n';
    TInt b;
    b=2147483647;
    std::cout<<"b="<<b<<'\n';
    try {
        if(b>=21474836499){
            std::cout<<1;
        } else std::cout<<0;
    }
    catch (OverFlow &e){
        std::cout<<e.what();
    }

    if(x>=y){
        std::cout<<"X="<<x<<'\n';
    } else std::cout<<"Y="<<y<<'\n';

    std::cout<<x%y<<'\n';
    std::cout<<(x/=99999)<<'\n';
    try {
        b=x-y;
        std::cout<<"b="<<b<<'\n';
    }
    catch(OverFlow &e)
    {
        std::cout<<e.what();
    }
    x/=2;
    std::cout<<x<<'\n';
    TInt d;
    d=-2147483648;
    try {
        d-=1;
    }
    catch (OverFlow &e){
        std::cout<<e.what();
    }
    return 0;
}
