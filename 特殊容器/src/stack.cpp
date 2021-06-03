#include <stack>
#include <iostream>
#include "Stack.h"

int main()
{
    {
        std::stack<int, std::deque<int>> st;
        st.push(1);
        st.push(2);
        st.push(3);
        while (!st.empty())
        {
            std::cout << st.top() << std::endl;
            st.pop();
        }
    }

    {
        std::stack<std::pair<std::string, std::string>> st;
        auto p = std::make_pair("hello", "world");
        st.push(std::move(p));
        st.emplace("hi", "judy");
    }

    {
        try
        {
            Stack<int> st;
            st.Push(1);
            st.Push(2);
            st.Push(3);

            std::cout << st.Size() << std::endl;
            st.Top() = 77;
            while (!st.empty())
            {
                std::cout << st.Top() << std::endl;
                st.Pop();
            }
            st.Top();
        }
        catch (const std::exception &e)
        {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
    }
    return 0;
}