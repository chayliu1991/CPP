// HelloWorld.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
#include <locale>
#include <exception>
#include <cstdlib>
#include <string>


int main()
{
	try
	{
		std::locale langLocale("");
		std::cout.imbue(langLocale);
		std::cout << langLocale.name() << std::endl;
		bool isGerman = (langLocale.name().substr(0, 2) == "de" || langLocale.name().substr(0, 3) == "ger" || langLocale.name().substr(0, 3) == "Ger");

		std::cout << (isGerman ? "Sprachumgebung fuer Eingaben:" : "Locale for input: ") << std::endl;
		std::string s;
		std::cin >> s;
		if (!std::cin)
		{
			if (isGerman)
			{
				std::cerr << "FEHLER beim Einlesen der Sprachumgebung" << std::endl;
			}
			else
			{
				std::cerr << "Error while reading the locale" << std::endl;
			}
		}

		std::locale cinLocale(s);
		std::cin.imbue(cinLocale);
		std::cout << (isGerman ? "Gleitkommawerte:" : "Floating-point values: ") << std::endl;
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