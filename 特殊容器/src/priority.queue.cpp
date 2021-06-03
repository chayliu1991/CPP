#include <queue>
#include <algorithm>
#include <iostream>
#include <vector>
#include <functional>

int main()
{
    {
        std::priority_queue<float, std::deque<float>> q;
        q.push(66.6);
        q.push(11.1);
        q.push(22.2);
        std::cout << q.top() << std::endl;
        q.push(33.3);
        q.push(55.5);
        while (!q.empty())
        {
            std::cout << q.top() << std::endl;
            q.pop();
        }
    }

    {
        std::cout << "=========================================================" << std::endl;
        std::priority_queue<float, std::vector<float>, std::greater<float>> q;
        q.push(66.6);
        q.push(11.1);
        q.push(22.2);
        std::cout << q.top() << std::endl;
        q.push(33.3);
        q.push(55.5);
        while (!q.empty())
        {
            std::cout << q.top() << std::endl;
            q.pop();
        }
    }
    return 0;
}
