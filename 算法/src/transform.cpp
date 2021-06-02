#include "algostuff.h"

int main()
{
    using namespace std::placeholders;

    {
        std::vector<int> coll1;
        std::list<int> coll2;

        INSERT_ELEMENTS(coll1, 1, 10);
        PRINT_ELEMENTS(coll1, "coll1 is : ");

        std::transform(coll1.cbegin(), coll1.cend(), coll1.begin(), std::negate<int>());
        PRINT_ELEMENTS(coll1, "coll1 is : ");
        std::cout << std::endl;

        std::transform(coll1.cbegin(), coll1.cend(), std::back_inserter(coll2), std::bind(std::multiplies<int>(), _1, 100));
        PRINT_ELEMENTS(coll2, "coll2 is : ");
        std::cout << std::endl;
    }

    {
        std::vector<int> coll1;
        std::list<int> coll2;

        INSERT_ELEMENTS(coll1, 1, 10);
        PRINT_ELEMENTS(coll1, "coll1 is : ");
        std::cout << std::endl;

        std::transform(coll1.cbegin(), coll1.cend(), coll1.cbegin(), coll1.begin(), std::multiplies<int>());
        PRINT_ELEMENTS(coll1, "coll1 is : ");
        std::cout << std::endl;

        std::transform(coll1.cbegin(), coll1.cend(), coll1.cbegin(), std::back_inserter(coll2), std::plus<int>());
        PRINT_ELEMENTS(coll2, "coll2 is : ");
        std::cout << std::endl;

        std::transform(coll1.cbegin(), coll1.cend(), coll2.cbegin(), std::ostream_iterator<int>(std::cout, " "), std::minus<int>());
        std::cout << std::endl;
    }

    return 0;
}