#include <iostream>
#include "date.h"

bool Date::isLeap(const int year)
{
    return (((year % 4 == 0) &&
             (year % 100 != 0)) ||
            (year % 400 == 0));
}

bool Date::checkIfDateIsValid()
{
    if (12 < m_month || m_month < 1)
    {
        return false;
    }

    if (m_month == February)
    {
        if (isLeap(m_year))
        {
            if (29 < m_day || m_day < 1)
            {
                return false;
            }
        }
        else
        {
            if (28 < m_day || m_day < 1)
            {
                return false;
            }
        }
    }

    if (m_month == January || m_month == March ||
        m_month == May || m_month == March ||
        m_month == July || m_month == August || m_month == October || m_month == December)
    {
        if (31 < m_day || m_day < 1)
        {
            return false;
        }
    }
    else
    {
        if (30 < m_day || m_day < 1)
        {
            return false;
        }
    }
    return true;
}

Date::Date(const int year, const int month, const int day)
// : m_day(day), m_month(month), m_year(year)
{
    if (!checkIfDateIsValid())
    {
        std::cout << "Invalid date\n";
    }
    else
    {
        m_day = day;
        m_month = month;
        m_year = year;
    }
}

int Date::getDay() const
{
    return m_day;
}
int Date::getMonth() const
{
    return m_month;
}
int Date::getYear() const
{
    return m_year;
}

void Date::setDay(int day)
{
    m_day = day;
}
void Date::setMonth(int month)
{
    m_month = month;
}
void Date::setYear(int year)
{
    m_year = year;
}

bool Date::operator==(const Date &rhs)
{
    if (m_year == rhs.m_year && m_month == rhs.m_month && m_day == rhs.m_day)
    {
        return true;
    }
    return false;
}

Date::Date()
    : m_year(-1),
      m_month(-1),
      m_day(-1)
{
}
