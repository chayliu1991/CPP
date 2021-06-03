#include "algostuff.h"

int main()
{
    {
        std::vector<int> coll;
        INSERT_ELEMENTS(coll, 1, 4);
        PRINT_ELEMENTS(coll, "coll is: ");
        while (std::next_permutation(coll.begin(), coll.end()))
        {
            PRINT_ELEMENTS(coll, "coll: ");
        }
        PRINT_ELEMENTS(coll, "afterward: ");

        while (std::prev_permutation(coll.begin(), coll.end()))
        {
            PRINT_ELEMENTS(coll, "coll: ");
        }
        PRINT_ELEMENTS(coll, "now: ");

        while (std::prev_permutation(coll.begin(), coll.end()))
        {
            PRINT_ELEMENTS(coll, "coll: ");
        }
        PRINT_ELEMENTS(coll, "afterward: ");
    }

    return 0;
}