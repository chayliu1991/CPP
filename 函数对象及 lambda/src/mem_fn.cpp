#include <iostream>
#include <functional>
#include <locale>
#include <string>
#include <algorithm>
#include <vector>
#include <memory>
#include <map>
#include <numeric>

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
        std::vector<Person> coll{Person("Tick"), Person("Trick"), Person("Track")};
        //@ mem_fn() adapter 不需要占位符指明调用对象
        std::for_each(coll.begin(), coll.end(), std::mem_fn(&Person::print));
    }

    {
        //@ 若有额外参数传给成员函数，第一实参依旧为调用者
        Person n("nico");
        std::mem_fn (&Person::print)(n);
        std::mem_fn (&Person::print2)(n, "hello ");
    }
    return 0;
}