#ifndef _DATE_
#define _DATE_

enum Months
{
    January = 1,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
};

class Date
{
private:
    int m_year;
    int m_month;
    int m_day;

    bool isLeap(const int);
    bool checkIfDateIsValid();

public:
    Date();
    Date(const int year, const int month, const int day);
    bool operator==(const Date &);

    int getDay() const;
    int getMonth() const;
    int getYear() const;

    void setDay(const int day);
    void setMonth(const int month);
    void setYear(const int year);
};

#endif // _DATE_