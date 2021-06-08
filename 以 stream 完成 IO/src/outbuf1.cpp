#include <iostream>
#include "outbuf1.hpp"

int main()
{
    outbuf ob;
    std::ostream out(&ob);

    out << "31 hexadecimal: " << std::hex << 31 << std::endl;
    return 0;
}