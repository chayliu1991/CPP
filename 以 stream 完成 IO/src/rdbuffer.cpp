#include <iostream>
#include <fstream>

void hexMultiplicationTable(std::streambuf *buffer, int num)
{
    std::ostream hexout(buffer);
    hexout << std::hex << std::showbase;

    for (int i = 1; i <= num; ++i)
    {
        for (int j = 1; j <= 10; ++j)
        {
            hexout << i * j << ' ';
        }
        hexout << std::endl;
    }
}

int main(int argc, char *argv[])
{
    {
        std::ostream hexout(std::cout.rdbuf());
        hexout.setf(std::ios::hex, std::ios::basefield);
        hexout.setf(std::ios::showbase);

        hexout << "hexout: " << 177 << " ";
        std::cout << "cout: " << 177 << " ";
        hexout << "hexout: " << -49 << " ";
        std::cout << "cout: " << -49 << " ";
        hexout << std::endl;
    }

    {
        int num = 5;
        std::cout << "We print " << num << " lines hexadecimal " << std::endl;
        hexMultiplicationTable(std::cout.rdbuf(), num);
        std::cout << "That was the output of " << num << " hexadecimal lines" << std::endl;
    }
    return 0;
}