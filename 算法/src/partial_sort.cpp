#include "algostuff.h"

bool lessLength(const std::string &s1, const std::string &s2)
{
    return s1.length() < s2.length();
}

int main()
{
    {
        std::deque<int> coll;
        INSERT_ELEMENTS(coll, 3, 7);
        INSERT_ELEMENTS(coll, 2, 6);
        INSERT_ELEMENTS(coll, 1, 5);

        PRINT_ELEMENTS(coll, "coll is: ");

        std::partial_sort(coll.begin(), coll.begin() + 5, coll.end());
        PRINT_ELEMENTS(coll, "coll is: ");

        std::partial_sort(coll.begin(), coll.begin() + 5, coll.end(), std::greater<int>());
        PRINT_ELEMENTS(coll, "coll is: ");

        std::partial_sort(coll.begin(), coll.end(), coll.end());
        PRINT_ELEMENTS(coll, "coll is: ");
    }

    {
        std::deque<int> coll1;
        std::vector<int> coll6(6);
        std::vector<int> coll30(30);

        INSERT_ELEMENTS(coll1, 3, 7);
        INSERT_ELEMENTS(coll1, 2, 6);
        INSERT_ELEMENTS(coll1, 1, 5);

        PRINT_ELEMENTS(coll1, "coll1 is: ");

        std::vector<int>::const_iterator pos6;
        pos6 = std::partial_sort_copy(coll1.begin(), coll1.end(), coll6.begin(), coll6.end());
        std::copy(coll6.begin(), coll6.end(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;

        std::vector<int>::const_iterator pos30;
        pos30 = std::partial_sort_copy(coll1.cbegin(), coll1.cend(), coll30.begin(), coll30.end(), std::greater<int>());
        std::copy(coll30.cbegin(), pos30, std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;
    }

    return 0;
}