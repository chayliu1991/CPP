#include "algostuff.h"

int main()
{

    std::vector<int> coll1;
    std::deque<int> coll2;

    INSERT_ELEMENTS(coll1, 1, 10);
    INSERT_ELEMENTS(coll2, 11, 23);
    PRINT_ELEMENTS(coll1, "coll1 is : ");
    PRINT_ELEMENTS(coll2, "coll2 is : ");

    std::deque<int>::iterator pos;
    pos = std::swap_ranges(coll1.begin(), coll1.end(), coll2.begin());

    PRINT_ELEMENTS(coll1, "coll1 is : ");
    PRINT_ELEMENTS(coll2, "coll2 is : ");
    if (pos != coll2.end())
    {
        std::cout << "first element not modified: " << *pos << std::endl;
    }

    std::swap_ranges(coll2.begin(), coll2.begin() + 3, coll2.rbegin());
    PRINT_ELEMENTS(coll2, "coll2 is : ");

    return 0;
}