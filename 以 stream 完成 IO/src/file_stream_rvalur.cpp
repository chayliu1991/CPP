#include <iostream>
#include <string>
#include <fstream>

int main()
{
	std::string s("hello");
	std::ofstream("fstream2.tmp") << s;

	std::ofstream("fstream2.tmp", std::ios::app) << ",world" << std::endl;
	return 0;
}

