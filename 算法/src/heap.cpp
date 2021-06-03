#include "algostuff.h"

int main()
{
    {
        std::vector<int> coll;
        INSERT_ELEMENTS(coll, 3, 8);
        INSERT_ELEMENTS(coll, 5, 10);
        INSERT_ELEMENTS(coll, 1, 5);

        PRINT_ELEMENTS(coll, "coll : ");

        std::make_heap(coll.begin(), coll.end());
        PRINT_ELEMENTS(coll, "coll : ");

        std::pop_heap(coll.begin(), coll.end());
        coll.pop_back();
        PRINT_ELEMENTS(coll, "coll : ");

        coll.push_back(19);
        std::push_heap(coll.begin(), coll.end());
        PRINT_ELEMENTS(coll, "coll : ");

        std::sort_heap(coll.begin(), coll.end());
        PRINT_ELEMENTS(coll, "coll : ");
    }

    return 0;
}