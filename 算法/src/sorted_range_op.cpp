#include "algostuff.h"

int main()
{
    {
        std::list<int> coll;
        INSERT_ELEMENTS(coll, 1, 10);
        PRINT_ELEMENTS(coll, "coll: ");

        if (std::binary_search(coll.begin(), coll.end(), 6))
        {
            std::cout << "6 is found" << std::endl;
        }
        else
        {
            std::cout << "6 is not found" << std::endl;
        }
    }

    {
        std::list<int> coll;
        std::vector<int> search;
        INSERT_ELEMENTS(coll, 1, 10);
        PRINT_ELEMENTS(coll, "coll: ");
        search.push_back(3);
        search.push_back(4);
        search.push_back(7);
        PRINT_ELEMENTS(search, "search: ");

        if (std::includes(coll.cbegin(), coll.cend(), search.cbegin(), search.cend()))
        {
            std::cout << "coll includes search" << std::endl;
        }
        else
        {
            std::cout << "coll do not includes search" << std::endl;
        }

        search.push_back(18);
        if (std::includes(coll.cbegin(), coll.cend(), search.cbegin(), search.cend()))
        {
            std::cout << "coll includes search" << std::endl;
        }
        else
        {
            std::cout << "coll do not includes search" << std::endl;
        }
    }

    {
        std::list<int> coll;
        INSERT_ELEMENTS(coll, 1, 10);
        INSERT_ELEMENTS(coll, 1, 10);
        coll.sort();
        PRINT_ELEMENTS(coll, "coll: ");

        auto pos1 = std::lower_bound(coll.begin(), coll.end(), 6);
        auto pos2 = std::upper_bound(coll.begin(), coll.end(), 6);
        std::cout << "pos1: " << std::distance(coll.begin(), pos1) << " pos2: " << std::distance(coll.begin(), pos2) << std::endl;

        coll.insert(std::lower_bound(coll.begin(), coll.end(), 3), 3);
        coll.insert(std::upper_bound(coll.begin(), coll.end(), 9), 9);
        PRINT_ELEMENTS(coll, "coll: ");
    }

    {
        std::list<int> coll;
        INSERT_ELEMENTS(coll, 1, 10);
        INSERT_ELEMENTS(coll, 1, 10);
        coll.sort();
        PRINT_ELEMENTS(coll, "coll: ");

        std::pair<std::list<int>::const_iterator, std::list<int>::const_iterator> range;
        range = std::equal_range(coll.begin(), coll.end(), 5);
        std::cout << "pos1: " << std::distance(coll.cbegin(), range.first) << " pos2: " << std::distance(coll.cbegin(), range.second) << std::endl;
    }

    {
        std::list<int> coll;
        INSERT_ELEMENTS(coll, 5, 11);
        std::set<int> coll2;
        INSERT_ELEMENTS(coll2, 1, 8);

        PRINT_ELEMENTS(coll, "coll: ");
        PRINT_ELEMENTS(coll2, "coll2: ");
        std::merge(coll.begin(), coll.end(), coll2.begin(), coll2.end(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;
    }

    {
        std::vector<int> c1 = {1, 2, 2, 4, 6, 7, 7, 9};
        std::deque<int> c2 = {2, 2, 2, 3, 6, 6, 8, 9};

        PRINT_ELEMENTS(c1, "c1: ");
        PRINT_ELEMENTS(c2, "c2: ");

        std::merge(c1.cbegin(), c1.cend(), c2.cbegin(), c2.cend(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;

        std::set_union(c1.cbegin(), c1.cend(), c2.cbegin(), c2.cend(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;

        std::set_intersection(c1.cbegin(), c1.cend(), c2.cbegin(), c2.cend(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;

        std::set_difference(c1.cbegin(), c1.cend(), c2.cbegin(), c2.cend(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;

        std::set_symmetric_difference(c1.cbegin(), c1.cend(), c2.cbegin(), c2.cend(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;
    }

    {
        std::list<int> coll;
        INSERT_ELEMENTS(coll, 1, 8);
        INSERT_ELEMENTS(coll, 1, 9);
        PRINT_ELEMENTS(coll, "coll: ");

        auto pos = std::find(coll.begin(), coll.end(), 7);
        ++pos;
        std::inplace_merge(coll.begin(), pos, coll.end());
        PRINT_ELEMENTS(coll, "coll: ");
    }

    return 0;
}
