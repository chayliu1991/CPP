#include "algostuff.h"
#include <cstdlib>

bool absLess(int elem1, int elem2)
{
    return abs(elem1) < abs(elem2);
}

int main()
{
    std::deque<int> coll;
    INSERT_ELEMENTS(coll, 2, 7);
    INSERT_ELEMENTS(coll, -3, 7);
    PRINT_ELEMENTS(coll, "coll is: ");

    std::cout << "minimum : " << *min_element(coll.cbegin(), coll.cend()) << std::endl;
    std::cout << "maximum : " << *max_element(coll.cbegin(), coll.cend()) << std::endl;

    auto mm = minmax_element(coll.cbegin(), coll.cend());
    std::cout << "minimum : " << *mm.first << std::endl;
    std::cout << "maximum : " << *mm.second << std::endl;
    std::cout << "distance : " << std::distance(mm.first, mm.second) << std::endl;

    std::cout << "minimum of abs value: " << *min_element(coll.cbegin(), coll.cend(), absLess) << std::endl;
    std::cout << "maximum of abs value: " << *max_element(coll.cbegin(), coll.cend(), absLess) << std::endl;

    auto mmabs = minmax_element(coll.cbegin(), coll.cend(), absLess);
    std::cout << "minimum of abs value: " << *mmabs.first << std::endl;
    std::cout << "maximum of abs value: " << *mmabs.second << std::endl;
    std::cout << "distance of abs value: " << std::distance(mmabs.first, mmabs.second) << std::endl;

    return 0;
}