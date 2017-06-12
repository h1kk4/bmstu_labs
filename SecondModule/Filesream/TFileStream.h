//
// Created by Алексей Долматов on 12.06.17.
//

#ifndef FILESTREAM_TFILESTREAM_H
#define FILESTREAM_TFILESTREAM_H


#include <string>
#include <iostream>
#include <sstream>
#include <stdio.h>
class FileStream
{
    FILE *file;
    bool opened;
    bool eofFlag;
public:

    FileStream():file(nullptr),eofFlag(nullptr)
    {}

    ~ FileStream()
    {
        if (!is_open())
            fclose(file);
        opened = 0;
    };

    FileStream(const std::string& str, const std::string& type)
    {
        file = fopen(str.c_str(), type.c_str());
        if (file != NULL)
            opened = true;
        eofFlag=nullptr;
    };

    void open(const char * str, const char *  type)
    {
        if (opened) close();
        file = fopen(str, type);
        if (file != NULL)
            opened = true;
    }

    bool is_open()
    {
        return opened;
    }

    void close()
    {
        if (opened) fclose(file);
        opened = 0;
        file= nullptr;
    }

    FileStream& operator<<(const std::string& str)
    {
        if (!opened)
            throw std::exception();
        fprintf(file, str.c_str());
        return *this;
    }


    FileStream& operator<<(std::ostream&(*endl)(std::ostream&))
    {
        if (!opened)
            throw std::exception();
        std::ostringstream ss;
        ss << endl;
        fprintf(file, ss.str().c_str());
        return *this;
    }

    FileStream& operator >> (char *& str)
    {

        if (!opened)
            throw std::exception();
        fscanf(file, "%s", str);
        return *this;
    }

    FileStream& operator >> (std::string& str)
    {

        char * tmp = new char[1024];
        if (!opened)
            throw std::exception();
        fscanf(file, "%s", tmp);
        str = tmp;
        return *this;
    }

    FileStream& getline(char *s, const int n, const char delim)
    {
        if(n <= 0) return *this;
        for(size_t i = 0; i < n; ++i)
        {
            int ch = fgetc(file);
            if(ch == EOF || ch == delim)
            {
                if(ch == EOF) eofFlag = true;
                s[i] = '\0';
                break;
            }
            s[i] = ch;
        }
        s[n] = '\0';
        return *this;
    }

    FileStream& getline (char* s, const int n )
    {
        return getline(s, n, '\n');

    }

    FileStream& read(char *s, const int n)
    {
        if(n <= 0) return *this;
        char *str = new char[n + 1];
        for(size_t i = 0; i < n; ++i)
        {
            int ch = fgetc(file);
            if(ch == EOF)
            {
                eofFlag = true;
                break;
            }
            str[i] = ch;
        }
        s = str;
        return *this;
    }
    FileStream& write(const char *s, const int n)
    {
        fwrite(s, sizeof(char), n, file);
        return *this;
    }
    void seek(int pos)
    {
        if (opened)
            fseek(file, pos, SEEK_SET);
    }


    bool eof() const
    {
        return eofFlag;
    }

};


#endif //FILESTREAM_TFILESTREAM_H

