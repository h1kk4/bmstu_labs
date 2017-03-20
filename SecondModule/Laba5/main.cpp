
#include "TNotCopyable.h"
#include <iostream>

int main()
{
    try
    {
        TNotCopyable obj;
        RAII x=&obj;
        obj.OpenToWrite("/Users/alex/ClionProjects/Module2Laba5/File1");

        obj.OpenToRead("/Users/alex/ClionProjects/Module2Laba5/File2");

        obj.Close();
    }
    catch (const std::exception & e)
    {
        std::cout << e.what();

    }
}