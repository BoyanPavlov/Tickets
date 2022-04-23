#include "date.hpp"
#include "utilities.hpp"
#ifndef _TICKET_
#define _TICKET_

class Ticket
{
private:
    char *m_name = nullptr;
    // TODO
    Date *m_date = nullptr;
    int m_row = -1;
    int m_seat = -1;
    bool m_isReserved = false;
    char *m_passoword = nullptr;

public:
    Ticket() = delete;
    Ticket(char *name, Date *date, int row, int seat);
    // TODO
    //  find a way to get passwords and find if a seat is reserved
    Ticket(const Ticket &rhs);
    Ticket &operator=(const Ticket &rhs);

    ~Ticket();

    void setName(const char *name);
    void setDate(const Date *date);
    void setRow(const int row);
    void setSeat(const int seat);
    void setReservationOnSeat(const bool reserved);
    void setPassword(const char *pass);

    char *getName() const;
    Date *getDate() const;
    int getRow() const;
    int getSeat() const;
    bool getReservationOnSeat() const;
    char *getPassword() const;
};

Ticket::Ticket(char *name, Date *date, int row, int seat)
{
    strDub(m_name, name);
    m_row = row;
    m_seat = seat;
    // TODO
}

Ticket &Ticket::operator=(const Ticket &rhs)
{
    strDub(m_name, rhs.m_name);
    strDub(m_passoword, rhs.m_passoword);

    m_row = rhs.m_row;
    m_seat = rhs.m_seat;
    m_isReserved = rhs.m_isReserved;
    *m_date = *rhs.m_date; // I think this isn't the way
    return *this;
}

Ticket::Ticket(const Ticket &rhs)
{
    strDub(m_name, rhs.m_name);
    strDub(m_passoword, rhs.m_passoword);

    m_row = rhs.m_row;
    m_seat = rhs.m_seat;
    m_isReserved = rhs.m_isReserved;
    *m_date = *rhs.m_date; // I think this isn't the way
}

Ticket::~Ticket()
{
    clearString(m_name);
    clearString(m_passoword);
}

void Ticket::setName(const char *name)
{
    strDub(m_name, name);
}
void Ticket::setDate(const Date *date)
{
    *m_date = *date;
}
void Ticket::setRow(const int row)
{
    m_row = row;
}

void Ticket::setSeat(const int seat)
{
    m_seat = seat;
}

void Ticket::setReservationOnSeat(const bool reserved)
{
    m_isReserved = reserved;
}

void Ticket::setPassword(const char *pass)
{
    strDub(m_passoword, pass);
}

char *Ticket::getName() const
{
    return m_name;
}
Date *Ticket::getDate() const
{
    return m_date;
}
int Ticket::getRow() const
{
    return m_row;
}
int Ticket::getSeat() const
{
    return m_seat;
}
bool Ticket::getReservationOnSeat() const
{
    return m_isReserved;
}
char *Ticket::getPassword() const
{
    return m_passoword;
}
#endif // _TICKET_