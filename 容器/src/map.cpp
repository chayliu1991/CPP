#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <functional>
#include <iterator>
#include <utility>

template <typename T, typename U>
std::ostream &operator<<(std::ostream &ostr, const std::pair<T, U> &pa)
{
    ostr << "{";
    ostr << pa.first << " : " << pa.second;
    return ostr << "}";
}

template <typename C>
void PRINT_ELEMENTS(const C &c, const std::string &prefix)
{
    std::cout << prefix;
    for (auto const &elem : c)
        std::cout << elem << " ";
    std::cout << std::endl;
}

class RuntimeStringComp
{
public:
    enum cmp_mode
    {
        normal,
        nocase
    };

private:
    cmp_mode mode;

    static bool nocase_compare(char c1, char c2)
    {
        return toupper(c1) < toupper(c2);
    }

public:
    RuntimeStringComp(cmp_mode m = normal) : mode(m) {}

    bool operator()(const std::string &s1, const std::string &s2) const
    {
        if (mode == normal)
            return s1 < s2;
        else
            return std::lexicographical_compare(s1.begin(), s1.end(), s2.begin(), s2.end(), nocase_compare);
    }

    bool operator==(const RuntimeStringComp &rc) const
    {
        return mode == rc.mode;
    }
};

int main()
{
    {
        std::map<std::string, float> coll;
        coll.insert(std::map<std::string, float>::value_type("otto", 22.3));
        coll.insert(std::map<std::string, float>::value_type("carl", 33.4));
        PRINT_ELEMENTS(coll, "coll:");

        coll.insert(std::pair<std::string, float>("john", 44.3));
        PRINT_ELEMENTS(coll, "coll:");

        coll.insert(std::make_pair("bibl", 12.5));
        PRINT_ELEMENTS(coll, "coll:");

        coll.emplace(std::piecewise_construct, std::make_tuple("hello"), std::make_tuple(11.9));
        PRINT_ELEMENTS(coll, "coll:");
    }

    {
        std::map<int, char> coll{{1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {4, 'e'}, {5, 'f'}, {6, 'g'}};

        //@ C++ 11 之前的写法
        for (auto it = coll.begin(); it != coll.end();)
        {
            if (it->second == 'c')
                coll.erase(it++);
            else
                ++it;
        }

        PRINT_ELEMENTS(coll, "coll:");
        //@ C++ 11 之后的写法
        for (auto it = coll.begin(); it != coll.end();)
        {
            if (it->first % 2 == 0)
                it = coll.erase(it);
            else
                ++it;
        }
        PRINT_ELEMENTS(coll, "after erase coll:");
    }

    {
        typedef std::map<std::string, float> StringFloatMap;
        StringFloatMap stocks;
        stocks["BASF"] = 367.09;
        stocks["VW"] = 564.12;
        stocks["Siemens"] = 854.32;
        stocks["BMW"] = 1532.89;
        PRINT_ELEMENTS(stocks, "stocks:");

        stocks["Siemens"] = stocks["VW"];
        PRINT_ELEMENTS(stocks, "stocks:");

        stocks.erase("BASF");
        PRINT_ELEMENTS(stocks, "after erase stocks:");
    }

    {
        typedef std::map<std::string, std::string, RuntimeStringComp> StringStringMap;
        auto fill_map = [](StringStringMap &dict)
        {
            dict["Deutschland"] = "Germany";
            dict["Haken"] = "snag";
            dict["deutsch"] = "German";
            dict["arbeiten"] = "work";
            dict["Hund"] = "dog";
            dict["gehen"] = "go";
            dict["Unternehmen"] = "enterprise";
            dict["unternehmen"] = "enterprise";
            dict["Bestatter"] = "undertaker";
        };

        StringStringMap coll;
        fill_map(coll);
        PRINT_ELEMENTS(coll, "coll:");

        RuntimeStringComp ignore_case(RuntimeStringComp::nocase);
        StringStringMap coll2(ignore_case);
        fill_map(coll2);
        PRINT_ELEMENTS(coll2, "coll:");
    }
    return 0;
}
