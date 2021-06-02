#include "algostuff.h"

int main()
{
    {
        std::vector<int> coll;
        INSERT_ELEMENTS(coll, 1, 10);
        PRINT_ELEMENTS(coll, "coll is: ");

        std::rotate(coll.begin(), coll.begin() + 1, coll.end());
        PRINT_ELEMENTS(coll, "coll is: ");

        std::rotate(coll.begin(), coll.end() - 2, coll.end());
        PRINT_ELEMENTS(coll, "coll is: ");

        std::rotate(coll.begin(), std::find(coll.begin(), coll.end(), 5), coll.end());
        PRINT_ELEMENTS(coll, "coll is: ");
    }

    {
        std::set<int> coll;
        INSERT_ELEMENTS(coll, 1, 10);
        PRINT_ELEMENTS(coll, "coll is: ");

        std::set<int>::iterator pos = std::next(coll.begin());
        std::rotate_copy(coll.begin(), pos, coll.end(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;

        pos = coll.cend();
        std::advance(pos, -2);
        std::rotate_copy(coll.cbegin(), pos, coll.cend(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;
    }

    return 0;
}