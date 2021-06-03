#include <string>
#include <iostream>

int main(int argc, char *argv[])
{
    const std::string delims(" \t,.;");
    std::string line;

    while (std::getline(std::cin, line))
    {
        std::string::size_type begIdx, endIdx;
        begIdx = line.find_first_not_of(delims);
        while (begIdx != std::string::npos)
        {
            endIdx = line.find_first_of(delims, begIdx);
            if (endIdx == std::string::npos)
            {
                endIdx = line.length();
            }

            for (int i = endIdx - 1; i >= static_cast<int>(begIdx); --i)
            {
                std::cout << line[i];
            }
            std::cout << ' ';

            begIdx = line.find_first_not_of(delims, endIdx);
        }
        std::cout << std::endl;
    }

    return 0;
}
