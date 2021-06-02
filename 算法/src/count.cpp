#include "algostuff.h"

int main()
{
    std::vector<int> coll;
    int num;
    INSERT_ELEMENTS(coll, 1, 10);
    PRINT_ELEMENTS(coll, "coll is: ");

    num = std::count(coll.begin(), coll.end(), 4);
    std::cout << "number of equal to 4: " << num << std::endl;

    num = std::count_if(coll.begin(), coll.end(), [](int elem)
                        { return elem % 2 == 0; });
    std::cout << "number of elements with even value: " << num << std::endl;

    num = std::count_if(coll.begin(), coll.end(), [](int elem)
                        { return elem > 4; });
    std::cout << "number of elements greater than 4: " << num << std::endl;
    return 0;
}