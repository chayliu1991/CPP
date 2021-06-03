#include "algostuff.h"

int main()
{
    {
        std::vector<int> coll;
        INSERT_ELEMENTS(coll, 1, 10);
        PRINT_ELEMENTS(coll, "coll: ");
        std::cout << std::accumulate(coll.begin(), coll.end(), 0) << std::endl;
        std::cout << std::accumulate(coll.begin(), coll.end(), 1, std::multiplies<int>()) << std::endl;
        std::cout << std::accumulate(coll.begin(), coll.end(), 0, std::minus<int>()) << std::endl;
    }

    {
        std::vector<int> coll;
        INSERT_ELEMENTS(coll, 1, 7);
        PRINT_ELEMENTS(coll, "coll: ");

        std::cout << std::inner_product(coll.cbegin(), coll.cend(), coll.cbegin(), 0) << std::endl;
        std::cout << std::inner_product(coll.cbegin(), coll.cend(), coll.crbegin(), 0) << std::endl;
        std::cout << std::inner_product(coll.cbegin(), coll.cend(), coll.cbegin(), 1, std::multiplies<int>(), std::plus<int>()) << std::endl;
    }

    {
        std::vector<int> coll;
        INSERT_ELEMENTS(coll, 1, 7);
        PRINT_ELEMENTS(coll, "coll: ");
        std::partial_sum(coll.cbegin(), coll.cend(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;

        std::partial_sum(coll.cbegin(), coll.cend(), std::ostream_iterator<int>(std::cout, " "), std::multiplies<int>());
        std::cout << std::endl;
    }

    {
        std::deque<int> coll;
        INSERT_ELEMENTS(coll, 1, 7);
        PRINT_ELEMENTS(coll, "coll: ");

        std::adjacent_difference(coll.cbegin(), coll.cend(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;

        std::adjacent_difference(coll.cbegin(), coll.cend(), std::ostream_iterator<int>(std::cout, " "), std::plus<int>());
        std::cout << std::endl;

        std::adjacent_difference(coll.cbegin(), coll.cend(), std::ostream_iterator<int>(std::cout, " "), std::multiplies<int>());
        std::cout << std::endl;
    }
    return 0;
}