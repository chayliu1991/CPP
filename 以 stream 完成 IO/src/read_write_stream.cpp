#include <iostream>
#include <fstream>

int main()
{
    std::filebuf buffer;
    std::ostream output(&buffer);
    std::istream input(&buffer);

    buffer.open("example.dat", std::ios::in | std::ios::out | std::ios::trunc);
    for (int i = 1; i <= 4; ++i)
    {
        output << i << " .line" << std::endl;
        input.seekg(0);
        char c;
        while (input.get(c))
        {
            std::cout.put(c);
        }
        std::cout << std::endl;
        input.clear(); //@ clear eofbit and failbit
    }

    return 0;
}