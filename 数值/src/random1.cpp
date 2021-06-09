#include <random>
#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
	std::default_random_engine e;
	std::uniform_int_distribution<int> dis(1, 9);
	for (int i = 0; i < 10; ++i)
	{
		std::cout << dis(e) << std::endl;
	}

	std::uniform_real_distribution<double> disf(10, 20);
	for (int i = 0; i < 6; ++i)
	{
		std::cout << disf(e) << std::endl;
	}

	std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::shuffle(v.begin(), v.end(), e);
	for (int i = 0; i < v.size(); ++i)
	{
		std::cout << v[i] << std::endl;
	}

	return 0;
}