#include "algostuff.h"

class MeanValue
{
private:
    long sum;
    long num;

public:
    MeanValue() : sum(0), num(0) {}

    void operator()(int x)
    {
        num++;
        sum += x;
    }

    operator double()
    {
        return num == 0 ? 0.0 : static_cast<double>(sum) / static_cast<double>(num);
    }
};

int main()
{
    {
        std::vector<int> coll;
        INSERT_ELEMENTS(coll, 1, 9);

        std::for_each(coll.begin(), coll.end(), [](int elem)
                      { std::cout << elem << " "; });
        std::cout << std::endl;
    }

    {
        std::vector<int> coll;
        INSERT_ELEMENTS(coll, 1, 10);
        std::for_each(coll.begin(), coll.end(), [](int &elem)
                      { elem += 10; });
        PRINT_ELEMENTS(coll);

        std::for_each(coll.begin(), coll.end(), [coll](int &elem)
                      { elem += *coll.begin(); });
        PRINT_ELEMENTS(coll);
    }

    {
        std::vector<int> coll;
        INSERT_ELEMENTS(coll, 1, 9);
        double mv = std::for_each(coll.begin(), coll.end(), MeanValue());
        std::cout << mv << std::endl;
    }
    return 0;
}