#include "algostuff.h"

int main()
{
    {
        std::vector<int> coll1{1, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        PRINT_ELEMENTS(coll1, "coll1 is: ");
        if (std::is_sorted(coll1.begin(), coll1.end()))
        {
            std::cout << "coll1 is sorted " << std::endl;
        }
        else
        {
            std::cout << "coll1 is not sorted " << std::endl;
        }

        std::map<int, std::string> coll2{{1, "Bill"}, {2, "Jim"}, {3, "Nico"}, {4, "Liu"}, {5, "Ai"}};
        PRINT_MAPPED_ELEMENTS(coll2, "coll2 is: ");
        auto compareName = [](const std::pair<int, std::string> &e1, const std::pair<int, std::string> &e2)
        {
            return e1.second < e2.second;
        };
        if (std::is_sorted(coll2.begin(), coll2.end(), compareName))
        {
            std::cout << "coll2 is sorted " << std::endl;
        }
        else
        {
            std::cout << "coll2 is not sorted " << std::endl;
        }

        auto pos = std::is_sorted_until(coll2.begin(), coll2.end(), compareName);
        if (pos != coll2.end())
        {
            std::cout << "first unsorted name: " << pos->second << std::endl;
        }
    }

    {
        std::vector<int> coll1{5, 3, 9, 1, 3, 4, 8, 2, 6};
        PRINT_ELEMENTS(coll1, "coll1 is: ");
        auto isOdd = [](int elem)
        {
            return elem % 2 == 1;
        };

        if (std::is_partitioned(coll1.begin(), coll1.end(), isOdd))
        {
            std::cout << "coll1 is partitioned " << std::endl;
            auto pos = std::partition_point(coll1.begin(), coll1.end(), isOdd);
            std::cout << "first even is: " << *pos << std::endl;
        }
        else
        {
            std::cout << "coll1 is not partitioned " << std::endl;
        }
    }

    {
        std::vector<int> coll1 = {9, 8, 7, 7, 7, 5, 4, 2, 1};
        std::vector<int> coll2 = {5, 3, 2, 1, 4, 7, 9, 8, 6};

        PRINT_ELEMENTS(coll1, "coll1 is: ");
        PRINT_ELEMENTS(coll2, "coll2 is: ");
        std::cout << std::boolalpha;
        std::cout << "is heap: " << std::is_heap(coll1.begin(), coll1.end()) << std::endl;
        std::cout << "is heap: " << std::is_heap(coll2.begin(), coll2.end()) << std::endl;

        auto pos = std::is_heap_until(coll2.cbegin(), coll2.cend());
        if (pos != coll2.end())
        {
            std::cout << "first non-heap element : " << *pos << std::endl;
        }
    }

    {
        std::vector<int> coll1;
        INSERT_ELEMENTS(coll1, 1, 10);

        std::vector<int>::iterator pos;
        PRINT_ELEMENTS(coll1, "coll1 is: ");

        auto isEven = [](int elem)
        {
            return elem % 2 == 0;
        };

        std::cout << std::boolalpha;
        std::cout << "all_of even: " << std::all_of(coll1.cbegin(), coll1.cend(), isEven) << std::endl;
        std::cout << "any_of even: " << std::any_of(coll1.cbegin(), coll1.cend(), isEven) << std::endl;
        std::cout << "none_of even: " << std::none_of(coll1.cbegin(), coll1.cend(), isEven) << std::endl;
    }

    return 0;
}