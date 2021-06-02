#include <iostream>
#include <functional>
#include <locale>
#include <string>
#include <algorithm>
#include <vector>
#include <memory>
#include <cmath>
#include <iterator>

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
        //@ bind 预定义的函数对象
        auto plus10 = std::bind(std::plus<int>(), std::placeholders::_1, 10);
        std::cout << "+10： " << plus10(9) << std::endl;

        auto plus10times2 = std::bind(std::multiplies<int>(), std::bind(std::plus<int>(), std::placeholders::_1, 10), 2);
        std::cout << "+10： " << plus10times2(7) << std::endl;

        auto pow3 = std::bind(std::multiplies<int>(), std::bind(std::multiplies<int>(), std::placeholders::_1, std::placeholders::_1), std::placeholders::_1);
        std::cout << "x*x*x： " << pow3(6) << std::endl;

        auto inversDivide = std::bind(std::divides<double>(), std::placeholders::_2, std::placeholders::_1);
        std::cout << "invdiv： " << inversDivide(49, 7) << std::endl;
    }

    {
        //@ bind 调用全局函数
        using namespace std::placeholders;
        std::string s("Internationalization");
        std::string sub("Nation");
        std::string::iterator pos;
        pos = std::search(s.begin(), s.end(), sub.begin(), sub.end(), std::bind(std::equal_to<char>(), std::bind(myToUpper, _1), std::bind(myToUpper, _2)));

        if (pos != s.end())
        {
            std::cout << sub << " is a sub string of " << s << std::endl;
        }
    }

    {
        //@ bind 调用成员函数
        using namespace std::placeholders;
        std::vector<Person> coll{Person("Tick"), Person("Trick"), Person("Track")};
        std::for_each(coll.begin(), coll.end(), std::bind(&Person::print, _1));
        std::cout << std::endl;

        std::for_each(coll.begin(), coll.end(), std::bind(&Person::print2, _1, "Person: "));
        std::cout << std::endl;

        Person n("nico");
        std::bind(&Person::print2, _1, "This is: ")(n);

        std::vector<Person *> cp;
        cp.push_back(new Person("Tick"));
        cp.push_back(new Person("Trick"));
        std::for_each(cp.begin(), cp.end(), std::bind(&Person::print2, _1, "I am: "));

        for (auto p : cp)
        {
            delete p;
        }

        std::vector<std::shared_ptr<Person>> sp;
        sp.push_back(std::make_shared<Person>("Tick"));
        sp.push_back(std::make_shared<Person>("Trick"));
        std::for_each(sp.begin(), sp.end(), std::bind(&Person::print2, _1, "Hi, "));
    }

    {
        //@ 绑定成员对象
        using namespace std::placeholders;
        std::map<std::string, int> coll{{"a", 1}, {"b", 2}, {"c", 3}};
        int sum = std::accumulate(coll.begin(), coll.end(), 0, std::bind(std::plus<int>(), _1, std::bind(&std::map<std::string, int>::value_type::second, _2)));
        std::cout << sum << std::endl;
    }

    {
        using namespace std::placeholders;
        std::vector<int> coll{1, 2, 3, 4, 5, 6, 7, 8, 9};
        std::transform(coll.begin(), coll.end(), std::ostream_iterator<float>(std::cout, ", "), std::bind(fopow<float, int>(), 3, _1));
        std::cout << std::endl;

        std::transform(coll.begin(), coll.end(), std::ostream_iterator<float>(std::cout, ", "), std::bind(fopow<float, int>(), _1, 3));
        std::cout << std::endl;
    }
    return 0;
}