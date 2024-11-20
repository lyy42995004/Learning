#include <iostream>
#include <assert.h>
using namespace std;

namespace chan
{
    template <class T>
    class vector
    {
    public:
        typedef T *inerator;
        typedef const T *const_inerator;

        vector()
        {
        }

        vector(size_t n, const T &val = T())
        {
            reserve(n);
            for (size_t i = 0; i < n; ++i)
            {
                push_back(val);
            }
        }

        vector(int n, const T &val = T())
        {
            reserve(n);
            for (size_t i = 0; i < n; ++i)
            {
                push_back(val);
            }
        }

        template <class InputIterator>
        vector(InputIterator begin, InputIterator end)
        {
            while (begin != end)
            {
                push_back(*begin);
                begin++;
            }
        }

        // vector(const vector<T> &v)
        // {
        //     _start = new T[v.capacity()];
        //     for (size_t i = 0; i < v.size(); ++i)
        //     {
        //         _start[i] = v._start[i];
        //     }
        //     _finish = _start + v.size();
        //     _end_of_storage = _start + v.capacity();
        // }

        vector(const vector<T> &v)
        {
            vector<T> tmp(v.begin(), v.end());
            swap(tmp);
        }

        ~vector()
        {
            delete[] _start;
            _start = _finish = _end_of_storage = nullptr;
        }

        T &operator[](size_t n)
        {
            assert(n < size());
            return _start[n];
        }

        const T &operator[](size_t n) const
        {
            assert(n < size());
            return _start[n];
        }

        void swap(vector<T> &v)
        {
            std::swap(_start, v._start);
            std::swap(_finish, v._finish);
            std::swap(_end_of_storage, v._end_of_storage);
        }

        vector &operator=(vector<T> v)
        {
            swap(v);
            return *this;
        }

        void push_back(const T &val)
        {
            if (_finish == _end_of_storage)
                reserve(capacity() == 0 ? 4 : 2 * capacity());
            *_finish = val;
            _finish++;
        }

        bool isempty()
        {
            return size() == 0;
        }

        void pop_back(const T &val)
        {
            assert(!isempty());
            --_finish;
        }

        void resize(size_t n, const T &val = T())
        {
            if (n < size())
            {
                _finish = _start + n;
            }
            else
            {
                if (n > capacity())
                    reserve(n);
                for (size_t i = size(); i < n; ++i)
                {
                    _start[i] = val;
                }
                _finish = _start + n;
            }
        }

        void reserve(size_t n)
        {
            if (n > capacity())
            {
                size_t sz = size();
                T *tmp = new T[n];
                if (_start)
                {
                    for (size_t i = 0; i < size(); ++i)
                    {
                        tmp[i] = _start[i];
                    }
                    delete[] _start;
                }
                _start = tmp;
                _finish = _start + sz;
                _end_of_storage = _start + n;
            }
        }

        inerator insert(inerator pos, const T &val)
        {
            assert(pos <= _finish);
            assert(pos >= _start);
            if (_finish == _end_of_storage)
            {
                size_t len = pos - _start;
                reserve(capacity() == 0 ? 4 : 2 * capacity());
                pos = _start + len;
            }
            inerator end = _finish;
            while (end >= pos)
            {
                *(end + 1) = *end;
                --end;
            }
            *pos = val;
            ++_finish;
            return pos;
        }

        inerator erase(inerator pos)
        {
            assert(pos <= _finish);
            assert(pos >= _start);
            inerator end = pos;
            while (end != _finish)
            {
                *end = *(end + 1);
                ++end;
            }
            --_finish;
            return pos;
        }

        size_t size() const
        {
            return _finish - _start;
        }

        size_t capacity() const
        {
            return _end_of_storage - _start;
        }

        inerator begin()
        {
            return _start;
        }

        inerator end()
        {
            return _finish;
        }

        const_inerator begin() const
        {
            return _start;
        }

        const_inerator end() const
        {
            return _finish;
        }

    private:
        inerator _start = nullptr;
        inerator _finish = nullptr;
        inerator _end_of_storage = nullptr;
    };
    
    void test()
    {

	}
}