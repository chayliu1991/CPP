#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iterator>
#include <list>
#include <deque>


template <typename C>
void PRINT_ELEMENTS(const C& c, const std::string& prefix)
{
	std::cout << prefix;
	for (auto const& elem : c)
		std::cout << elem << " ";
	std::cout << std::endl;
}

void print(int elem)
{
	std::cout << elem << " ";
}

int main()
{
	{
		std::list<int> coll{ 1,2,3,4,5,6,7,8,9 };

		std::for_each(coll.begin(), coll.end(), print);
		std::cout << std::endl;

		std::for_each(coll.rbegin(), coll.rend(), print);
		std::cout << std::endl;
	}

	{
		std::vector<int> coll{ 1,2,3,4,5,6,7,8,9 };

		std::vector<int>::const_iterator pos;
		pos = std::find(coll.cbegin(), coll.cend(), 5);
		std::cout << "pos: " << *pos << std::endl;

		std::vector<int>::const_reverse_iterator rpos(pos);
		std::cout << "rpos: " << *rpos << std::endl;

	}

	{
		std::deque<int> coll{ 1,2,3,4,5,6,7,8,9 };
		std::deque<int>::const_iterator pos1;
		pos1 = std::find(coll.cbegin(),coll.cend(),2);

		std::deque<int>::const_iterator pos2;
		pos2 = std::find(coll.cbegin(), coll.cend(), 7);

		std::for_each(pos1,pos2,print);
		std::cout << std::endl;

		std::deque<int>::const_reverse_iterator rpos1(pos1);
		std::deque<int>::const_reverse_iterator rpos2(pos2);
		std::for_each(rpos2, rpos1, print);
		std::cout << std::endl;
	}

	{
		std::list<int> coll{ 1,2,3,4,5,6,7,8,9 };
		std::list<int>::const_iterator pos;
		pos = std::find(coll.cbegin(),coll.cend(),5);
		std::cout << "pos: " << *pos << std::endl;

		std::list<int>::const_reverse_iterator rpos(pos);
		std::cout << "rpos: " << *rpos << std::endl;

		std::list<int>::const_iterator rrpos = rpos.base();
		std::cout << "rrpos: " << *rrpos << std::endl;
	}

	return 0;
}