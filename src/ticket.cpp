#include <iostream>
#include "ticket.h"

Ticket::Ticket(char *name, const Date &date, int row, const Seat &seat)
    : m_date(date), m_seat(seat), m_row(row)
{
    strDub(m_nameOfEvent, name);
}

Ticket::Ticket(char *name, const Date &date, int row, const Seat &seat, char *password)
    : m_date(date), m_seat(seat), m_row(row)
{
    strDub(m_nameOfEvent, name);
    strDub(m_password, password);
}

Ticket &Ticket::operator=(const Ticket &rhs)
{
    if (this != &rhs)
    {
        strDub(m_nameOfEvent, rhs.m_nameOfEvent);
        strDub(m_password, rhs.m_password);
        m_row = rhs.m_row;
        m_seat = rhs.m_seat;
        m_date = rhs.m_date;
    }
    return *this;
}

Ticket::Ticket(const Ticket &rhs)
    : m_nameOfEvent(nullptr), m_password(nullptr),
      m_date(rhs.m_date), m_seat(rhs.m_seat), m_row(rhs.m_row)
{
    strDub(m_nameOfEvent, rhs.m_nameOfEvent);
    strDub(m_password, rhs.m_password);
}

Ticket::~Ticket()
{
    clearString(m_nameOfEvent);
    clearString(m_password);
}

void Ticket::setName(const char *name)
{
    strDub(m_nameOfEvent, name);
}

void Ticket::setDate(const Date &date)
{
    m_date = date;
}

void Ticket::setRow(const int row)
{
    m_row = row;
}

void Ticket::setSeat(const Seat &seat)
{
    m_seat = seat;
}

void Ticket::setPassword(const char *pass)
{
    strDub(m_password, pass);
}

char *Ticket::getName() const
{
    return m_nameOfEvent;
}

const Date &Ticket::getDate() const
{
    return m_date;
}
int Ticket::getRow() const
{
    return m_row;
}
Seat &Ticket::getSeat() 
{
    return m_seat;
}
char *Ticket::getPassword() const
{
    return m_password;
}

void Ticket::reserveATicket(char *password)
{
    if (!m_seat.isSeatReserved())
    {
        m_seat.reserveSeat();
        strDub(m_password, password);
    }
    else
    {
        std::cout << "seat already reserved\n";
    }
}

void Ticket::FreeATicket()
{
    if (!m_password)
    {
        delete[] m_password;
        m_password = nullptr;
    }
    m_seat.freeASeat();
}

void Ticket::TakeATicket()
{
    if (!m_seat.isSeatReserved() && m_seat.isSeatFree())
    {
        m_seat.takeASeat();
    }
    else
    {
        std::cout << "Seat taken already or reserved\n";
    }
}


Ticket::Ticket()
    : m_nameOfEvent(nullptr), m_roomNumber(-1), m_row(-1),
      m_password(nullptr)
{
}

void Ticket::setRoom(int room)
{
    m_roomNumber = room;
}
