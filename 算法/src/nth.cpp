#include "algostuff.h"

int main()
{
    {
        std::deque<int> coll;
        INSERT_ELEMENTS(coll, 3, 7);
        INSERT_ELEMENTS(coll, 2, 6);
        INSERT_ELEMENTS(coll, 1, 5);

        PRINT_ELEMENTS(coll);

        std::nth_element(coll.begin(), coll.begin() + 3, coll.end());
        std::copy(coll.cbegin(), coll.cbegin() + 4, std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;

        std::nth_element(coll.begin(), coll.begin() + 3, coll.end(), std::greater<int>());
        std::copy(coll.cbegin(), coll.cbegin() + 4, std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;

        std::nth_element(coll.begin(), coll.end() - 3, coll.end());
        std::copy(coll.cend() - 3, coll.cend(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;
    }

    return 0;
}