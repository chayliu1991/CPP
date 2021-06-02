#pragma once

#include <array>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <string>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <functional>
#include <iostream>

template <typename T>
inline void INSERT_ELEMENTS(T &coll, int first, int last)
{
	for (int i = first; i != last; ++i)
	{
		coll.insert(coll.end(), i);
	}
}

template <typename C>
void PRINT_ELEMENTS(const C &c, const std::string &prefix = "")
{
	std::cout << prefix;
	for (auto const &elem : c)
		std::cout << elem << " ";
	std::cout << std::endl;
}

template <typename C>
void PRINT_MAPPED_ELEMENTS(const C &c, const std::string &prefix = "")
{
	std::cout << prefix;
	for (auto const &elem : c)
		std::cout << "[" << elem.first << "," << elem.second << "]";
	std::cout << std::endl;
}