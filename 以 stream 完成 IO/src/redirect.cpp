#include <iostream>
#include <fstream>
#include <memory>

void redirect(std::ostream&);


int main(int argc,char* argv[])
{	
	std::cout << "the first row" << std::endl;
	redirect(std::cout);
	std::cout << "the last row" << std::endl;

	return 0;
}


void redirect(std::ostream& strm)
{
	auto del = [&](std::streambuf* p)
	{
		strm.rdbuf(p);
	};

	std::unique_ptr<std::streambuf, decltype(del)> origBuffer(strm.rdbuf(),del);
	std::ofstream file("redirect.txt");
	strm.rdbuf(file.rdbuf());

	file << "one row for the file" << std::endl;
	strm << "one row for the stream" << std::endl;
}