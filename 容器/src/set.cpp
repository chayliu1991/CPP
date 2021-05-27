#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include <functional>
#include <iterator>
#include <utility>

template <typename C>
void PRINT_ELEMENTS(const C &c, const std::string &prefix)
{
    std::cout << prefix;
    for (auto const &elem : c)
        std::cout << elem << " ";
    std::cout << std::endl;
}

class RuntimeComp
{
public:
    enum cmp_mode
    {
        normal,
        reverse
    };

private:
    cmp_mode mode;

public:
    RuntimeComp(cmp_mode m = normal) : mode(m) {}

    template <typename T>
    bool operator()(const T &t1, const T &t2) const
    {
        return mode == normal ? t1 < t2 : t2 < t1;
    }

    bool operator==(const RuntimeComp &rc) const
    {
        return mode == rc.mode;
    }
};

typedef std::set<int, RuntimeComp> IntSet;

int main()
{
    {
        std::set<float> c1{1.1f, 2.2f, 3.3f};
        std::set<float, std::greater<float>> c2{1.1f, 2.2f, 3.3f};
        //if (c1 == c2) //@ 不同的容器类型之间无法进行比较
        //{
        //}
    }

    {
        std::set<int> c3;
        c3.insert(1);
        c3.insert(2);
        c3.insert(4);
        c3.insert(5);
        c3.insert(6);

        std::cout << "lower_bound(3): " << *c3.lower_bound(3) << std::endl;
        std::cout << "upper_bound(3): " << *c3.upper_bound(3) << std::endl;
        std::cout << "equal_range(3): " << *c3.equal_range(3).first << " " << *c3.equal_range(3).second << std::endl;
    }

    {
        std::set<double> c;
        if (c.insert(3.3).second)
        {
            std::cout << "3.3 is insertered" << std::endl;
        }
        else
        {
            std::cout << "3.3 is already exist" << std::endl;
        }
    }

    {
        std::multiset<int> coll{1, 4, 3, 2, 1, 5};
        PRINT_ELEMENTS(coll, "original coll: ");

        auto pos = coll.find(1);
        if (pos != coll.end())
        {
            coll.erase(pos);
        }
        PRINT_ELEMENTS(coll, "after erase first 1 coll: ");
    }

    {
        std::set<int, std::greater<int>> coll;
        coll.insert({1, 3, 5, 7, 8, 9, 1});
        PRINT_ELEMENTS(coll, "original coll: ");
        coll.erase(coll.begin(), coll.find(5));
        PRINT_ELEMENTS(coll, "after erase coll: ");
    }

    {
        IntSet coll1{4, 7, 5, 1, 6, 2, 5};
        PRINT_ELEMENTS(coll1, "original coll: ");

        RuntimeComp reverse_order(RuntimeComp::reverse);
        IntSet coll2(reverse_order);
        coll2 = {4, 7, 5, 1, 6, 2, 5};
        PRINT_ELEMENTS(coll2, "original coll2: ");
    }
    return 0;
}