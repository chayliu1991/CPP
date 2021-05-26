#include <iterator>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <string>
#include <iostream>
#include <functional>

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
        std::list<std::string> ls{"hello", "world"};
        std::vector<std::string> vs(std::make_move_iterator(ls.begin()), std::make_move_iterator(ls.end()));
        PRINT_ELEMENTS(ls, "ls is: ");
        PRINT_ELEMENTS(vs, "vs is: ");
    }

    {
        int array[]{1, 2, 3, 4, 5};
        //@ C++ 98 写法
        std::vector<int> v1(array, array + sizeof(array) / sizeof(array[0]));
        PRINT_ELEMENTS(v1, "v1 is: ");

        //@ C++ 11 写法
        std::vector<int> v2(std::begin(array), std::end(array));
        PRINT_ELEMENTS(v2, "v2 is: ");
    }

    {
        std::vector<int> v1{2, 4, 6, 8, 10};
        std::vector<int> v2 = std::move(v1);
        PRINT_ELEMENTS(v1, "v1 is: ");
        PRINT_ELEMENTS(v2, "v2 is: ");
    }

    {
        std::cout << "请输入数字:" << std::endl;
        std::deque<int> dq{std::istream_iterator<int>(std::cin), std::istream_iterator<int>()};
        PRINT_ELEMENTS(dq, "dq is:");
    }
    return 0;
}