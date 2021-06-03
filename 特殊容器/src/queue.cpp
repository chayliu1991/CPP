#include <queue>
#include <list>
#include <iostream>
#include <string>
#include "Queue.h"

int main()
{
    {
        std::queue<std::string, std::list<std::string>> q;
        q.push("These ");
        q.push("are ");
        q.push("more than ");
        std::cout << q.front() << std::endl;
        q.pop();
        std::cout << q.front() << std::endl;
        q.push("four ");
        q.push("words!");
        q.pop();
        std::cout << q.front() << std::endl;
        std::cout << q.back() << std::endl;
    }

    {
        try
        {
            Queue<std::string> q;
            q.Push("These ");
            q.Push("are ");
            q.Push("more than ");
            std::cout << q.Front() << std::endl;
            q.Pop();
            std::cout << q.Front() << std::endl;
            q.Push("four ");
            q.Push("words!");
            q.Pop();
            std::cout << q.Front() << std::endl;
            std::cout << q.Back() << std::endl;
            std::cout << q.Size() << std::endl;
            while (!q.empty())
            {
                std::cout << q.Pop() << std::endl;
            }
            q.Front();
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    return 0;
}
