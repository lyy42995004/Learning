#pragma once
#include <iostream>
#include<deque>
using namespace std;

namespace chan
{
    template<class T, class Container = deque<T>>
    class stack
    {
    public:
        stack()
        {}

        void push(const T& x)
        {
            _container.push_back(x);
        }

        void pop()
        {
            _container.pop_back();
        }

        T& top()
        {
            return _container.back();
        }

        const T& top()const
        {
            return _container.back();
        }

        size_t size()const
        {
            return _container.size();
        };

        bool empty()const
        {
            return _container.empty();
        }
    private:
        Container _container;
    };
}