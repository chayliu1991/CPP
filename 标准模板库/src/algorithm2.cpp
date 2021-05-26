#include <iterator>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <string>
#include <iostream>
#include <functional>

template <typename C>
void PRINT_ELEMENTS(const C &c, const std::string &prefix)
{
	std::cout << prefix;
	for (auto const &elem : c)
		std::cout << elem << " ";
	std::cout << std::endl;
}

void print(int num)
{
	std::cout << num << ' ';
}

int square(int x)
{
	return x * x;
}

bool is_prime(int num)
{
	num = std::abs(num);
	if (num == 0 || num == 1)
		return false;

	int divisor;
	for (divisor = num / 2; num % divisor != 0; --divisor)
		;
	return divisor == 1;
}

struct Person
{
	std::string first_name;
	std::string last_name;
};

bool person_sort_criterion(const Person &p1, const Person &p2)
{
	return (p1.last_name < p2.last_name) || ((p1.last_name == p2.last_name) && (p1.first_name < p2.first_name));
}

class Pred
{
private:
	int x;
	int y;

public:
	Pred(int xx, int yy) : x(xx), y(yy)
	{
	}

	bool operator()(int i) const
	{
		return i > x && i < y;
	}
};

class AddValue
{
private:
	int the_value;

public:
	AddValue(int v) : the_value(v) {}
	void operator()(int &elem) const
	{
		elem += the_value;
	}
};

int main()
{
	{
		std::list<int> coll;
		for (int i = 1; i <= 6; ++i)
		{
			coll.push_front(i);
			coll.push_back(i);
		}

		std::copy(coll.cbegin(), coll.cend(), std::ostream_iterator<int>(std::cout, " "));
		std::cout << std::endl;

		std::list<int>::iterator end = std::remove(coll.begin(), coll.end(), 3);
		std::copy(coll.begin(), end, std::ostream_iterator<int>(std::cout, " "));
		std::cout << std::endl;

		std::cout << "remove " << std::distance(end, coll.end()) << " elements";
		std::cout << std::endl;

		std::copy(coll.cbegin(), coll.cend(), std::ostream_iterator<int>(std::cout, " "));
		std::cout << std::endl;

		coll.erase(end, coll.end());
		std::copy(coll.cbegin(), coll.cend(), std::ostream_iterator<int>(std::cout, " "));
		std::cout << std::endl;
	}

	{
		std::set<int> coll{1, 2, 3, 4, 5, 6, 7, 8, 9};
		std::copy(coll.cbegin(), coll.cend(), std::ostream_iterator<int>(std::cout, " "));
		std::cout << std::endl;
		int num = coll.erase(3);
		std::cout << "number of erased : " << num << std::endl;
		std::copy(coll.cbegin(), coll.cend(), std::ostream_iterator<int>(std::cout, " "));
		std::cout << std::endl;
	}

	{
		std::set<int> coll{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
		PRINT_ELEMENTS(coll, "original:");

		std::vector<int> coll2;
		std::transform(coll.begin(), coll.end(), std::back_inserter(coll2), square);
		PRINT_ELEMENTS(coll2, "squared:");
	}

	{
		std::list<int> coll{24, 25, 26, 27, 28, 29, 30};
		auto pos = std::find_if(coll.cbegin(), coll.cend(), is_prime);
		if (pos != coll.end())
		{
			std::cout << *pos << " is first prime number found" << std::endl;
		}
		else
		{
			std::cout << "no prime number found" << std::endl;
		}

		std::deque<Person> dp;
		std::sort(dp.begin(), dp.end(), person_sort_criterion);
	}

	{
		std::vector<int> coll{1, 3, 5, 7, 9};
		std::transform(coll.begin(), coll.end(), coll.begin(), [](int x)
					   { return x * x * x; });
		PRINT_ELEMENTS(coll, "x*x*x:");

		std::deque<int> coll2{1, 3, 19, 5, 13, 7, 11, 2, 17};
		int x = 5, y = 12;
		auto pos = std::find_if(coll2.begin(), coll2.end(), [=](int i)
								{ return i > x && i < y; });
		std::cout << "first element > 5 and < 12: " << *pos << std::endl;

		//@ 使用函数对象比较丑陋
		auto pos1 = std::find_if(coll2.begin(), coll2.end(), Pred(x, y));
		std::cout << "first element > 5 and < 12: " << *pos1 << std::endl;

		//@ bind 使用也很麻烦
		auto pos2 = std::find_if(coll2.begin(), coll2.end(), std::bind(std::logical_and<bool>(), std::bind(std::greater<int>(), std::placeholders::_1, x), std::bind(std::less<int>(), std::placeholders::_1, y)));
		std::cout << "first element > 5 and < 12: " << *pos2 << std::endl;

		std::list<int> coll3{1, 2, 3, 4, 5, 6, 7, 8, 9};
		PRINT_ELEMENTS(coll3, "original:");
		std::for_each(coll3.begin(), coll3.end(), AddValue(10));
		PRINT_ELEMENTS(coll3, "add 10:");

		AddValue add_one(1);
		std::for_each(coll3.begin(), coll3.end(), add_one);
		PRINT_ELEMENTS(coll3, "add 1:");
	}

	{
		std::deque<int> coll{1, 2, 3, 5, 7, 11, 13, 17, 19};
		PRINT_ELEMENTS(coll, "original:");
		std::transform(coll.begin(), coll.end(), coll.begin(), std::negate<int>());
		PRINT_ELEMENTS(coll, "negated:");
		std::transform(coll.cbegin(), coll.cend(), coll.cbegin(), coll.begin(), std::multiplies<int>());
		PRINT_ELEMENTS(coll, "squared:");
	}

	{
		std::set<int, std::greater<int>> coll{1, 2, 3, 4, 5, 6, 7, 8, 9};
		PRINT_ELEMENTS(coll, "coll original:");
		std::deque<int> coll2;
		std::transform(coll.cbegin(), coll.cend(), std::back_inserter(coll2), std::bind(std::multiplies<int>(), std::placeholders::_1, 10));
		PRINT_ELEMENTS(coll2, "multiply 10:");
	}

	return 0;
}