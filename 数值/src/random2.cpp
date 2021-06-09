#include <random>
#include <iostream>
#include <sstream>


void printNumbers(std::default_random_engine& e)
{
	for (int i = 0; i < 6; ++i)
		std::cout << e() << " ";
	std::cout << std::endl;
}

int main()
{
	std::default_random_engine e;
	printNumbers(e);

	std::default_random_engine e2;
	printNumbers(e2);

	std::default_random_engine e3(42);
	printNumbers(e3);

	std::stringstream engineState;
	engineState << e;

	printNumbers(e);

	engineState >> e;

	engineState.clear();
	engineState.seekg(0);


	engineState >> e;
	e.discard(2);

	printNumbers(e);
	return 0;
}