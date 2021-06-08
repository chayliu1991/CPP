#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstdlib>

void writeCharsetToFile(const std::string &filename);
void outputFile(const std::string &filename);

int main(int argc, char *argv[])
{
    writeCharsetToFile("charset.out");
    outputFile("charset.out");

    return 0;
}

void writeCharsetToFile(const std::string &filename)
{
    std::ofstream file(filename);
    if (!file)
    {
        std::cerr << "can not open output file " << filename << std::endl;
        exit(EXIT_FAILURE);
    }

    for (int i = 32; i < 256; ++i)
    {
        file << "value: " << std::setw(3) << i << " "
             << "char: " << static_cast<char>(i) << std::endl;
    }
}

void outputFile(const std::string &filename)
{
    std::ifstream file(filename);
    if (!file)
    {
        std::cerr << "can not open output file " << filename << std::endl;
        exit(EXIT_FAILURE);
    }
    char c;
    while (file.get(c))
    {
        std::cout.put(c);
    }
}
