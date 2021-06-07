#include <regex>
#include <iostream>
#include "regexexception.hpp"

int main(int argc, char *argv[])
{
    try
    {
        //@ 使用 grep 文法，但是对 { }进行了转义
        std::regex pat("\\\\.*index\\{([^{]*)\\}", std::regex_constants::grep | std::regex_constants::icase);
    }
    catch (const std::regex_error &e)
    {
        std::cerr << "regex_error: \n"
                  << " what(): " << e.what() << "\n"
                  << " code(): " << regexCode(e.code()) << std::endl;
    }
    return 0;
}
