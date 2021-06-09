#include <iostream>
#include <locale>
#include <exception>
#include <cstdlib>
#include <string>


int main()
{

		try
		{
			std::cin.imbue(std::locale::classic());
#ifdef  _MSC_VER
			std::cout.imbue(std::locale("deu_deu.1252"));
#else
			std::cout.imbue(std::locale("deu_DE"));
#endif //  _MSC_VER

			std::cout << "input floating-point values(classic notation): " << std::endl;
			double value;
			while (std::cin >> value)
			{
				std::cout << value << std::endl;
			}
		}
		catch (const std::exception& e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
			return EXIT_FAILURE;
		}

    return 0;
}