#include <iostream>
#include <vector>
using namespace std;

namespace chan
{
    template <class T, class Container = vector<T>, class Compare = less<T>>
    class priority_queue
    {
    public:
        priority_queue()
        {
        }

        void adjust_up(int child)
        {
            int parent = (child - 1) / 2;
            while (child > 0)   
            {
                if (_cmp(_con[parent], _con[child]))
                {
                    swap(_con[child], _con[parent]);
                    child = parent;
                    parent = (child - 1) / 2;
                }
                else
                    break;
            }
        }

        void adjust_down(int parent)
        {
            int child = 2 * parent + 1;
            while (child < _con.size())
            {
                if (child + 1 < _con.size() && _cmp(_con[child], _con[child + 1]))
                    child++;
                if (_cmp(_con[parent], _con[child]))
                {
                    swap(_con[child], _con[parent]);
                    parent = child;
                    child = 2 * parent + 1;
                }
                else
                    break;
            }
        }

        template <class InputIterator>
        priority_queue(InputIterator first, InputIterator last)
            : _con(first, last)
        {
            for (int i = (_con.size() - 2) / 2; i >= 0; --i)
                adjust_down(i);
        }

        void push(const T &x)
        {
            _con.push_back(x);
            adjust_up(_con.size() - 1);
        }

        const T &top() const
        {
            return _con[0];
        }

        void pop()
        {
            swap(_con[0], _con[_con.size() - 1]);
            _con.pop_back();
            adjust_down(0);
        }

        bool empty() const
        {
            return _con.size() == 0;
        }

        size_t size() const
        {
            return _con.size();
        }

    private:
        Container _con;
        Compare _cmp;
    };
}