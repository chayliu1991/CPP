#include <iostream>
#include <functional>
#include <locale>
#include <string>
#include <algorithm>
#include <vector>
#include <memory>
#include <map>
#include <numeric>

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
        //@ not2 的使用
        std::vector<int> coll{6, 3, 4, 5, 2, 1};
        std::sort(coll.begin(), coll.end(), std::not2(std::less<int>()));
        PRINT_ELEMENTS(coll, "coll is: ");

        //@ 比下面的形式简单
        using namespace std::placeholders;
        std::sort(coll.begin(), coll.end(), std::bind(std::logical_not<bool>(), std::bind(std::less<int>(), _1, _2)));
        PRINT_ELEMENTS(coll, "coll is: ");

        //@ 不如直接
        std::sort(coll.begin(), coll.end(), std::greater_equal<int>());
        PRINT_ELEMENTS(coll, "coll is: ");
    }
}