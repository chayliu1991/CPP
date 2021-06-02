#include "algostuff.h"

bool bothEvenorOdd(int elem1, int elem2)
{
    return elem1 % 2 == elem2 % 2;
}

void printCollection(const std::list<int> &lst)
{
    PRINT_ELEMENTS(lst);
}

bool lessForCollection(const std::list<int> &l1, const std::list<int> &l2)
{
    return std::lexicographical_compare(l1.cbegin(), l1.cend(), l2.cbegin(), l2.cend());
}

int main()
{
    {
        std::vector<int> coll1;
        std::list<int> coll2;

        INSERT_ELEMENTS(coll1, 1, 8);
        INSERT_ELEMENTS(coll2, 3, 10);

        PRINT_ELEMENTS(coll1, "coll1: ");
        PRINT_ELEMENTS(coll2, "coll2: ");

        if (std::equal(coll1.begin(), coll1.end(), coll2.begin()))
        {
            std::cout << "coll1 == coll2" << std::endl;
        }
        else
        {
            std::cout << "coll1 != coll2" << std::endl;
        }

        if (std::equal(coll1.begin(), coll1.end(), coll2.begin(), bothEvenorOdd))
        {
            std::cout << "even and odd elements correspond" << std::endl;
        }
        else
        {
            std::cout << "even and odd elements do not correspond" << std::endl;
        }
    }

    {
        std::vector<int> coll1{1, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        std::list<int> coll2{1, 9, 8, 7, 6, 5, 4, 3, 2, 1};
        std::deque<int> coll3{11, 12, 13, 19, 18, 17, 16, 15, 14, 11};

        PRINT_ELEMENTS(coll1, "coll1: ");
        PRINT_ELEMENTS(coll2, "coll2: ");
        PRINT_ELEMENTS(coll3, "coll3: ");

        //@ 顺序无所谓时，两个区间的元素是否相等
        if (std::is_permutation(coll1.cbegin(), coll1.cend(), coll2.cbegin()))
        {
            std::cout << "coll1 and coll2 hava equal elements" << std::endl;
        }
        else
        {
            std::cout << "coll1 and coll2 do not hava equal elements" << std::endl;
        }

        if (std::is_permutation(coll1.cbegin(), coll1.cend(), coll3.cbegin(), bothEvenorOdd))
        {
            std::cout << "number of even and odd elements match" << std::endl;
        }
        else
        {
            std::cout << "number of even and odd elements do not match" << std::endl;
        }
    }

    {
        std::vector<int> coll1{1, 2, 3, 4, 5, 6};
        std::list<int> coll2{1, 2, 3, 4, 8, 16, 3};

        PRINT_ELEMENTS(coll1, "coll1: ");
        PRINT_ELEMENTS(coll2, "coll2: ");

        auto values = std::mismatch(coll1.begin(), coll1.end(), coll2.begin());
        if (values.first == coll1.end())
        {
            std::cout << "no mismatch value" << std::endl;
        }
        else
        {
            std::cout << "first mismatch value: " << *values.first << " " << *values.second << std::endl;
        }

        values = std::mismatch(coll1.begin(), coll1.end(), coll2.begin(), std::less_equal<int>());
        if (values.first == coll1.end())
        {
            std::cout << "always less-or-equal" << std::endl;
        }
        else
        {
            std::cout << "not always less-or-equal: " << *values.first << " " << *values.second << std::endl;
        }
    }

    {
        std::list<int> c1, c2, c3, c4;
        INSERT_ELEMENTS(c1, 1, 6);
        c4 = c3 = c2 = c1;
        c1.push_back(7);
        c3.push_back(2);
        c3.push_back(0);
        c4.push_back(2);

        std::vector<std::list<int>> cc;
        cc.insert(cc.begin(), {c1, c2, c3, c4, c3, c1, c4, c2});
        std::for_each(cc.cbegin(), cc.cend(), printCollection);
        std::cout << std::endl;

        std::sort(cc.begin(), cc.end(), lessForCollection);
        std::for_each(cc.cbegin(), cc.cend(), printCollection);
    }
    return 0;
}