#include <iostream>
#include "TInt.h"
int main() {
    TInt x(2147483647),y(2147483647);
    int heh=8;
    try {
        x+=heh;
    }
    catch (OverFlow &e)
    {
        std::cout<<e.what();
    }

    x=y;
    std::cout<<"X=Y="<<x<<'\n';
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
    int five=5;
    b=b/five;
    std::cout<<"b="<<b<<'\n';
    try {
        if(b>=21836499){
            std::cout<<1;
        } else std::cout<<0;
    }
    catch (OverFlow &e){
        std::cout<<e.what();
    }
    //TInt a = 123;
    //int vcr = a;
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
    TInt f(2147483646), g(2);


    std::cout<<"q"<<'\n';


    std::cout<<"x="<<x<<" b="<<b<<'\n';
    if(b<=x){
        std::cout<<1<<'\n';
    } else std::cout<<0<<'\n';

    TInt d(0),j(1) ;
    int i(5);
    j+=i;
    d=-2147483648;
    try {
        d-= j;
    }
    catch (OverFlow &e){
        std::cout<<"!"<<e.what();
    }
    return 0;
}
