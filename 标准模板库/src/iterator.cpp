#include <iterator>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <string>
#include <iostream>

int main()
{
    {
        std::list<int> coll1{1, 2, 3, 4, 5, 6, 7, 8, 9};
        std::vector<int> coll2;
        std::copy(coll1.cbegin(), coll1.cend(), std::back_inserter(coll2));
        for (const auto elem : coll2)
            std::cout << elem << " ";
        std::cout << std::endl;

        std::deque<int> coll3;
        std::copy(coll1.cbegin(), coll1.cend(), std::front_inserter(coll3));

        for (const auto elem : coll3)
            std::cout << elem << " ";
        std::cout << std::endl;

        std::set<int> coll4;
        std::copy(coll1.cbegin(), coll1.cend(), std::inserter(coll4, coll4.begin()));
        for (const auto elem : coll4)
            std::cout << elem << " ";
        std::cout << std::endl;
    }

    {
        std::cout << "-----------------------------------------------------------\n";
        std::vector<int> coll{1, 2, 3, 4, 5, 6, 7, 8, 9};
        std::copy(coll.crbegin(), coll.crend(), std::ostream_iterator<int>(std::cout, ","));
        std::cout << std::endl;
    }

    {
        std::cout << "请执行输入:\n";
        std::vector<std::string> coll;
        std::copy(std::istream_iterator<std::string>(std::cin), std::istream_iterator<std::string>(), std::back_inserter(coll));
        std::sort(coll.begin(), coll.end());
        std::unique_copy(coll.cbegin(), coll.cend(), std::ostream_iterator<std::string>(std::cout, "\n"));
    }

    return 0;
}