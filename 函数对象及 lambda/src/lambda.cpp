#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <string>

template <typename C>
void PRINT_ELEMENTS(const C &c, const std::string &prefix)
{
    std::cout << prefix;
    for (auto const &elem : c)
        std::cout << elem << " ";
    std::cout << std::endl;
}

char myToUpper(char c)
{
    std::locale loc;
    return std::use_facet<std::ctype<char>>(loc).toupper(c);
}

class Person
{
private:
    std::string name;

public:
    Person(const std::string &n) : name(n)
    {
    }

    void print() const
    {
        std::cout << name << std::endl;
    }

    void print2(const std::string &prefix) const
    {
        std::cout << prefix << " " << name << std::endl;
    }
};

int main()
{
    {
        auto plus10 = [](int i)
        { return i + 10; };
        std::cout << plus10(9) << std::endl;

        auto plus10times2 = [](int i)
        { return (i + 10) << 1; };
        std::cout << plus10times2(7) << std::endl;

        auto pow3 = [](int i)
        { return i * i * i; };
        std::cout << pow3(6) << std::endl;

        auto inversDivide = [](double d1, double d2)
        {
            return d2 / d1;
        };
        std::cout << inversDivide(49, 7) << std::endl;
    }

    {
        //@ lambda 带状态
        std::vector<int> coll{1, 2, 3, 4, 5, 6, 7, 8};
        long sum = 0;
        std::for_each(coll.begin(), coll.end(), [&sum](int elem)
                      { sum += elem; });
        double mv = static_cast<double>(sum) / static_cast<double>(coll.size());
        std::cout << mv << std::endl;
    }

    {
        std::list<int> coll{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        PRINT_ELEMENTS(coll, "coll is: ");

        std::list<int>::iterator pos;
        int count = 0;
        pos = std::remove_if(coll.begin(), coll.end(), [count](int) mutable
                             { return ++count == 3; });
        coll.erase(pos, coll.end());
        PRINT_ELEMENTS(coll, "coll is: ");
    }

    {
        //@ 调用全局函数
        std::string s("Internationlization");
        std::string sub("Nation");
        std::string::iterator pos;
        pos = std::search(s.begin(), s.end(), sub.begin(), sub.end(), [](char c1, char c2)
                          { return myToUpper(c1) == myToUpper(c2); });

        if (pos != s.end())
        {
            std::cout << sub << " is a sub string of " << s << std::endl;
        }
    }

    {
        //@ 调用成员函数
        std::vector<Person> coll{Person("Tick"), Person("Trick"), Person("Track")};
        std::for_each(coll.begin(), coll.end(), [](const Person &p)
                      { p.print(); });
        std::cout << std::endl;

        std::for_each(coll.begin(), coll.end(), [](const Person &p)
                      { p.print2("Person: "); });
        std::cout << std::endl;
    }

    return 0;
}