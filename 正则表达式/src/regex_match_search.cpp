#include <regex>
#include <iostream>
#include <iomanip>
#include <string>


void out(bool b)
{
	std::cout << (b ? "found" : "not found") << std::endl;
}


int main(int argc, char* argv[])
{
	std::regex reg1("<.*>.*</.*>");
	bool found = std::regex_match("<tag>value</tag>", reg1);
	out(found);

	//@ (...) 指定 capture group，后面的 \1也是指代它
	//@ 也可以使用 raw string: R"(<(.*).*(/\1)>)"
	std::regex reg2("<(.*)>.*</\\1>");
	found = std::regex_match("<tag>value</tag>", reg2);
	out(found);

	std::regex reg3("<\\(.*\\)>.*</\\1>", std::regex_constants::grep);
	found = std::regex_match("<tag>value</tag>", reg3);
	out(found);

	found = std::regex_match("<tag>value</tag>", std::regex("<(.*)>.*</\\1>"));
	out(found);


	//@ regex_match VS. regex_search
	found = std::regex_match("XML tag: <tag>value</tag>", std::regex("<(.*)>.*</\\1>"));
	out(found);

	found = std::regex_match("XML tag: <tag>value</tag>", std::regex(".*<(.*)>.*</\\1>.*"));
	out(found);


	found = std::regex_search("XML tag: <tag>value</tag>", std::regex("<(.*)>.*</\\1>"));
	out(found);

	found = std::regex_search("XML tag: <tag>value</tag>", std::regex(".*<(.*)>.*</\\1>.*"));

	out(found);
	return 0;
}