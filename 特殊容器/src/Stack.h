#pragma once
#include <deque>
#include <exception>

template <typename T>
class Stack
{
private:
    std::deque<T> data;

public:
    class ReadEmptyStack : public std::exception
    {
    public:
        virtual const char *what() const throw()
        {
            return "rad empty stack";
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

    T &Top()
    {
        if (data.empty())
            throw ReadEmptyStack();
        return data.back();
    }

    T Pop()
    {
        if (data.empty())
            throw ReadEmptyStack();
        T elem(data.back());
        data.pop_back();
        return elem;
    }
};