#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iterator>
#include <list>
#include <deque>
#include<iterator>
#include <set>


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
		std::back_insert_iterator<std::vector<int>> iter(coll);
		*iter = 1;
		iter++;
		*iter = 2;
		iter++;
		*iter = 3;
		PRINT_ELEMENTS(coll, "vector is: ");
	}

	{
		std::list<int> coll;
		std::front_insert_iterator<std::list<int>> iter(coll);
		*iter = 1;
		iter++;
		*iter = 2;
		iter++;
		*iter = 3;
		PRINT_ELEMENTS(coll, "list is: ");

		std::front_inserter(coll) = 44;
		std::front_inserter(coll) = 55;
		PRINT_ELEMENTS(coll, "list is: ");

		std::copy(coll.begin(),coll.end(),std::front_inserter(coll));
		PRINT_ELEMENTS(coll, "list is: ");
	}

	{
		std::set<int> coll;
		std::insert_iterator<std::set<int>> iter(coll,coll.begin());
		*iter = 1;
		iter++;
		*iter = 2;
		iter++;
		*iter = 3;
		PRINT_ELEMENTS(coll, "set is: ");

		std::inserter(coll, coll.end()) = 44;
		std::inserter(coll, coll.end()) = 55;
		PRINT_ELEMENTS(coll, "set is: ");

		std::list<int> coll2;
		std::copy(coll.begin(),coll.end(),std::inserter(coll2, coll2.begin()));
		PRINT_ELEMENTS(coll2, "list is: ");

		std::copy(coll.begin(), coll.end(), std::inserter(coll2, ++coll2.begin()));
		PRINT_ELEMENTS(coll2, "list is: ");
	}

	return 0;
}