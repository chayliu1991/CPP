#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

#define ArraySize(arr) (sizeof(arr) / sizeof(arr[0]))

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
        int vals[]{33, 67, -4, 13, 6, 5, 2};
        std::vector<int> vec(std::begin(vals), std::end(vals));
        PRINT_ELEMENTS(vec, "vec is:");
    }

    {
        //@ C++ 11 之前不提供 std::begin std::end
        int coll[]{9, 8, 2, 3, 33, 67, -4, 13, 6, 5, 2};
        PRINT_ELEMENTS(coll, "coll is:");

        std::transform(coll, coll + ArraySize(coll), coll, coll, std::multiplies<int>());
        PRINT_ELEMENTS(coll, "coll is:");

        std::sort(coll, coll + ArraySize(coll));
        PRINT_ELEMENTS(coll, "coll is:");
    }
    return 0;
}