#include <iterator>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <string>
#include <iostream>

template <typename C>
void PRINT_ELEMENTS(const C &c, const std::string &prefix)
{
    std::cout << prefix;
    for (auto const &elem : c)
        std::cout << elem << " ";
    std::cout << std::endl;
}

void print(int num)
{
    std::cout << num << ' ';
}

int square(int x)
{
    return x * x;
}

bool is_prime(int num)
{
    num = std::abs(num);
    if (num == 0 || num == 1)
        return false;

    int divisor;
    for (divisor = num / 2; num % divisor != 0; --divisor)
        ;
    return divisor == 1;
}

struct Person
{
    std::string first_name;
    std::string last_name;
};

bool person_sort_criterion(const Person &p1, const Person &p2)
{
    return (p1.last_name < p2.last_name) || ((p1.last_name == p2.last_name) && (p1.first_name < p2.first_name));
}

int main()
{
    {
        std::list<int> coll;
        for (int i = 1; i <= 6; ++i)
        {
            coll.push_front(i);
            coll.push_back(i);
        }

        std::copy(coll.cbegin(), coll.cend(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;

        std::list<int>::iterator end = std::remove(coll.begin(), coll.end(), 3);
        std::copy(coll.begin(), end, std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;

        std::cout << "remove " << std::distance(end, coll.end()) << " elements";
        std::cout << std::endl;

        std::copy(coll.cbegin(), coll.cend(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;

        coll.erase(end, coll.end());
        std::copy(coll.cbegin(), coll.cend(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;
    }

    {
        std::set<int> coll{1, 2, 3, 4, 5, 6, 7, 8, 9};
        std::copy(coll.cbegin(), coll.cend(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;
        int num = coll.erase(3);
        std::cout << "number of erased : " << num << std::endl;
        std::copy(coll.cbegin(), coll.cend(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;
    }

    {
        std::set<int> coll{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        PRINT_ELEMENTS(coll, "original:");

        std::vector<int> coll2;
        std::transform(coll.begin(), coll.end(), std::back_inserter(coll2), square);
        PRINT_ELEMENTS(coll2, "squared:");
    }

    {
        std::list<int> coll{24, 25, 26, 27, 28, 29, 30};
        auto pos = std::find_if(coll.cbegin(), coll.cend(), is_prime);
        if (pos != coll.end())
        {
            std::cout << *pos << " is first prime number found" << std::endl;
        }
        else
        {
            std::cout << "no prime number found" << std::endl;
        }

        std::deque<Person> dp;
        std::sort(dp.begin(), dp.end(), person_sort_criterion);
    }

    return 0;
}