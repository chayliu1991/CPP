#include <iterator>
#include <algorithm>
#include <vector>
#include <iostream>

int main()
{
    std::vector<int> coll{2, 5, 4, 1, 6, 3};
    auto min_pos = std::min_element(coll.cbegin(), coll.cend());
    std::cout << "min : " << *min_pos << std::endl;
    auto max_pos = std::max_element(coll.cbegin(), coll.cend());
    std::cout << "max : " << *max_pos << std::endl;

    std::sort(coll.begin(), coll.end());
    auto pos3 = std::find(coll.cbegin(), coll.cend(), 3);
    std::reverse(coll.begin(), coll.end());

    for (const auto &elem : coll)
        std::cout << elem << " ";
    std::cout << std::endl;

    std::vector<int> coll2(coll.size());
    std::copy(coll.cbegin(), coll.cend(), coll2.begin());
    return 0;
}
