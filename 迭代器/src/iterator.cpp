#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>


template <typename C>
void PRINT_ELEMENTS(const C& c, const std::string& prefix)
{
	std::cout << prefix;
	for (auto const& elem : c)
		std::cout << elem << " ";
	std::cout << std::endl;
}

int main()
{
	{
		std::vector<int> coll;
		for (int i = -3; i <= 9; ++i)
			coll.push_back(i);

		std::cout << "number/distance: " << coll.end() - coll.begin() << std::endl;

		for (int i = 0; i < coll.size(); ++i)
		{
			std::cout << coll.begin()[i] << " ";
		}
		std::cout << std::endl;

		auto pos = coll.begin();
		for (pos = coll.begin(); pos < coll.end() - 1; pos += 2)
		{
			std::cout << *pos << " ";
		}
		std::cout << std::endl;
	}

	{
		std::vector<int> coll{ 9,1,12,3,4,5,1,2,10 };
		PRINT_ELEMENTS(coll, "coll: ");
		if (coll.size() > 1)
		{
			std::sort(std::next(coll.begin()), coll.end());
		}
		PRINT_ELEMENTS(coll, "after sort coll: ");
	}

	{
		std::list<int> coll{ 1,2,3,4,5,6,7,8,9 };
		std::list<int>::iterator pos = coll.begin();
		std::cout << *pos << std::endl;
		std::advance(pos, 3);
		std::cout << *pos << std::endl;
		std::advance(pos, -1);
		std::cout << *pos << std::endl;
	}

	{
		std::list<int> coll{ -3,-2,-1,0,1,2,3,4,5,6,7,8,9 };
		std::list<int>::iterator pos;
		pos = std::find(coll.begin(), coll.end(), 6);
		if (pos != coll.end())
		{
			std::cout << "difference between beginning and 6: " << std::distance(coll.begin(), pos) << std::endl;
		}
		else
		{
			std::cout << "6 not found" << std::endl;
		}
	}

	{
		std::list<int> coll{ 0,1,2,3,4,5,6,7,8,9 };
		PRINT_ELEMENTS(coll,"coll is: ");
		std::iter_swap(coll.begin(),std::next(coll.begin()));
		PRINT_ELEMENTS(coll, "coll is: ");
		std::iter_swap(coll.begin(),std::prev(coll.end()));
		PRINT_ELEMENTS(coll, "coll is: ");
	}
	return 0;
}