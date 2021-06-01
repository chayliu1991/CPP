#include <iterator>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <iostream>

template <typename ForwardIterator>
void shift_left(ForwardIterator beg, ForwardIterator end)
{
    typedef typename std::iterator_traits<ForwardIterator>::value_type value_type;
    while (beg != end)
    {
        value_type tmp(*beg);
        std::cout << tmp << ", ";
        ++beg;
    }
    std::cout << std::endl;
}

template <typename Iterator>
typename std::iterator_traits<Iterator>::difference_type Distance(Iterator pos1, Iterator pos2)
{
    return Distance(pos1, pos2, std::iterator_traits<Iterator>::iterator_category());
}

template <typename RaIterator>
typename std::iterator_traits<RaIterator>::difference_type Distance(RaIterator pos1, RaIterator pos2, std::random_access_iterator_tag)
{
    return pos2 - pos1;
}

template <typename InIterator>
typename std::iterator_traits<InIterator>::difference_type Distance(InIterator pos1, InIterator pos2, std::input_iterator_tag)
{
    typename std::iterator_traits<InIterator>::difference_type dis;
    for (dis = 0; pos1 != pos2; ++pos1, ++dis)
        ;
    return dis;
}

int main()
{
    {
        std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};
        shift_left(vec.cbegin(), vec.cend());
    }

    {
        std::vector<int> vec{1, 2, 3, 4, 5, 6};
        std::list<int> lst{1, 2, 3};
        std::forward_list<int> flst{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

        std::cout << Distance(vec.begin(), vec.end()) << std::endl;
        std::cout << Distance(lst.begin(), lst.end()) << std::endl;
        std::cout << Distance(flst.begin(), flst.end()) << std::endl;
    }
    return 0;
}