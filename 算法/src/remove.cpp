#include "algostuff.h"
#include <cstdlib>

bool differenceOne(int elem1, int elem2)
{
    return elem1 + 1 == elem2 || elem1 - 1 == elem2;
}

bool bothSpaces(char elem1, char elem2)
{
    return elem1 == ' ' && elem2 == ' ';
}

int main()
{
    {
        std::vector<int> coll;
        INSERT_ELEMENTS(coll, 2, 8);
        INSERT_ELEMENTS(coll, 4, 9);
        INSERT_ELEMENTS(coll, 1, 7);
        PRINT_ELEMENTS(coll, "coll is: ");

        std::vector<int>::iterator pos;
        pos = std::remove(coll.begin(), coll.end(), 6);
        std::cout << std::distance(pos, coll.end()) << " elements was removed" << std::endl;

        coll.erase(pos, coll.end());
        PRINT_ELEMENTS(coll, "coll is: ");

        coll.erase(std::remove_if(coll.begin(), coll.end(), [](int elem)
                                  { return elem <= 5; }),
                   coll.end());
        PRINT_ELEMENTS(coll, "coll is: ");
    }

    {
        std::list<int> coll;
        INSERT_ELEMENTS(coll, 1, 6);
        INSERT_ELEMENTS(coll, 1, 9);
        PRINT_ELEMENTS(coll, "coll is: ");

        std::remove_copy(coll.cbegin(), coll.cend(), std::ostream_iterator<int>(std::cout, " "), 4);
        std::cout << std::endl;

        std::remove_copy_if(coll.cbegin(), coll.cend(), std::ostream_iterator<int>(std::cout, " "), [](int elem)
                            { return elem % 2 == 0; });
        std::cout << std::endl;
    }

    {
        int source[]{1, 4, 4, 6, 1, 2, 2, 2, 3, 1, 6, 6, 6, 6, 7, 5, 5, 4, 4, 4};
        std::list<int> coll;
        std::copy(std::begin(source), std::end(source), std::back_inserter(coll));
        PRINT_ELEMENTS(coll, "coll is: ");

        auto pos = std::unique(coll.begin(), coll.end());
        std::copy(coll.begin(), pos, std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;

        std::copy(std::begin(source), std::end(source), coll.begin());
        PRINT_ELEMENTS(coll, "coll is: ");

        coll.erase(std::unique(coll.begin(), coll.end(), std::greater<int>()), coll.end());
        PRINT_ELEMENTS(coll, "coll is: ");
    }

    {
        int source[]{1, 4, 4, 6, 1, 2, 2, 2, 3, 1, 6, 6, 6, 6, 7, 5, 5, 4, 4, 4};
        std::list<int> coll;
        std::copy(std::begin(source), std::end(source), std::back_inserter(coll));
        PRINT_ELEMENTS(coll, "coll is: ");

        std::unique_copy(coll.begin(), coll.end(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;

        std::unique_copy(coll.begin(), coll.end(), std::ostream_iterator<int>(std::cout, " "), differenceOne);
        std::cout << std::endl;

        std::cin.unsetf(std::ios::skipws);
        std::unique_copy(std::istream_iterator<char>(std::cin), std::istream_iterator<char>(), std::ostream_iterator<char>(std::cout, " "), bothSpaces);
    }

    return 0;
}