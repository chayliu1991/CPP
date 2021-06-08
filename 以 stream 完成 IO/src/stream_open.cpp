#include <iostream>
#include <string>
#include <fstream>

int main(int argc,char* argv[])
{	
	std::ifstream file;
	for (int i = 1; i < argc; ++i)
	{
		file.open(argv[i]);
		char c;
		while (file.get(c))
		{
			std::cout.put(c);
		}
		//@ clear eofbit and filbit 
		file.clear();
		file.close();
	}
	
	return 0;
}