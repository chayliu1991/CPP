#include <iostream>
#include "inbuf1.hpp"

int main()
{
    inbuf ib;
    std::istream in(&ib);

    char c;
    for (int i = 1; i <= 20; i++)
    {
        in.get(c);
        std::cout << c << std::flush;
        if (i == 8)
        {
            in.unget();
            in.unget();
        }
    }

    std::cout << std::endl;
    return 0;
}