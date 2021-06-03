#pragma once
#include <deque>
#include <exception>

template <typename T>
class Queue
{
private:
    std::deque<T> data;

public:
    class ReadEmptyQueue : public std::exception
    {
    public:
        virtual const char *what() const throw()
        {
            return "read empty queue";
        }
    };

    typename std::deque<T>::size_type Size() const
    {
        return data.size();
    }

    bool empty() const
    {
        return data.empty();
    }

    void Push(const T &elem)
    {
        data.push_back(elem);
    }

    T &Front()
    {
        if (data.empty())
            throw ReadEmptyQueue();
        return data.front();
    }

    T &Back()
    {
        if (data.empty())
            throw ReadEmptyQueue();
        return data.back();
    }

    T Pop()
    {
        if (data.empty())
            throw ReadEmptyQueue();
        T elem(data.front());
        data.pop_front();
        return elem;
    }
};