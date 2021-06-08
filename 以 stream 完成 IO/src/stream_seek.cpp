#include <iostream>
#include <fstream>

void printFileTwice(const char* filename)
{
	std::ifstream file(filename);
	std::cout << file.rdbuf();
	file.seekg(0);
	std::cout << file.rdbuf();
}

int main(int argc,char* argv[])
{	
	for (int i = 1; i < argc; ++i)
	{
		printFileTwice(argv[i]);
	}
	return 0;
}