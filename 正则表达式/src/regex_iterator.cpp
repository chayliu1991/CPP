#include <regex>
#include <iostream>
#include <algorithm>
#include <string>


int main(int argc, char* argv[])
{
	{
		std::string data = "<person>\n"
			"<first>Nico</first>\n"
			"<last>Josuttis</last>\n"
			"</person>\n";
		std::regex reg("<(.*)>(.*)</(\\1)>");
		std::sregex_iterator pos(data.cbegin(),data.cend(),reg);
		std::sregex_iterator end;

		for (; pos != end; ++pos)
		{
			std::cout << "match:	" << pos->str() << std::endl;
			std::cout << "tag:	" << pos->str(1) << std::endl;
			std::cout << "value:	" << pos->str(2) << std::endl;
		}

		std::sregex_iterator beg(data.cbegin(), data.cend(), reg);
		std::for_each(beg, end, [](const std::smatch& m) {
			std::cout << "match:	" << m.str() << std::endl;
			std::cout << "tag:	" << m.str(1) << std::endl;
			std::cout << "value:	" << m.str(2) << std::endl;
		});
	
	}

	return 0;
}
