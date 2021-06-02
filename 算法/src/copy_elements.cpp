#include "algostuff.h"

int main()
{
    {
        std::vector<std::string> coll1{"hello", "this", "is", "an", "example"};
        std::list<std::string> coll2;

        std::copy(coll1.cbegin(), coll1.cend(), std::back_inserter(coll2));
        std::copy(coll2.cbegin(), coll2.cend(), std::ostream_iterator<std::string>(std::cout, " "));
        std::cout << std::endl;

        std::copy(coll1.crbegin(), coll1.crend(), coll2.begin());
        std::copy(coll2.cbegin(), coll2.cend(), std::ostream_iterator<std::string>(std::cout, " "));
        std::cout << std::endl;
    }

    {
        std::vector<char> source(10, '.');
        for (int c = 'a'; c <= 'f'; c++)
        {
            source.push_back(c);
        }
        source.insert(source.end(), 10, '.');
        PRINT_ELEMENTS(source, "source is: ");

        std::vector<char> c1(source.cbegin(), source.cend());
        std::copy(c1.cbegin() + 10, c1.cbegin() + 16, c1.begin() + 7);
        PRINT_ELEMENTS(c1, "c1 is:		");

        std::vector<char> c2(source.cbegin(), source.cend());
        std::copy_backward(c2.cbegin() + 10, c2.cbegin() + 16, c2.begin() + 19);
        PRINT_ELEMENTS(c2, "c2 is:		");
    }

    return 0;
}