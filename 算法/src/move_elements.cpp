#include "algostuff.h"

int main()
{
    std::vector<std::string> coll1{"Hello", "this", "is", "an", "example"};
    std::list<std::string> coll2;
    std::copy(coll1.begin(), coll1.end(), std::back_inserter(coll2));

    std::move(coll2.begin(), coll2.end(), std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << std::endl;

    std::move(coll1.crbegin(), coll1.crend(), coll2.begin());
    std::move(coll2.begin(), coll2.end(), std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << std::endl;

    return 0;
}