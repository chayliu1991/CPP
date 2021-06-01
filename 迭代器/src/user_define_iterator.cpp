#include <iterator>
#include <string>
#include <vector>
#include <list>
#include <unordered_set>
#include <iostream>

template <typename C>
void PRINT_ELEMENTS(const C &c, const std::string &prefix)
{
    std::cout << prefix;
    for (auto const &elem : c)
        std::cout << elem << " ";
    std::cout << std::endl;
}

template <typename Container>
class asso_insert_iterator : public std::iterator<std::output_iterator_tag, typename Container::value_type>
{
protected:
    Container &container;

public:
    explicit asso_insert_iterator(Container &c) : container(c)
    {
    }

    asso_insert_iterator<Container> &operator=(const typename Container::value_type &value)
    {
        container.insert(value);
        return *this;
    }

    asso_insert_iterator<Container> &operator*()
    {
        return *this;
    }

    asso_insert_iterator<Container> &operator++()
    {
        return *this;
    }

    asso_insert_iterator<Container> &operator++(int)
    {
        return *this;
    }
};

template <typename Container>
inline asso_insert_iterator<Container> asso_inserter(Container &c)
{
    return asso_insert_iterator<Container>(c);
}

int main()
{
    {
        std::unordered_set<int> coll;

        asso_insert_iterator<decltype(coll)> iter(coll);
        *iter = 1;
        iter++;
        *iter = 2;
        iter++;
        *iter = 3;
        iter++;

        PRINT_ELEMENTS(coll, "coll is: ");

        asso_inserter(coll) = 44;
        asso_inserter(coll) = 55;
        PRINT_ELEMENTS(coll, "coll is: ");
    }

    {
        std::vector<int> vec{1, 2, 3, 4, 5, -98, -2, 100};
        std::unordered_set<int> coll;
        std::copy(vec.begin(), vec.end(), asso_inserter(coll));
        PRINT_ELEMENTS(vec, "vec is: ");
    }
    return 0;
}