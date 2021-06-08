#include <iostream>
#include <iterator>

int countLines(std::istream &in)
{
	return std::count(std::istreambuf_iterator<char>(in), std::istreambuf_iterator<char>(), '\n');
}

int main()
{
	std::istreambuf_iterator<char> inpos(std::cin);

	std::istreambuf_iterator<char> endpos;

	std::ostreambuf_iterator<char> outpos(std::cout);

	while (inpos != endpos)
	{
		*outpos = *inpos;
		++inpos;
		++outpos;
	}

	return 0;
}