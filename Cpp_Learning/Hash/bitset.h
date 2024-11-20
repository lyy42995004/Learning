#pragma once

namespace tian
{
    template <size_t N> 
    class bitset
    {
    public:
        bitset()
        {
            _bits.resize((N >> 5) + 1, 0);
        }

        void set(size_t x)
        {
            size_t i = x / 32;
            size_t j = x % 32;
            _bits[i] |= (1 << j);
        }

        void reset(size_t x)
        {
            size_t i = x / 32;
            size_t j = x % 32;
            _bits[i] &= ~(1 << j);
        }

        bool test(size_t x)
        {
            size_t i = x / 32;
            size_t j = x % 32;
            return _bits[i] & (1 << j);
        }

    private:
        vector<int> _bits;
    };

    void test()
    {
        bitset<100> bs;
        bs.set(40);
        bs.set(39);

        cout << bs.test(38) << endl;
        cout << bs.test(39) << endl;
        cout << bs.test(40) << endl;
        cout << bs.test(41) << endl;
        cout << bs.test(42) << endl << endl;

        bs.reset(40);

        cout << bs.test(38) << endl;
        cout << bs.test(39) << endl;
        cout << bs.test(40) << endl;
        cout << bs.test(41) << endl;
        cout << bs.test(42) << endl << endl;
    }
}