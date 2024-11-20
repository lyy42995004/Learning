#pragma once
#include <cstring>
#include <cassert>
#include <iostream>
using namespace std;

namespace Chandler
{
    class string
    {
    public:
        typedef char *iterator;
        typedef const char *const_iterator;

        iterator begin()
        {
            return _str;
        }

        iterator end()
        {
            return _str + _size;
        }

        const_iterator begin() const
        {
            return _str;
        }

        const_iterator end() const
        {
            return _str + _size;
        }

        string(const char *str = "")
            : _size(strlen(str))
        {
            _capacity = (_size == 0 ? 4 : _size);
            _str = new char[_capacity + 1];
            strcpy(_str, str);
        }

        string(const string &s)
            : _size(s._size), _capacity(s._capacity)
        {
            _str = new char[_capacity + 1];
            strcmp(_str, s._str);
        }

        ~string()
        {
            delete[] _str;
            _str = nullptr;
            _size = _capacity = 0;
        }

        const char &operator[](size_t pos) const
        {
            assert(pos < _size);
            return _str[pos];
        }

        char &operator[](size_t pos)
        {
            assert(pos < _size);
            return _str[pos];
        }

        const char *c_str() const
        {
            return _str;
        }

        size_t size() const
        {
            return _size;
        }

        size_t capacity() const
        {
            return _capacity;
        }

        string operator=(const string &s)
        {
            if (this != &s)
            {
                delete[] _str;
                _size = s._size;
                _capacity = s._capacity;
                _str = new char[_capacity + 1];
                strcpy(_str, s._str);
            }
            return *this;
        }

        bool operator==(const string &s) const
        {
            return (strcmp(_str, s._str) == 0);
        }

        bool operator!=(const string &s) const
        {
            return !(*this == s);
        }

        bool operator>(const string &s) const
        {
            return (strcmp(_str, s._str) > 0);
        }

        bool operator>=(const string &s) const
        {
            return (*this == s) || (*this > s);
        }

        bool operator<(const string &s) const
        {
            return !(*this >= s);
        }

        bool operator<=(const string &s) const
        {
            return !(*this > s);
        }

        void reserve(size_t n)
        {
            if (n > _capacity)
            {
                char *tmp = new char[n + 1];
                strcpy(tmp, _str);
                delete[] _str;
                _str = tmp;
                _capacity = n;
            }
        }

        void resize(size_t n, char ch = '\0')
        {
            if (n <= _size)
            {
                _size = n;
                _str[_size] = '\0';
            }
            else
            {
                if (n > _capacity)
                {
                    reserve(n);
                }
                size_t i = _size;
                while (i < n)
                {
                    _str[i] = ch;
                    i++;
                }
                _size = n;
                _str[_size] = '\0';
            }
        }

        void push_back(char ch)
        {
            insert(_size, ch);
        }

        void append(const char *str)
        {
            insert(_size, str);
        }

        string &operator+=(char ch)
        {
            push_back(ch);
            return *this;
        }

        string &operator+=(const char *str)
        {
            append(str);
            return *this;
        }

        string &insert(size_t pos, char ch)
        {
            assert(pos <= _size);
            if (_size + 1 > _capacity)
            {
                reserve(2 * _capacity);
            }
            // 移动数据
            ++_size;
            int i = _size;
            while (i > pos)
            {
                _str[i] = _str[i - 1];
                --i;
            }
            // 插入数据
            _str[pos] = ch;
            return *this;
        }

        string &insert(size_t pos, const char *str)
        {
            assert(pos <= _size);
            int len = strlen(str);
            if (_size + len > _capacity)
            {
                reserve(_capacity + len);
            }
            _size += len;
            // 移动数据
            int i = _size;
            while (i > pos + len - 1)
            {
                _str[i] = _str[i - len];
                --i;
            }
            // 插入数据
            strncpy(_str + pos, str, len);
            return *this;
        }

        string &erase(size_t pos, size_t len = npos)
        {
            if (len == npos || pos + len >= _size)
            {
                _str[pos] = '\0';
                _size = pos;
            }
            else
            {
                strcpy(_str + pos, _str + pos + len);
                _size -= len;
            }
            return *this;
        }

        size_t find(char ch, size_t pos = 0)
        {
            assert(pos < _size);
            for (size_t i = pos; i < _size; ++i)
            {
                if (_str[pos] == ch)
                    return i;
            }
            return npos;
        }

        size_t find(const char *str, size_t pos = 0)
        {
            assert(pos < _size);
            char *p = strstr(_str + pos, str);
            if (p != nullptr)
            {
                return (p - _str);
            }
            return npos;
        }

        void swap(string &s)
        {
            std::swap(_str, s._str);
            std::swap(_size, s._size);
            std::swap(_capacity, s._capacity);
        }

        void clear()
        {
            _str[0] = '\0';
            _size = 0;
        }

    private:
        char *_str;
        size_t _size;
        size_t _capacity;
        static const size_t npos;
    };

    const size_t string::npos = -1;

    ostream &operator<<(ostream &out, const string &s)
    {
        for (auto ch : s)
        {
            out << ch;
        }
        return out;
    }

    istream &operator>>(istream &in, string &s)
    {
        s.clear();
        char buf[128];
        int i = 0;
        char ch = in.get();
        while (ch != ' ' && ch != '\n')
        {
            buf[i++] = ch;
            if (i == 127)
            {
                buf[127] = '\0';
                i = 0;
                s += buf;
            }
            ch = in.get();
        }
        if (i != 0)
        {
            buf[i] = '\0';
            s += buf;
        }
        return in;
    }

    void test()
    {
        string s1;
        s1 += 'x';
        s1 += 'x';
        s1 += 'x';
        cout << s1 << endl;
    }
}