#include <list>
#include <vector>
#include <iostream>
#include <iterator>
#include <string>
#include <algorithm>

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
    {
        std::list<std::string> s{"one", "two", "three"};

        std::vector<std::string> v1(s.begin(), s.end()); // copy

        std::vector<std::string> v2(std::make_move_iterator(s.begin()),
                                    std::make_move_iterator(s.end())); // move

        PRINT_ELEMENTS(v1, "v1 now holds: ");
        PRINT_ELEMENTS(v2, "v2 now holds: ");
        PRINT_ELEMENTS(s, "s now holds: ");
    }

    {
        std::vector<std::string> vec{"one", "two"};
        std::list<std::string> lst(std::make_move_iterator(vec.begin()), std::make_move_iterator(vec.end()));
        PRINT_ELEMENTS(vec, "vec now holds: ");
        PRINT_ELEMENTS(lst, "lst now holds: ");

        std::vector<int> vec2{1, 2};
        std::list<int> lst2(std::make_move_iterator(vec2.begin()), std::make_move_iterator(vec2.end()));
        PRINT_ELEMENTS(vec2, "vec2 now holds: ");
        PRINT_ELEMENTS(lst2, "lst2 now holds: ");
    }

    return 0;
}