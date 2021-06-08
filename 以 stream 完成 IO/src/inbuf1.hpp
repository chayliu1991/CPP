#pragma once
#include <cstdio>
#include <cstring>
#include <streambuf>

#ifdef _MSC_VER
#include <io.h>
#else
#include <unistd.h>
#endif //  _MSC_VER

class inbuf : public std::streambuf
{
protected:
    static const int bufferSize = 10;
    char buffer[bufferSize];

public:
    inbuf()
    {
        setg(buffer + 4, buffer + 4, buffer + 4);
    }

protected:
    virtual int_type underflow()
    {
        if (gptr() < egptr())
        {
            return traits_type::to_int_type(*gptr());
        }

        int numPutback;
        numPutback = gptr() - eback();
        if (numPutback > 4)
            numPutback = 4;

        std::memmove(buffer + (4 - numPutback), gptr() - numPutback, numPutback);

        int num;
        num = _read(0, buffer + 4, bufferSize - 4);
        if (num <= 0)
            return EOF;

        setg(buffer + (4 - numPutback), buffer + 4, buffer + 4 + num);
        return traits_type::to_int_type(*gptr());
    }
};