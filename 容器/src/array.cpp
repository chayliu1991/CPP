#include <iostream>
#include <array>
#include <string>
#include <cstring>
#include <cstdio>

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
        std::array<int, 4> a1;
        PRINT_ELEMENTS(a1, "a1 is: ");
        std::array<int, 4> a2 = {};
        PRINT_ELEMENTS(a2, "a2 is: ");
    }

    {
        //std::array<int, 3> a1({1,2,3});  //@ 错误
        std::array<int, 3> a2 = {1, 2, 3}; //@ 正确
        std::array<int, 3> a3{1, 2, 3};    //@ 正确
    }

    {
        std::array<int, 5> arr;
        arr.fill(1);
        PRINT_ELEMENTS(arr, "arr is: ");
    }

    {
        std::array<int, 3> arr{1, 2, 3};
        std::cout << "first is: " << arr[0] << std::endl;
        std::cout << "middle is: " << std::get<1>(arr) << std::endl;
        std::cout << "last is: " << arr.back() << std::endl;
    }

    {
        std::array<char, 60> carray{};
        strcpy(carray.data(), "hello,world");
        printf("carray is : %s\n", carray.data());
    }

    {
        typedef std::array<std::string, 5> FiveStrings;
        FiveStrings arr = {"hello", "hello", "hi", "hi", "hi"};
        std::cout << std::tuple_size<FiveStrings>::value << std::endl;
        std::tuple_element<1, FiveStrings>::type hi = "hi";
        std::cout << std::get<0>(arr) << std::endl;
    }

    return 0;
}