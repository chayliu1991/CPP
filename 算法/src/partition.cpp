#include "algostuff.h"
#include <cstdlib>
#include <random>

int main()
{
    {
        std::vector<int> coll1;
        std::vector<int> coll2;

        INSERT_ELEMENTS(coll1, 1, 9);
        INSERT_ELEMENTS(coll2, 3, 10);
        PRINT_ELEMENTS(coll1, "coll1: ");
        PRINT_ELEMENTS(coll2, "coll2: ");

        std::vector<int>::iterator pos1, pos2;

        pos1 = std::partition(coll1.begin(), coll1.end(), [](int elem)
                              { return elem % 2 == 0; });
        pos2 = std::stable_partition(coll2.begin(), coll2.end(), [](int elem)
                                     { return elem % 2 == 0; });

        PRINT_ELEMENTS(coll1, "coll1: ");
        std::cout << "coll1 first not even is: " << *pos1 << std::endl;

        PRINT_ELEMENTS(coll2, "coll2: ");
        std::cout << "coll2 first not even is: " << *pos2 << std::endl;
    }

    {
        std::vector<int> coll1;
        INSERT_ELEMENTS(coll1, 1, 17);
        std::vector<int> odd, even;
        std::partition_copy(coll1.begin(), coll1.end(), std::back_inserter(even), std::back_inserter(odd), [](int elem)
                            { return elem % 2 == 0; });
        PRINT_ELEMENTS(odd, "odd: ");
        PRINT_ELEMENTS(even, "even: ");
    }

    return 0;
}