#include <iostream>
#include <locale>
#include <exception>
#include <cstdlib>
#include <string>
#include <chrono>

int main()
{
    try
    {
        std::locale locC;
        std::cout.imbue(locC);
        std::use_facet<std::num_put<char>>(locC).put(std::cout, std::cout, ' ', 12345.6789);
        std::cout << std::endl;

#ifdef _MSC_VER
        std::locale locG("deu_deu.1252");
#else
        std::locale locG("de_DE");
#endif //  _MSC_VER

        std::cout.imbue(locG);
        std::use_facet<std::num_put<char>>(locG).put(std::cout, std::cout, ' ', 12345.6789);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}