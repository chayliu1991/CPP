#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <vector>
#include <list>
#include <iterator>

template <typename C>
void PRINT_ELEMENTS(const C &c, const std::string &prefix)
{
    std::cout << prefix;
    for (auto const &elem : c)
        std::cout << elem << " ";
    std::cout << std::endl;
}

class Person
{
private:
    std::string first_name;
    std::string last_name;

public:
    Person(const std::string &fname, const std::string &lname) : first_name(fname), last_name(lname)
    {
    }
    std::string firstname() const { return first_name; }
    std::string lastname() const { return last_name; }
};

void print(const Person &p)
{
    std::cout << p.firstname() << " " << p.lastname() << std::endl;
}

class PersonSortCriterion
{
public:
    bool operator()(const Person &p1, const Person &p2)
    {
        return p1.lastname() < p2.lastname() || (p1.lastname() == p2.lastname() && p1.firstname() < p2.firstname());
    }
};

//@ 函数对象可以带有状态
class IntSequence
{
private:
    int value;

public:
    IntSequence(int v) : value(v)
    {
    }

    int operator()()
    {
        return ++value;
    }
};

class MeanValue
{
private:
    long num;
    long sum;

public:
    MeanValue() : num(0), sum(0)
    {
    }

    void operator()(int elem)
    {
        ++num;
        sum += elem;
    }

    double value()
    {
        return static_cast<double>(sum) / static_cast<double>(num);
    }
};

class Nth
{
private:
    int nth;
    int count;

public:
    Nth(int n) : nth(n), count(0)
    {
    }

    bool operator()(int)
    {
        return ++count == nth;
    }
};

int main()
{
    {
        std::vector<Person> vec{{"san", "zhang"}, {"si", "li"}, {"wu", "wang"}, {"liu", "liu"}, {"qi", "feng"}};
        std::for_each(vec.begin(), vec.end(), print);

        std::cout << "============= after sort ================" << std::endl;
        std::sort(vec.begin(), vec.end(), PersonSortCriterion());
        std::for_each(vec.begin(), vec.end(), print);
        std::cout << "=============================" << std::endl;
    }

    {
        std::list<int> coll;
        std::generate_n(std::back_inserter(coll), 10, IntSequence(0));
        PRINT_ELEMENTS(coll, "coll is:");

        std::generate(std::next(coll.begin()), std::prev(coll.end()), IntSequence(42));
        PRINT_ELEMENTS(coll, "coll is:");
    }

    {
        std::list<int> coll;
        IntSequence seq(1);

        std::generate_n<std::back_insert_iterator<std::list<int>>, int, IntSequence &>(std::back_inserter(coll), 4, seq);
        PRINT_ELEMENTS(coll, "coll is:");

        std::generate_n(std::back_inserter(coll), 4, IntSequence(42));
        PRINT_ELEMENTS(coll, "coll is:");

        std::generate_n(std::back_inserter(coll), 4, seq);
        PRINT_ELEMENTS(coll, "coll is:");

        std::generate_n(std::back_inserter(coll), 4, seq);
        PRINT_ELEMENTS(coll, "coll is:");
    }

    {
        std::vector<int> coll{1, 2, 3, 4, 5, 6, 7, 8};
        MeanValue mv = std::for_each(coll.begin(), coll.end(), MeanValue());
        std::cout << "mean value: " << mv.value() << std::endl;
    }

    {
        std::list<int> coll{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        PRINT_ELEMENTS(coll, "coll is: ");

        std::list<int>::iterator pos;
        pos = std::remove_if(coll.begin(), coll.end(), Nth(3));
        coll.erase(pos, coll.end());
        PRINT_ELEMENTS(coll, "3rd removed: ");
    }
    return 0;
}