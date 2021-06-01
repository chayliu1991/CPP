#include <vector>
#include <iostream>
#include <iterator>
#include <string>
#include <algorithm>

int main()
{
    {
        std::ostream_iterator<int> intWriter(std::cout, "\n");
        *intWriter = 54;
        intWriter++;
        *intWriter = 77;
        intWriter++;
        *intWriter = 98;
        intWriter++;

        std::vector<int> coll{1, 2, 3, 4, 5, 6, 7, 8, 9};
        std::copy(coll.cbegin(), coll.cend(), std::ostream_iterator<int>(std::cout, ","));
        std::cout << std::endl;
    }

    {
        std::istream_iterator<int> intReader(std::cin);
        std::istream_iterator<int> intReaderEof;
        while (intReader != intReaderEof)
        {
            std::cout << "once:  " << *intReader << std::endl;
            std::cout << "once again:  " << *intReader << std::endl;
            ++intReader;
        }
    }

    {
        std::istream_iterator<std::string> cinPos(std::cin);
        std::ostream_iterator<std::string> coutPos(std::cout, " ");

        while (cinPos != std::istream_iterator<std::string>())
        {
            //@ 跳过某些输入单元
            std::advance(cinPos, 2);

            //@ 必须检查迭代器是否有效
            if (cinPos != std::istream_iterator<std::string>())
            {
                *coutPos++ = *cinPos++;
            }
        }

        std::cout << std::endl;
    }

    return 0;
}