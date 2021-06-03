#include "algostuff.h"

bool lessLength(const std::string &s1, const std::string &s2)
{
    return s1.length() < s2.length();
}

int main()
{
    {
        std::deque<int> coll;
        INSERT_ELEMENTS(coll, 1, 10);
        INSERT_ELEMENTS(coll, 2, 13);

        PRINT_ELEMENTS(coll, "coll is: ");

        std::sort(coll.begin(), coll.end());
        PRINT_ELEMENTS(coll, "coll is: ");

        std::sort(coll.begin(), coll.end(), std::greater<int>());
        PRINT_ELEMENTS(coll, "coll is: ");
    }

    {
        std::vector<std::string> coll1{"1xxx", "2x", "3x", "4x", "5xx", "6xxxx", "7xx", "8xxx", "9xx", "10xxx", "11", "12", "13", "14xx", "15", "16", "17"};
        std::vector<std::string> coll2(coll1);
        PRINT_ELEMENTS(coll1, "coll1 is: ");
        PRINT_ELEMENTS(coll2, "coll2 is: ");

        std::sort(coll1.begin(), coll1.end(), lessLength);
        std::stable_sort(coll2.begin(), coll2.end(), lessLength);
        PRINT_ELEMENTS(coll1, "coll1 is: ");
        PRINT_ELEMENTS(coll2, "coll2 is: ");
    }

    return 0;
}