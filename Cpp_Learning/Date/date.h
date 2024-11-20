#include <iostream>
using namespace std;

class Date
{
    friend ostream &operator<<(ostream &in, const Date &d);
    friend istream &operator>>(istream &out, Date &d);

public:
    Date(int year = 2000, int month = 1, int day = 1)
    {
        _year = year;
        _month = month;
        _day = day;
    }

    Date(const Date &d)
    {
        _year = d._year;
        _month = d._month;
        _day = d._day;
    }

    int GetMonthDay(int year, int month) const
    {
        int montharr[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (month == 2 && ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)))
        {
            montharr[2] = 29;
        }
        return montharr[month];
    }

    Date &operator+=(int day)
    {
        if (day < 0)
        {
            *this -= -day;
            return *this;
        }
        _day += day;
        while (_day > GetMonthDay(_year, _month))
        {
            _day -= GetMonthDay(_year, _month);
            ++_month;
            if (_month == 13)
            {
                ++_year;
                _month = 1;
            }
        }
        return *this;
    }

    Date operator+(int day) const
    {
        Date tmp = *this;
        tmp += day;
        return tmp;
    }

    Date operator++()
    {
        *this += 1;
        return *this;
    }

    Date operator++(int) const
    {
        Date tmp = *this;
        tmp += 1;
        return tmp;
    }

    Date &operator-=(int day)
    {
        if (day < 0)
        {
            *this += -day;
            return *this;
        }
        _day -= day;
        while (_day <= 0)
        {
            --_month;
            if (_month == 0)
            {
                --_year;
                _month = 12;
            }
            _day += GetMonthDay(_year, _month);
        }
        return *this;
    }

    Date operator-(int day) const
    {
        Date tmp = *this;
        tmp -= day;
        return tmp;
    }

    int operator-(const Date &d) const
    {
        Date max = *this;
        Date min = d;
        int flag = 1;
        if (*this < d)
        {
            max = d;
            min = *this;
            flag = -1;
        }
        int n = 0;
        while (max != min)
        {
            ++min;
            ++n;
        }
        return n * flag;
    }

    Date operator--()
    {
        *this -= 1;
        return *this;
    }

    Date operator--(int) const
    {
        Date tmp = *this;
        tmp -= 1;
        return tmp;
    }

    bool operator==(const Date &d) const
    {
        return (_year == d._year && _month == d._month && _day == d._day);
    }

    bool operator!=(const Date &d) const
    {
        return !(*this == d);
    }

    bool operator<(const Date &d) const
    {
        return ((_year < d._year) ||
                (_year == d._year && _month < d._month) ||
                (_year == d._year && _month == d._month && _day < d._day));
    }

    bool operator<=(const Date &d) const
    {
        return (*this == d || *this < d);
    }

    bool operator>(const Date &d) const
    {
        return !(*this <= d);
    }

    bool operator>=(const Date &d) const
    {
        return !(*this < d);
    }

private:
    int _year;
    int _month;
    int _day;
};

inline ostream &operator<<(ostream &out, const Date &d)
{
    cout << d._year << " " << d._month << " " << d._day << endl;
    return out;
}

inline istream &operator>>(istream &in, Date &d)
{
    in >> d._year >> d._month >> d._day;
    return in;
}