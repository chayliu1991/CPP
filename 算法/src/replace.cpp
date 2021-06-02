#include "algostuff.h"
#include <cstdlib>

int main()
{
    {
        std::list<int> coll;
        INSERT_ELEMENTS(coll, 2, 7);
        INSERT_ELEMENTS(coll, 4, 9);
        PRINT_ELEMENTS(coll, "coll: ");

        std::replace(coll.begin(), coll.end(), 6, 55);
        PRINT_ELEMENTS(coll, "coll: ");

        std::replace_if(
            coll.begin(), coll.end(), [](int elem)
            { return elem < 5; },
            0);
        PRINT_ELEMENTS(coll, "coll: ");
    }

    {
        std::list<int> coll;
        INSERT_ELEMENTS(coll, 2, 7);
        INSERT_ELEMENTS(coll, 4, 9);
        PRINT_ELEMENTS(coll, "coll: ");

        std::replace_copy(coll.cbegin(), coll.cend(), std::ostream_iterator<int>(std::cout, " "), 5, 88);
        std::cout << std::endl;

        std::replace_copy_if(
            coll.cbegin(), coll.cend(), std::ostream_iterator<int>(std::cout, " "), [](int elem)
            { return elem % 2 == 0; },
            666);
        std::cout << std::endl;
    }

    return 0;
}