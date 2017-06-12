#include <iostream>
#include <string>
#include "TFileStream.h"

int main()

{
   FileStream file1;
    file1.open("/Users/alex/ClionProjects/FileStream/test.txt","r");
    std::string s;

    file1 >> s;


    std::cout<<s;
    file1.close();
    return 0;
}