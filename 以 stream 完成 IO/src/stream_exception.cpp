#include <iostream>
#include <iomanip>
#include <chrono>
#include <cstdlib>


namespace Mylib
{
	double readAndProcessSum(std::istream& strm)
	{
		using std::ios;
		double value, sum;
		ios::iostate oldExceptions = strm.exceptions();
		strm.exceptions(ios::failbit | ios::badbit);

		try
		{
			sum = 0.0;
			while (strm >> value)
				sum += value;
		}
		catch (...)
		{
			//@ end of file 会设置 failbit
			if (!strm.eof())
			{
				strm.exceptions(oldExceptions);
				throw std::ios::failure("input error in readAndProcessSum()");
			}
		}

		strm.exceptions(oldExceptions);
		return sum;
	}
}



int main(int argc, char *argv[])
{
	double sum;
	try
	{
		sum = Mylib::readAndProcessSum(std::cin);
	}
	catch (const std::ios::failure& error)
	{
		std::cerr << "I/O exception: " << error.what() << std::endl;
		return EXIT_FAILURE;
	}
	catch (const std::exception& error)
	{
		std::cerr << "I/O exception: " << error.what() << std::endl;
		return EXIT_FAILURE;
	}
	catch (...)
	{
		std::cerr << "Unexcepted failure" << std::endl;
		return EXIT_FAILURE;
	}

	std::cout << sum << std::endl;

	return 0;
}