#include "algostuff.h"
#include <cstdlib>
#include <random>

class MyRandom
{
public:
    ptrdiff_t operator()(ptrdiff_t max)
    {
        double tmp;
        tmp = static_cast<double>(rand()) / static_cast<double>(RAND_MAX);
        return static_cast<ptrdiff_t>(tmp * max);
    }
};

int main()
{
    {
        std::vector<int> coll;
        INSERT_ELEMENTS(coll, 1, 10);
        PRINT_ELEMENTS(coll, "coll is: ");

        std::random_shuffle(coll.begin(), coll.end());
        PRINT_ELEMENTS(coll, "coll is: ");

        std::sort(coll.begin(), coll.end());
        PRINT_ELEMENTS(coll, "coll sorted: ");

        std::default_random_engine e;
        std::shuffle(coll.begin(), coll.end(), e);
        PRINT_ELEMENTS(coll, "coll is: ");
    }

    {
        //@ 使用自定义的随机数生成器
        std::vector<int> coll;
        INSERT_ELEMENTS(coll, 1, 10);
        PRINT_ELEMENTS(coll, "coll is: ");
        MyRandom rd;
        std::random_shuffle(coll.begin(), coll.end(), rd);
        PRINT_ELEMENTS(coll, "coll is: ");
    }

    return 0;
}