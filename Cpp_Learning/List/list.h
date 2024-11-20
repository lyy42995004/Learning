#pragma once
#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

namespace chan
{
    template <class T>
    struct list_node
    {
        list_node<T> *_next;
        list_node<T> *_prev;
        T _data;

        list_node(const T &x = T())
            : _next(nullptr), _prev(nullptr), _data(x)
        {
        }
    };

    template <class T, class ref, class ptr>
    struct __list_iterator
    {
        typedef list_node<T> node;
        typedef __list_iterator<T, ref, ptr> self;
        node *_node;

        __list_iterator(node *n)
            : _node(n)
        {
        }

        ref operator*()
        {
            return _node->_data;
        }

        ptr operator->()
        {
            return &(_node->_data);
        }

        self &operator++() // 前置
        {
            _node = _node->_next;
            return *this;
        }

        self operator++(int) // 后置
        {
            self tmp(_node);
            _node = _node->_next;
            return tmp;
        }

        self &operator--()
        {
            _node = _node->_prev;
            return *this;
        }

        self operator--(int) // 后置
        {
            self tmp(_node);
            _node = _node->_prev;
            return tmp;
        }

        bool operator==(const self &s)
        {
            return _node == s._node;
        }

        bool operator!=(const self &s)
        {
            return _node != s._node;
        }
    };

    // template <class T>
    // struct __list_const_iterator
    // {
    //     typedef list_node<T> node;
    //     typedef __list_const_iterator<T> self;
    //     node *_node;

    //     __list_const_iterator(node *n)
    //         : _node(n)
    //     {
    //     }

    //     const T operator*()
    //     {
    //         return _node->_data;
    //     }

    //     const T *operator->()
    //     {
    //         return &(_node->_data);
    //     }

    //     self &operator++() // 前置
    //     {
    //         _node = _node->_next;
    //         return *this;
    //     }

    //     self operator++(int) // 后置
    //     {
    //         self tmp(_node);
    //         _node = _node->_next;
    //         return tmp;
    //     }

    //     self &operator--()
    //     {
    //         _node = _node->_prev;
    //         return *this;
    //     }

    //     self operator--(int) // 后置
    //     {
    //         self tmp(_node);
    //         _node = _node->_prev;
    //         return tmp;
    //     }

    //     bool operator==(const self &s)
    //     {
    //         return _node == s._node;
    //     }

    //     bool operator!=(const self &s)
    //     {
    //         return _node != s._node;
    //     }
    // };

    template <class T>
    class list
    {
        typedef list_node<T> node;

    public:
        typedef __list_iterator<T, T&, T*> iterator;
        typedef __list_iterator<T, const T&, const T*> const_iterator;
        // typedef __list_const_iterator<T> const_iterator;
        list()
        {
            empty_init();
        }

        template <class Iterator>
        list(Iterator first, Iterator last)
        {
            empty_init();
            while (first != last)
            {
                push_back(*first);
                first++;
            }
        }

        // list(const list<T>& lt)
        // {
        //     empty_init();
        //     for (auto x : lt)
        //         push_back(x);
        // }

        void swap(list<T>& lt)
        {
            std::swap(_head, lt._head);
        }

        list(const list<T> &lt)
        {
            empty_init();
            list<T> tmp(lt.begin(), lt.end());
            swap(tmp);
        }

        list<T>& operator=(list<T> lt)
        {
            swap(lt);
            return *this;
        }

        ~list()
        {
            clear();
            delete _head;
            _head = nullptr;
        }

        void empty_init()
        {
            _head = new node;
            _head->_next = _head->_prev = _head;
        }

        void clear()
        {
            iterator it = begin();
            while (it != end())
                erase(it++);
        }

        void push_back(const T &x)
        {
            insert(end(), x);
            // node* new_node = new node(x);
            // node* tail = _head->_prev;
            // tail->_next = new_node;
            // new_node->_prev = tail;
            // _head->_prev = new_node;
            // new_node->_next = _head;
        }

        void push_front(const T &x)
        {
            insert(begin(), x);
        }

        void pop_back()
        {
            erase(--end());
        }

        void pop_front()
        {
            erase(begin());
        }

        void insert(iterator pos, const T &x)
        {
            node *cur = pos._node; // 取结构体的成员
            node *prev = cur->_prev;
            node *new_node = new node(x);
            prev->_next = new_node;
            new_node->_prev = prev;
            cur->_prev = new_node;
            new_node->_next = cur;
        }

        iterator erase(iterator pos)
        {
            assert(pos != end());
            node *cur = pos._node;
            node *prev = cur->_prev;
            node *next = cur->_next;
            prev->_next = next;
            next->_prev = prev;
            delete cur;
            return iterator(next);
        }

        iterator begin()
        {
            return iterator(_head->_next);
        }

        iterator end()
        {
            return iterator(_head);
        }

        const_iterator begin() const
        {
            return const_iterator(_head->_next);
        }

        const_iterator end() const
        {
            return const_iterator(_head);
        }
    private:
        node *_head;
    };

    template <typename T>
    void print_list(const list<T>& lt)
    {
        typename list<T>::const_iterator it = lt.begin();
        while (it != lt.end())
        {
            cout << *it << " ";
            it++;
        }
		cout << endl;
    }

    template <typename Container>
    void print_container(const Container& lt)
    {
        typename Container::const_iterator it = lt.begin();
        while (it != lt.end())
        {
            cout << *it << " ";
            it++;
        }
		cout << endl;
    }

    void test_list()
	{
		list<string> lt;
		lt.push_back("123");
		lt.push_back("123");
		lt.push_back("123");
		lt.push_back("123");
		lt.push_back("123");
        list<string> lt2(lt);
        print_list(lt2);
        print_container(lt);

        vector<string> vs;
        vs.push_back("456");
        vs.push_back("456");
        vs.push_back("456");
        print_container(vs);
	}
};