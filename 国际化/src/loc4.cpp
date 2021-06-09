#include <iostream>
#include <locale>
#include <exception>
#include <cstdlib>
#include <string>
#include <chrono>

std::ostream& operator<<(std::ostream& strm, std::moneypunct<char>::pattern p)
{
	for (int i = 0; i < 4; ++i)
	{
		auto f = p.field[i];
		strm << ( f ==  std::money_base::none ? "none" : f == std::money_base::space ? "space":
			f == std::money_base::symbol ? "symbol" : f == std::money_base::sign ? "sign" :
			f == std::money_base::value ? "value" : "???") << " ";
	}
	return strm;
}


template <bool intl>
void printMoneyPunct(const std::string& localeName)
{
	std::locale loc(localeName);
	const std::moneypunct<char, intl>& mp = std::use_facet < std::moneypunct<char, intl >>(loc);
	std::cout << "moneypunct in locale " << loc.name() << std::endl;
	std::cout << "decimal_point " << (mp.decimal_point() != '\0' ? mp.decimal_point() : ' ') << std::endl;
	std::cout << "thousands_sep" << (mp.thousands_sep() != '\0' ? mp.thousands_sep() : ' ') << std::endl;
	std::cout << " grouping: ";

	for (int i = 0; i < mp.grouping().size(); ++i)
	{
		std::cout << static_cast<int>(mp.grouping()[i]) << " ";
	}
	std::cout << std::endl;
	std::cout << "curr_symbol: " << mp.curr_symbol() << std::endl;
	std::cout << "positive_sign: " << mp.positive_sign() << std::endl;
	std::cout << "negative_sign: " << mp.negative_sign() << std::endl;
	std::cout << "frac_digits: " << mp.frac_digits() << std::endl;
	//std::cout << "pos_format: " << mp.pos_format() << std::endl;
	//std::cout << "neg_fromat: " << mp.neg_fromat() << std::endl;
}


int main()
{
	try
	{
		printMoneyPunct<false>("C");
		std::cout << std::endl;
		printMoneyPunct<false>("german");
		std::cout << std::endl;
		printMoneyPunct<true>("german");
		std::cout << std::endl;

	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	return 0;
}