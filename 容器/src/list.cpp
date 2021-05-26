#include <iostream>
#include <list>
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
    std::list<int> coll1{1, 4, 2, 5, 4, 7, 8, 3};
    std::list<int> coll2{2, 2, 3, 9, 1, 3, 3, 6};

    PRINT_ELEMENTS(coll1, "original coll1:");

    coll1.sort();
    PRINT_ELEMENTS(coll1, "after sort original coll1:");

    coll1.unique();
    PRINT_ELEMENTS(coll1, "after unique original coll1:");

    coll1.splice(coll1.end(), coll1, coll1.begin());
    PRINT_ELEMENTS(coll1, "after splice original coll1:");

    coll1.splice(coll1.end(), coll2, coll2.begin(), coll2.end());
    PRINT_ELEMENTS(coll1, "after splice original coll1:");

    std::list<int> coll3{9, 9, 9, 7, 6};
    coll3.sort();
    coll1.sort();
    coll1.merge(coll3);
    PRINT_ELEMENTS(coll1, "after merge original coll1:");

    coll1.remove(9);
    PRINT_ELEMENTS(coll1, "after remove original coll1:");

    coll1.remove_if([](int x)
                    { return x % 2 == 0; });
    PRINT_ELEMENTS(coll1, "after remove_if original coll1:");

    coll1.reverse();
    PRINT_ELEMENTS(coll1, "after reverse original coll1:");
    return 0;
}