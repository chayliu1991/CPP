#include "algostuff.h"
#include <cstdlib>

int main()
{

    {
        std::fill_n(std::ostream_iterator<float>(std::cout, " "), 10, 3.1);
        std::cout << std::endl;

        std::list<std::string> coll;
        std::fill_n(std::back_inserter(coll), 5, "hello");
        PRINT_ELEMENTS(coll, "coll is: ");

        std::fill(coll.begin(), coll.end(), "again");
        PRINT_ELEMENTS(coll, "coll is: ");

        std::fill_n(coll.begin(), coll.size() - 2, "hi");
        PRINT_ELEMENTS(coll, "coll is: ");

        std::list<std::string>::iterator pos1, pos2;
        pos1 = coll.begin();
        pos2 = coll.end();
        std::fill(++pos1, --pos2, "hmmmm");
        PRINT_ELEMENTS(coll, "coll is: ");
    }

    {
        std::list<int> coll;
        std::generate_n(std::back_inserter(coll), 6, rand);
        PRINT_ELEMENTS(coll, "coll is: ");

        std::generate(coll.begin(), coll.end(), rand);
        PRINT_ELEMENTS(coll, "coll is: ");
    }

    {
        std::array<int, 10> coll;
        std::iota(coll.begin(), coll.end(), 42);
        PRINT_ELEMENTS(coll, "coll is: ");
    }

    return 0;
}