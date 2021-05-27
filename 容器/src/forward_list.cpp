#include <iostream>
#include <forward_list>
#include <string>
#include <algorithm>
#include <iterator>

template <typename C>
void PRINT_ELEMENTS(const C &c, const std::string &prefix)
{
	std::cout << prefix;
	for (auto const &elem : c)
		std::cout << elem << " ";
	std::cout << std::endl;
}


int main()
{
	std::forward_list<int> coll1{ 1,4,2,5,4,7,8,3 };
	PRINT_ELEMENTS(coll1, "original coll1:");
	std::cout << "coll1 size:" << std::distance(coll1.begin(), coll1.end())<<std::endl;

	coll1.push_front(100);
	PRINT_ELEMENTS(coll1, "after push_front coll1:");

	coll1.insert_after(coll1.begin(), 90);
	coll1.insert_after(coll1.begin(), 5, 101);
	PRINT_ELEMENTS(coll1, "after insert_after coll1:");

	coll1.remove(100);
	PRINT_ELEMENTS(coll1, "after remove coll1:");

	coll1.remove_if([](int x) {return x >= 100; });
	PRINT_ELEMENTS(coll1, "after remove_if coll1:");

	std::forward_list<int> coll2{ 9,1,2,2,3,4,5,6,7,8,3,2,1 };

	auto pos = coll1.begin();
	for (; pos != coll1.end(); ++pos)
	{
		if (*pos == 5)
			break;
	}
	coll1.splice_after(pos, coll2);
	PRINT_ELEMENTS(coll1, "after splice_after coll1:");

	coll1.unique();
	PRINT_ELEMENTS(coll1, "after unique coll1:");

	coll1.sort();
	PRINT_ELEMENTS(coll1, "after sort coll1:");

	return 0;
}