#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
#include <iterator>

template <typename C>
void PRINT_ELEMENTS(const C &c, const std::string &prefix)
{
    std::cout << prefix;
    for (auto const &elem : c)
        std::cout << elem << " ";
    std::cout << std::endl;
}

int main()
{
    std::deque<std::string> coll;
    coll.assign(3, std::string("string"));
    coll.push_back(std::string("last string"));
    coll.push_front(std::string("first string"));

    PRINT_ELEMENTS(coll, "original coll:");

    coll.resize(2);
    PRINT_ELEMENTS(coll, "after resize coll:");

    return 0;
}
