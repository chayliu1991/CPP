#include <regex>
#include <iostream>
#include <iomanip>
#include <string>

int main(int argc, char *argv[])
{
	{
		std::smatch m;
		std::string data = "XML tag:<tag-name>the value</tag-name>";
		std::cout << "data:						" << data << "\n\n";
		bool found = std::regex_search(data, m, std::regex("<(.*)>(.*)</(\\1)>"));

		std::cout << "m.empty():			" << std::boolalpha << m.empty() << std::endl;
		std::cout << "m.size():			" << m.size() << std::endl;
		if (found)
		{
			std::cout << "m.str():		" << m.str() << std::endl;
			std::cout << "m.length():		" << m.length() << std::endl;
			std::cout << "m.position():		" << m.position() << std::endl;
			std::cout << "m.prefix().str():		" << m.prefix().str() << std::endl;
			std::cout << "m.suffix().str():		" << m.suffix().str() << std::endl;
			std::cout << std::endl;
		}

		for (int i = 0; i < m.size(); ++i)
		{
			std::cout << "m[" << i << "].str():			" << m[i].str() << std::endl;
			std::cout << "m.str(" << i << "):			" << m.str(i) << std::endl;
			std::cout << "m.position(" << i << "):			" << m.position(i) << std::endl;
		}
		std::cout << std::endl;

		std::cout << "matches: " << std::endl;
		for (auto pos = m.begin(); pos != m.end(); ++pos)
		{
			std::cout << " " << *pos << " ";
			std::cout << "(length: " << pos->length() << " )" << std::endl;
		}
	}

	{
		std::string data = "<person>\n"
						   "<first>Nico</first>\n"
						   "<last>Josuttis</last>\n"
						   "</person>\n";
		std::regex reg("<(.*)>(.*)</(\\1)>");
		auto pos = data.cbegin();
		auto end = data.cend();
