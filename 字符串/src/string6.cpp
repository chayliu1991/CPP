#include <string>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <regex>
#include <locale>
#include "icstring.hpp"

int main(int argc, char *argv[])
{
    {
        icstring s1("hallo");
        icstring s2("otto");
        icstring s3("hALLo");

        std::cout << std::boolalpha;
        std::cout << s1 << "== " << s2 << " : " << (s1 == s2) << std::endl;
        std::cout << s1 << "== " << s3 << " : " << (s1 == s3) << std::endl;

        icstring::size_type idx = s1.find("All");
        if (idx != icstring::npos)
        {
            std::cout << "idx: " << idx << std::endl;
        }
        else
        {
            std::cout << "not fonud" << std::endl;
        }
    }

    return 0;
}
