#include "algostuff.h"

int main()
{
    {
        std::vector<int> coll;
        INSERT_ELEMENTS(coll, 1, 10);
        PRINT_ELEMENTS(coll, "coll is: ");

        std::reverse(coll.begin(), coll.end());
        PRINT_ELEMENTS(coll, "coll is: ");

        std::reverse(std::next(coll.begin()), std::prev(coll.end()));
        PRINT_ELEMENTS(coll, "coll is: ");

        std::reverse_copy(coll.begin(), coll.end(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;
    }

    return 0;
}