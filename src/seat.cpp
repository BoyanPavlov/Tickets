#include "seat.h"
#include <iostream>

void Seat::setColOfASeat(int col)
{
    m_col = col;
}
void Seat::setRowOfASeat(int row)
{
    m_row = row;
}

void Seat::reserveSeat()
{
    m_isFree = false;
    m_isReserved = true;
}
void Seat::takeASeat()
{
    m_isFree = false;
    m_isReserved = true;
}
void Seat::freeASeat()
{
    m_isFree = true;
    m_isReserved = false;
}

bool Seat::operator==(const Seat &rhs)
{
    if (this->m_row == rhs.m_row &&
        m_col == rhs.m_row)
    {
        return true;
    }
    return false;
}

int Seat::getColOfSeat() const
{
    return m_col;
}

int Seat::getRowOfSeat() const
{
    return m_row;
}

bool Seat::isSeatFree() const
{
    return m_isFree;
}
bool Seat::isSeatReserved() const
{
    return m_isReserved;
}

Seat::Seat()
    : m_row(-1), m_col(-1), m_isFree(true), m_isReserved(false)
{
}

Seat::Seat(int row, int col, bool isFree, bool isReserved)
    : m_row(row), m_col(col), m_isFree(isFree), m_isReserved(isReserved)
{
}

std::ostream &operator<<(std::ostream &out, const Seat &obj)
{
    out << obj.getRowOfSeat() << ' ' << obj.getColOfSeat() << "  isSeatFree:" << obj.isSeatFree()
        << " isSeatReserved" << obj.isSeatReserved() << "\n";
    return out;
}
