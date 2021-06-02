#include "algostuff.h"
#include <cstdlib>

bool absLess(int elem1, int elem2)
{
    return abs(elem1) < abs(elem2);
}

bool checkEven(int elem, bool even)
{
    if (even)
    {
        return elem % 2 == 0;
    }
    else
    {
        return elem % 2 == 1;
    }
}

bool doubled(int elem1, int elem2)
{
    return elem1 * 2 == elem2;
}

int main()
{
    {
        std::list<int> coll;
        INSERT_ELEMENTS(coll, 1, 9);
        INSERT_ELEMENTS(coll, 1, 9);
        PRINT_ELEMENTS(coll, "coll is: ");

        std::list<int>::iterator pos1, pos2;
        pos1 = std::find(coll.begin(), coll.end(), 4);
        if (pos1 != coll.end())
        {
            pos2 = std::find(++pos1, coll.end(), 4);
        }
        if (pos1 != coll.end() && pos2 != coll.end())
        {
            std::copy(--pos1, ++pos2, std::ostream_iterator<int>(std::cout, " "));
            std::cout << std::endl;
        }
    }

    {
        using namespace std::placeholders;

        std::vector<int> coll;
        INSERT_ELEMENTS(coll, 1, 9);
        PRINT_ELEMENTS(coll, "coll is: ");

        std::vector<int>::iterator pos;
        pos = std::find_if(coll.begin(), coll.end(), std::bind(std::greater<int>(), _1, 3));
        std::cout << *pos << " is the first element greater than 3" << std::endl;

        pos = std::find_if(coll.begin(), coll.end(), [](int elem)
                           { return elem % 3 == 0; });
        std::cout << *pos << " is the first element divide by 3" << std::endl;

        pos = std::find_if_not(coll.begin(), coll.end(), std::bind(std::less<int>(), _1, 5));
        std::cout << *pos << " is the first element no less than 5" << std::endl;
    }

    {
        std::deque<int> coll{1, 2, 7, 7, 6, 3, 9, 5, 7, 7, 7, 3, 6};
        PRINT_ELEMENTS(coll, "coll is: ");

        std::deque<int>::iterator pos;
        pos = std::search_n(coll.begin(), coll.end(), 3, 7); //@ 连续3个7
        if (pos != coll.end())
        {
            for (int i = 0; i < 3; i++)
            {
                std::cout << *pos++ << " ";
            }
            std::cout << std::endl;
        }
        else
        {
            std::cout << "not found" << std::endl;
        }

        pos = std::search_n(coll.begin(), coll.end(), 4, 1); //@ 连续4个1
        if (pos != coll.end())
        {
            for (int i = 0; i < 3; i++)
            {
                std::cout << *pos++ << " ";
            }
            std::cout << std::endl;
        }
        else
        {
            std::cout << "not found" << std::endl;
        }

        pos = std::search_n(coll.begin(), coll.end(), 3, 0, [](int n, int)
                            { return n > 5; });
        if (pos != coll.end())
        {
            for (int i = 0; i < 3; i++)
            {
                std::cout << *pos++ << " ";
            }
            std::cout << std::endl;
        }
        else
        {
            std::cout << "not found" << std::endl;
        }

        pos = std::search_n(coll.begin(), coll.end(), 4, 0, [](int elem, int)
                            { return elem % 2 == 1; });
        if (pos != coll.end())
        {
            for (int i = 0; i < 3; i++)
            {
                std::cout << *pos++ << " ";
            }
            std::cout << std::endl;
        }
        else
        {
            std::cout << "not found" << std::endl;
        }
    }

    {
        std::deque<int> coll;
        std::list<int> subcoll;

        INSERT_ELEMENTS(coll, 1, 8);
        INSERT_ELEMENTS(coll, 1, 8);
        INSERT_ELEMENTS(subcoll, 3, 6);

        PRINT_ELEMENTS(coll, "coll is: ");
        PRINT_ELEMENTS(subcoll, "subcoll is: ");

        std::deque<int>::iterator pos;
        pos = std::search(coll.begin(), coll.end(), subcoll.begin(), subcoll.end());

        while (pos != coll.end())
        {
            std::cout << "subcoll found starting from element: " << std::distance(coll.begin(), pos) + 1 << std::endl;
            ++pos;
            pos = std::search(pos, coll.end(), subcoll.begin(), subcoll.end());
        }
    }

    {
        std::vector<int> coll;
        INSERT_ELEMENTS(coll, 1, 9);
        PRINT_ELEMENTS(coll, "coll is: ");

        bool checkEvenArgs[3]{true, false, true}; //@ 偶、奇、偶的序列
        std::vector<int>::iterator pos;
        pos = std::search(coll.begin(), coll.end(), checkEvenArgs, checkEvenArgs + 3, checkEven);

        while (pos != coll.end())
        {
            std::cout << "subcoll found starting from element: " << std::distance(coll.begin(), pos) + 1 << std::endl;
            ++pos;
            pos = std::search(pos, coll.end(), checkEvenArgs, checkEvenArgs + 3, checkEven);
        }
    }

    {
        std::deque<int> coll;
        std::list<int> subcoll;

        INSERT_ELEMENTS(coll, 1, 8);
        INSERT_ELEMENTS(coll, 1, 8);
        INSERT_ELEMENTS(subcoll, 3, 6);

        PRINT_ELEMENTS(coll, "coll is: ");
        PRINT_ELEMENTS(subcoll, "subcoll is: ");

        std::deque<int>::iterator pos;
        std::deque<int>::iterator end = coll.end();
        pos = std::find_end(coll.begin(), coll.end(), subcoll.begin(), subcoll.end());
        while (pos != end)
        {
            end = pos;
            std::cout << "subcoll found starting from element: " << std::distance(coll.begin(), pos) + 1 << std::endl;
            pos = std::search(coll.begin(), end, subcoll.begin(), subcoll.end());
        }
    }

    {
        std::vector<int> coll;
        std::list<int> searchcoll;

        INSERT_ELEMENTS(coll, 1, 11);
        INSERT_ELEMENTS(searchcoll, 3, 5);

        PRINT_ELEMENTS(coll, "coll is: ");
        PRINT_ELEMENTS(searchcoll, "searchcoll is: ");

        std::vector<int>::iterator pos;
        pos = std::find_first_of(coll.begin(), coll.end(), searchcoll.begin(), searchcoll.end());
        if (pos != coll.end())
        {
            while (pos != coll.end())
                std::cout << *pos++ << " ";
            std::cout << std::endl;
        }
        else
        {
            std::cout << "not found" << std::endl;
        }
    }

    {
        std::vector<int> coll;
        coll.push_back(1);
        coll.push_back(3);
        coll.push_back(2);
        coll.push_back(4);
        coll.push_back(5);
        coll.push_back(5);
        coll.push_back(0);

        PRINT_ELEMENTS(coll, "coll is: ");
        std::vector<int>::iterator pos;

        pos = std::adjacent_find(coll.begin(), coll.end());
        if (pos != coll.end())
        {
            while (pos != coll.end())
                std::cout << *pos++ << " ";
            std::cout << std::endl;
        }
        else
        {
            std::cout << "not found" << std::endl;
        }

        pos = std::adjacent_find(coll.begin(), coll.end(), doubled);
        if (pos != coll.end())
        {
            while (pos != coll.end())
                std::cout << *pos++ << " ";
            std::cout << std::endl;
        }
        else
        {
            std::cout << "not found" << std::endl;
        }
    }
    return 0;
}