#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <functional>
#include <iterator>
#include <utility>
#include <typeinfo>
#include <iomanip>

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

//@ boost
template <typename T>
void hash_combine(std::size_t &seed, const T &val)
{
    seed ^= std::hash<T>()(val) + 0x9e3778b9 + (seed << 6) + (seed << 2);
}

template <typename T>
inline void hash_val(std::size_t &seed, const T &val)
{
    hash_combine(seed, val);
}

template <typename T, typename... Types>
inline void hash_val(std::size_t &seed, const T &val, const Types... args)
{
    hash_combine(seed, val);
    hash_val(seed, args...);
}

template <typename... Types>
inline std::size_t hash_val(const Types... args)
{
    std::size_t seed = 0;
    hash_val(seed, args...);
    return seed;
}

class Customer
{
private:
    std::string fname;
    std::string lname;
    long no;

public:
    Customer(const std::string &fn, const std::string &ln, long n) : fname(fn), lname(ln), no(n)
    {
    }

    friend std::ostream &operator<<(std::ostream &strm, const Customer &c)
    {
        return strm << "[" << c.fname << "," << c.lname << "," << c.no << "]";
    }

    std::string firstname() const
    {
        return fname;
    }

    std::string lastname() const
    {
        return lname;
    }

    long number() const
    {
        return no;
    }
    friend class CustomerHash;
    friend class CustomerEqual;
};

class CustomerHash
{
public:
    std::size_t operator()(const Customer &c) const
    {
        return hash_val(c.fname, c.lname, c.no);
    }
};

class CustomerEqual
{
public:
    bool operator()(const Customer &c1, const Customer &c2) const
    {
        return c1.no == c2.no;
    }
};

template <typename T>
void printf_hashtable_state(const T &cont)
{
    std::cout << "size:" << cont.size() << "\n";
    std::cout << "buckets:" << cont.bucket_count() << "\n";
    std::cout << "load factor:" << cont.load_factor() << "\n";
    std::cout << "max load factor:" << cont.max_load_factor() << "\n";

    if (typeid(typename std::iterator_traits<typename T::iterator>::iterator_category) == typeid(std::bidirectional_iterator_tag))
    {
        std::cout << "chaining style:doubly-linked"
                  << "\n";
    }
    else
    {
        std::cout << "chaining style:single-linked"
                  << "\n";
    }

    std::cout << "data: "
              << "\n";
    for (auto idx = 0; idx != cont.bucket_count(); ++idx)
    {
        std::cout << "b[" << std::setw(2) << idx << "]: ";
        for (auto pos = cont.begin(idx); pos != cont.end(); ++pos)
        {
            std::cout << *pos << " ";
        }
        std::cout << "\n";
    }
    std::cout << std::endl;
}

int main()
{
    {
        std::unordered_set<int> coll{1, 2, 3, 4, 6, 7, 8, 16, 9, 13, 17, 19, 77};
        PRINT_ELEMENTS(coll, "coll:");

        coll.insert({2, 3, 4, 5, 6, 7, 8, 90, 121});
        PRINT_ELEMENTS(coll, "coll:");

        coll.erase(121);
        PRINT_ELEMENTS(coll, "coll:");

        if (coll.find(19) != coll.end())
        {
            std::cout << "19 is found" << std::endl;
        }

        for (auto it = coll.begin(); it != coll.end();)
        {
            if (*it % 2 == 0)
            {
                it = coll.erase(it);
            }
            else
                ++it;
        }
        PRINT_ELEMENTS(coll, "coll:");
    }

    {
        std::unordered_multiset<int> coll{1, 2, 3, 5, 7, 11, 13, 17, 19, 77};
        PRINT_ELEMENTS(coll, "coll:");

        coll.insert({-7, 7, 33, -11, 19, 1, 13, 77});
        PRINT_ELEMENTS(coll, "coll:");

        auto pos = coll.find(77);
        if (pos != coll.end())
            coll.erase(pos);
        PRINT_ELEMENTS(coll, "coll:");
    }

    {
        std::unordered_set<Customer, CustomerHash, CustomerEqual> custset;
        custset.insert(Customer("nico", "josuttis", 43));
        PRINT_ELEMENTS(custset, "custset:");
    }

    {
        auto hash = [](const Customer &c)
        {
            return hash_val(c.firstname(), c.lastname(), c.number());
        };

        auto eq = [](const Customer &c1, const Customer &c2)
        {
            return c1.number() == c2.number();
        };

        std::unordered_set<Customer, decltype(hash), decltype(eq)> custset(10, hash, eq); //@ 10:buckets 最初大小
        custset.insert(Customer("nico", "josuttis", 109));
        PRINT_ELEMENTS(custset, "custset:");
    }

    {
        std::cout << "============================= layout ======================================" << std::endl;
        std::unordered_set<int> intset{1, 2, 3, 6, 7, 8, 9, 13, 11, 17, 99};
        printf_hashtable_state(intset);

        intset.insert({-9, 1, -8, 11, 12, 65});
        std::cout << "============================= layout ======================================" << std::endl;
        printf_hashtable_state(intset);
    }

    {
        std::unordered_multimap<std::string, std::string> dict = {
            {"day", "Tag"},
            {"strange", "fremd"},
            {"car", "Auto"},
            {"trait", "elegant"},
            {"trait", "Merkmal"},
            {"strange", "seltsam"},
        };

        std::cout << "============================= layout ======================================" << std::endl;
        printf_hashtable_state(dict);
        dict.insert({
            {"smart", "raffiniert"},
            {"smart", "klug"},
            {"clever", "raffiniert"},
        });
        std::cout << "============================= layout ======================================" << std::endl;
        printf_hashtable_state(dict);

        std::cout << "============================= layout ======================================" << std::endl;
        dict.max_load_factor(0.65);
        printf_hashtable_state(dict);
    }
    return 0;
}
